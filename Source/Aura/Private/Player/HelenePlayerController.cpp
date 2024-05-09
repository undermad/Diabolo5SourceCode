// Copyright Ectimel


#include "Player/HelenePlayerController.h"
#include <EnhancedInputSubsystems.h>

#include "EnhancedInputSubsystemInterface.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AHelenePlayerController::AHelenePlayerController()
{
	bReplicates = true;
}

void AHelenePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}


void AHelenePlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	/**
	 * Line trace from cursor. There are multiple scenarios
	 * A. LastActor is null && ThisActor is null
	 *	- Do nothing
	 * B. LastActor is null && ThisActor is valid
	 *	- Highlight ThisActor
	 * C. LastActor is valid && ThisActor is null
	 *	- Unhighlight LastActor
	 * B. LastActor is valid && ThisActor is valid != LastActor
	 *	-  Unhighlight LastActor
	 *	-  Highligh ThisActor
	 * E. LastActor is valid && ThisActor is valid == LastActor
	 *	- Do nothing
	 */

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			// Case B
			ThisActor->HighlightActor();
		}
		// else Case A <- Do nothing
	}
	else // LastActor is valid
	{
		if (ThisActor == nullptr)
		{
			// Case C
			LastActor->UnHighlightActor();
		}
		else if (ThisActor && ThisActor != LastActor)
		{
			LastActor->UnHighlightActor();
			ThisActor->HighlightActor();
		}
		// else Case E <- Do nothing
	}
}


void AHelenePlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(HeleneContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(HeleneContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AHelenePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AHelenePlayerController::Move);
}

void AHelenePlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
