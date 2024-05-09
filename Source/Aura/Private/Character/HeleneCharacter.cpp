// Copyright Ectimel


#include "Character/HeleneCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/HeleneAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/HelenePlayerController.h"
#include "Player/HelenePlayerState.h"
#include "UI/HUD/HeleneHUD.h"

AHeleneCharacter::AHeleneCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = 0;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AHeleneCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// init ability actor info for the server
	InitAbilityActorInfo();
}

void AHeleneCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// init ability actor info on the client
	InitAbilityActorInfo();
}

int32 AHeleneCharacter::GetPlayerLevel()
{
	const AHelenePlayerState* HelenePlayerState = GetPlayerState<AHelenePlayerState>();
	check(HelenePlayerState)
	return HelenePlayerState->GetPlayerLevel();
}

void AHeleneCharacter::InitAbilityActorInfo()
{
	AHelenePlayerState* HelenePlayerState = GetPlayerState<AHelenePlayerState>();
	check(HelenePlayerState);
	HelenePlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(HelenePlayerState, this);
	Cast<UHeleneAbilitySystemComponent>(HelenePlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = HelenePlayerState->GetAbilitySystemComponent();
	AttributeSet = HelenePlayerState->GetAttributeSet();

	if (AHelenePlayerController* HelenePlayerController = Cast<AHelenePlayerController>(GetController()))
	{
		if (AHeleneHUD* HeleneHUD = Cast<AHeleneHUD>(HelenePlayerController->GetHUD()))
		{
			HeleneHUD->InitOverlay(HelenePlayerController, HelenePlayerState, AbilitySystemComponent, AttributeSet);
		}
	}

	InitializeDefaultAttributes();
}
