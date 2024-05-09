// Copyright Ectimel

#pragma once

#include "CoreMinimal.h"
#include "Character/HeleneCharacterBase.h"
#include "HeleneCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AHeleneCharacter : public AHeleneCharacterBase
{
	GENERATED_BODY()


public:
	AHeleneCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	

	// Combat Interface
	virtual int32 GetPlayerLevel() override;
	// end Combat Interface
	
private:
	virtual void InitAbilityActorInfo() override;

};
