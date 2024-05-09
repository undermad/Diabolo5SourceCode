// Copyright Ectimel


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/HeleneAbilitySystemComponent.h"
#include "AbilitySystem/HeleneAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UHeleneAttributeSet* HeleneAttributeSet = CastChecked<UHeleneAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(HeleneAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(HeleneAttributeSet->GetMaxHealth());

	OnManaChanged.Broadcast(HeleneAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(HeleneAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	UHeleneAttributeSet* HeleneAttributeSet = CastChecked<UHeleneAttributeSet>(AttributeSet);

	if (HeleneAttributeSet)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HeleneAttributeSet->GetHealthAttribute())
							  .AddLambda([this](const FOnAttributeChangeData& Data)
							  {
								  OnHealthChanged.Broadcast(Data.NewValue);
							  });

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HeleneAttributeSet->GetMaxHealthAttribute())
							  .AddLambda([this](const FOnAttributeChangeData& Data)
							  {
								  OnMaxHealthChanged.Broadcast(Data.NewValue);
							  });

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HeleneAttributeSet->GetManaAttribute())
							  .AddLambda([this](const FOnAttributeChangeData& Data)
							  {
								  OnManaChanged.Broadcast(Data.NewValue);
							  });

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HeleneAttributeSet->GetMaxManaAttribute())
		                      .AddLambda([this](const FOnAttributeChangeData& Data)
		                      {
			                      OnMaxManaChanged.Broadcast(Data.NewValue);
		                      });
	}

	Cast<UHeleneAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowSignature.Broadcast(*Row);
				}
			}
		}
	);
}

