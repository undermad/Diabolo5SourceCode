// Copyright Ectimel


#include "HeleneGameplayTags.h"

#include "GameplayTagsManager.h"

FHeleneGameplayTags FHeleneGameplayTags::GameplayTags;

void FHeleneGameplayTags::InitializeNativeGameplayTags()
{
	
	// Primary Attributes	
	GameplayTags.Attribute_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Primary.Strength"), FString("Reduces damage taken, improve Block Chance."));
	
	GameplayTags.Attribute_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attribute.Primary.Intelligence"), FString("Increase magical damage"));
	
	GameplayTags.Attribute_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Primary.Resilience"), FString("Increase Armor and Armor Penetration"));
	
	GameplayTags.Attribute_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attribute.Primary.Vigor"), FString("Increase Health"));

	
	// Secondary Attributes
	GameplayTags.Attribute_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attribute.Secondary.Armor"), FString("Reduces damage taken, improve Block Chance."));
	
	GameplayTags.Attribute_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(
				FName("Attribute.Secondary.ArmorPenetration"), FString("Ignore percentage of enemy Armor, increases Critical Hit Chance."));

	GameplayTags.Attribute_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
				FName("Attribute.Secondary.BlockChance"), FString("Chance to reduce incoming damage."));

	GameplayTags.Attribute_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
				FName("Attribute.Secondary.CriticalHitChance"), FString("Chance to deal double damage plus critical hit bonus."));

	GameplayTags.Attribute_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
					FName("Attribute.Secondary.CriticalHitDamage"), FString("Percent of damage added to critical hits."));
	
	GameplayTags.Attribute_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
				FName("Attribute.Secondary.CriticalHitResistance"), FString("Reduces critical hit chance of attackers."));

	GameplayTags.Attribute_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
				FName("Attribute.Secondary.HealthRegeneration"), FString("Health regenerated every second."));
	
	GameplayTags.Attribute_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
				FName("Attribute.Secondary.ManaRegeneration"), FString("Mana regenerated every second."));

	GameplayTags.Attribute_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
				FName("Attribute.Secondary.MaxHealth"), FString("Maximum health."));

	GameplayTags.Attribute_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
				FName("Attribute.Secondary.MaxMana"), FString("Maximum mana."));

	
}
