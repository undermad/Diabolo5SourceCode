// Copyright Ectimel


#include "UI/WidgetController/HeleneWidgetController.h"

void UHeleneWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UHeleneWidgetController::BroadcastInitialValues()
{
	
}

void UHeleneWidgetController::BindCallbacksToDependencies()
{
	
}
