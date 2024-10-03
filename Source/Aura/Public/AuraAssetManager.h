// Copyright Peter Carsten Collins (2024)

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AuraAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	// Singleton getter
	static UAuraAssetManager& Get();
	
protected:
	// Begin UAssetManager interface
	virtual void StartInitialLoading() override;
	// End UAssetManager interface
};
