// Copyright Ectimel


#include "Actor/HeleneEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"


AHeleneEffectActor::AHeleneEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}


void AHeleneEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AHeleneEffectActor::ApplyEffectToTarget(AActor* TargetActor,
                                             TArray<TSubclassOf<UGameplayEffect>> GameplayEffectClassArray)
{
	UAbilitySystemComponent* TargetAbilitySystemComponent =
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	if (TargetAbilitySystemComponent == nullptr)
	{
		return;
	}

	FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);

	for (auto& GameplayEffectClass : GameplayEffectClassArray)
	{
		check(GameplayEffectClass);
		FGameplayEffectSpecHandle EffectSpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(
			GameplayEffectClass, ActorLevel, EffectContextHandle);
		
		const FActiveGameplayEffectHandle ActiveGameplayEffectHandle = TargetAbilitySystemComponent->
		ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
		
		if (const bool bIsInfinite = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy ==
		EGameplayEffectDurationType::Infinite && InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOvelap)
		{
			ActiveEffectHandles.Add(ActiveGameplayEffectHandle, TargetAbilitySystemComponent);
		}
	}


	

	
}

void AHeleneEffectActor::RemoveActiveEffects(AActor* TargetActor)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (!IsValid(TargetASC)) return;

	TArray<FActiveGameplayEffectHandle> HandlesToRemove;
	for (auto HandlePair : ActiveEffectHandles)
	{
		if (HandlePair.Value == TargetASC)
		{
			TargetASC->RemoveActiveGameplayEffect(HandlePair.Key, 1);
			HandlesToRemove.Add(HandlePair.Key);
		}
	}
	for (FActiveGameplayEffectHandle& HandleEffect : HandlesToRemove)
	{
		ActiveEffectHandles.FindAndRemoveChecked(HandleEffect);
	}
}

void AHeleneEffectActor::OnOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClassArray);
	}

	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClassArray);
	}

	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClassArray);
	}
}

void AHeleneEffectActor::OnEndOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClassArray);
	}

	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClassArray);
	}
	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClassArray);
	}

	if (InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOvelap)
	{
		RemoveActiveEffects(TargetActor);
	}
}
