// Copyright Peter Carsten Collins (2024)

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AuraAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTagsSignature, const FGameplayTagContainer& /*AssetTags*/) 

/**
 * Aura base ability system component
 */
UCLASS()
class AURA_API UAuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	// When this function is called, we know AbilityActorInfo has been set. Used for binding delegates
	void AbilityActorInfoSet();

	// Delegate for the WidgetController to bind to
	FEffectAssetTagsSignature EffectAssetTags;

protected:
	// Function called when a gameplay effect is applied to this ASC
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
	
};
