// Copyright Peter Carsten Collins (2024)

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "ExecCalcDamage.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UExecCalcDamage : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UExecCalcDamage();
	
	//~ Begin UGameplayEffectExecutionCalculation interface
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const;
	//~ End UGameplayEffectExecutionCalculation interface

};
