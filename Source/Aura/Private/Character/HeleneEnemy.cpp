// Copyright Ectimel


#include "Character/HeleneEnemy.h"

#include "AbilitySystem/HeleneAbilitySystemComponent.h"
#include "AbilitySystem/HeleneAttributeSet.h"
#include "Aura/Aura.h"


AHeleneEnemy::AHeleneEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UHeleneAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UHeleneAttributeSet>("Attribute Set");
}

void AHeleneEnemy::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
}

void AHeleneEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UHeleneAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}

void AHeleneEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AHeleneEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

int32 AHeleneEnemy::GetPlayerLevel()
{
	return Level;
}
