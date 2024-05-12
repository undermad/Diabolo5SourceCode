// Copyright Ectimel


#include "HeleneAssetManager.h"
#include "HeleneGameplayTags.h"


UHeleneAssetManager& UHeleneAssetManager::Get()
{
	check(GEngine);
	return *Cast<UHeleneAssetManager>(GEngine->AssetManager);
}

void UHeleneAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FHeleneGameplayTags::InitializeNativeGameplayTags();
}
