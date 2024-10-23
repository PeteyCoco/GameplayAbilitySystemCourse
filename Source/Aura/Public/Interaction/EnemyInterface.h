// Copyright Peter Carsten Collins (2024)

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface for interacting with enemy characters
 */
class AURA_API IEnemyInterface
{
	GENERATED_BODY()

public:
	// Highlight the actor in the scene
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;

};
