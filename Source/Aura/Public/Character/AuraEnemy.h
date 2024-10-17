// Copyright Peter Carsten Collins (2024)

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacter.h"
#include "Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AuraEnemy.generated.h"

class UWidgetComponent;

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

	// Begin ICombatInterface interface
	virtual int32 GetPlayerLevel() override;
	// End ICombatInterface interface

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;

protected:
	// Begin AActor interface //
	virtual void BeginPlay() override;
	// End AActor interface //

	// Begin AAuraCharacterBase interface
	virtual void InitAbilityActorInfo() override;
	// End AAuraCharacterBase interface

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1; // Not replicated; Server only needs this

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
};
