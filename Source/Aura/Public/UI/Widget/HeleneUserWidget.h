// Copyright Ectimel

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HeleneUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UHeleneUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
