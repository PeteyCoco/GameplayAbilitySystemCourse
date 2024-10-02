// Copyright Peter Carsten Collins (2024)

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * The Aura player character actor
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
	
public:
	AAuraCharacter();

	// Begin APawn interface
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	// End APawn interface 

	// Begin ICombatInterface interface
	virtual int32 GetPlayerLevel() override;
	// End ICombatInterface interface

private:
	// Begin AAuraCharacterBase interface
	virtual void InitAbilityActorInfo() override;
	// End AAuraCharacterBase interface

};
