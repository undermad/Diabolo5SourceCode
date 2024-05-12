// Copyright Ectimel


#include "AbilitySystem/HeleneAbilitySystemLibrary.h"

#include "AbilitySystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/HelenePlayerState.h"
#include "UI/HUD/HeleneHUD.h"
#include "UI/WidgetController/HeleneWidgetController.h"

UOverlayWidgetController* UHeleneAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AHeleneHUD* HeleneHUD = Cast<AHeleneHUD>(PlayerController->GetHUD()))
		{
			AHelenePlayerState* PlayerState = PlayerController->GetPlayerState<AHelenePlayerState>();
			UAbilitySystemComponent* AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();
			UAttributeSet* AttributeSet = PlayerState->GetAttributeSet();

			const FWidgetControllerParams WidgetControllerParams(PlayerController, PlayerState, AbilitySystemComponent,
			                                                     AttributeSet);

			return HeleneHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UHeleneAbilitySystemLibrary::GetAttributeMenuWidgetController(
	const UObject* WorldContextObject)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AHeleneHUD* HeleneHUD = Cast<AHeleneHUD>(PlayerController->GetHUD()))
		{
			AHelenePlayerState* PlayerState = PlayerController->GetPlayerState<AHelenePlayerState>();
			UAbilitySystemComponent* AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();
			UAttributeSet* AttributeSet = PlayerState->GetAttributeSet();

			FWidgetControllerParams WidgetControllerParams(PlayerController, PlayerState, AbilitySystemComponent,
			                                               AttributeSet);
			return HeleneHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}
