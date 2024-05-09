// Copyright Ectimel

#pragma once

#include "CoreMinimal.h"
#include "Character/HeleneCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "HeleneEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AHeleneEnemy : public AHeleneCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AHeleneEnemy();

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

public:
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	// Combat Interface
	virtual int32 GetPlayerLevel() override;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Class Defaults")
	int32 Level = 1;

};
