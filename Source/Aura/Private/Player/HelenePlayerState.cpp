// Copyright Ectimel


#include "Player/HelenePlayerState.h"

#include "AbilitySystem/HeleneAbilitySystemComponent.h"
#include "AbilitySystem/HeleneAttributeSet.h"
#include "Net/UnrealNetwork.h"

AHelenePlayerState::AHelenePlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UHeleneAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UHeleneAttributeSet>("Attribute Set");
}

void AHelenePlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AHelenePlayerState, Level);
}

UAbilitySystemComponent* AHelenePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AHelenePlayerState::OnRep_Level(int32 OldLevel)
{
}
