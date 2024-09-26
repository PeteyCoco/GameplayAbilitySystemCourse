// Copyright Peter Carsten Collins (2024)

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacter.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * Character class for enemy units
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacter, public IEnemyInterface
{
	GENERATED_BODY()
	
public:
	AAuraEnemy();

	// Begin IEnemyInterface interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	// End IEnemyInterface interface

protected:
	// Begin AActor interface //
	virtual void BeginPlay() override;
	// End AActor interface //

};
