// Copyright Ectimel

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/HeleneWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UAttributeMenuWidgetController : public UHeleneWidgetController
{
	GENERATED_BODY()


public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;
};
