// Copyright Ectimel

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * Helene Gameplay Tags.
 * Singleton containing native Gameplay Tags
 */

struct FHeleneGameplayTags
{
public:
	static const FHeleneGameplayTags& GetInstance() { return  GameplayTags; }
	static void InitializeNativeGameplayTags();


	FGameplayTag Attribute_Primary_Strength;
	FGameplayTag Attribute_Primary_Intelligence;
	FGameplayTag Attribute_Primary_Resilience;
	FGameplayTag Attribute_Primary_Vigor;
	
	FGameplayTag Attribute_Secondary_Armor;
	FGameplayTag Attribute_Secondary_ArmorPenetration;
	FGameplayTag Attribute_Secondary_BlockChance;
	FGameplayTag Attribute_Secondary_CriticalHitChance;
	FGameplayTag Attribute_Secondary_CriticalHitDamage;
	FGameplayTag Attribute_Secondary_CriticalHitResistance;
	FGameplayTag Attribute_Secondary_HealthRegeneration;
	FGameplayTag Attribute_Secondary_ManaRegeneration;
	FGameplayTag Attribute_Secondary_MaxHealth;
	FGameplayTag Attribute_Secondary_MaxMana;
	

protected:

private:
	static FHeleneGameplayTags GameplayTags;
};
