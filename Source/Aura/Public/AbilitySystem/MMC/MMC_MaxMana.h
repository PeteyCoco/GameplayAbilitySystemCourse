// Copyright Peter Carsten Collins (2024)

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxMana.generated.h"

/**
 * ModMaxCalculation for MaxMana attribute
 */
UCLASS()
class AURA_API UMMC_MaxMana : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	UMMC_MaxMana();

	// Begin UGameplayModMagnitudeCalculation Interface
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	// End UGameplayModMagnitudeCalculation Interface

private:
	FGameplayEffectAttributeCaptureDefinition IntelligenceDef;
};
