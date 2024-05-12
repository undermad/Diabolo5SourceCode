// Copyright Ectimel

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "HeleneAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UHeleneAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static UHeleneAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
};
