// Copyright Peter Carsten Collins (2024)

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxHealth.generated.h"

/**
 * ModMaxCalculation for MaxHealth attribute
 */
UCLASS()
class AURA_API UMMC_MaxHealth : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	UMMC_MaxHealth();
	
	// Begin UGameplayModMagnitudeCalculation Interface
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	// End UGameplayModMagnitudeCalculation Interface

private:
	FGameplayEffectAttributeCaptureDefinition VigorDef;
};
