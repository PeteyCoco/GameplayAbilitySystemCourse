// Copyright Peter Carsten Collins (2024)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "AuraPlayerController.generated.h"

struct FInputActionValue;

class UAuraAbilitySystemComponent;
class UAuraInputConfig;
class UDamageTextComponent;
class UInputMappingContext;
class UInputAction;
class USplineComponent;

class IEnemyInterface;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AAuraPlayerController();

	UFUNCTION(Client, Reliable)
	void ShowDamageNumber(float DamageAmount, ACharacter* TargetCharacter, bool bBlockedHit, bool bCriticalHit);

protected:
	//~ Begin AActor interface
	virtual void BeginPlay() override;
	//~ End AActor interface

	//~ Begin ACharacter interface
	virtual void SetupInputComponent() override;
	virtual void PlayerTick(float DeltaTime) override;
	//~ End ACharacter interface

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	// Begin Shift key modifiers
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> ShiftAction;

	void ShiftPressed() { bShiftKeyDown = true; }
	void ShiftReleased() { bShiftKeyDown = false; }
	bool bShiftKeyDown = false;
	// End Shift key modifiers

	// Move callback
	void Move(const FInputActionValue& InputActionValue);

	// Cursor trace
	void CursorTrace();

	// Cached cursor location
	FHitResult CursorHit;

	// Actor hovered over in the previous cursor trace
	TScriptInterface<IEnemyInterface> LastActor;

	// Actor hovered over in the current cursor trace
	TScriptInterface<IEnemyInterface> ThisActor;

	// Input action callbacks
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);

	// Input Config data asset
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UAuraInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> AuraAbilitySystemComponent;

	UAuraAbilitySystemComponent* GetASC();

	// Movement destination
	FVector CachedDestination = FVector::ZeroVector;

	// How long have we been following the cursor?
	float FollowTime = 0.f;

	// Threshold that discriminates between a short press and a long press
	float ShortPressThreshold = 0.5f;

	// Is the character auto-running to a destination?
	bool bAutoRunning = false;

	// The acceptance radius while autorunning along a route.
	UPROPERTY(EditDefaultsOnly)
	float AutorunAcceptanceRadius = 50.f;

	// Spline representing the path
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;

	// True if the player is targeting something
	bool bTargeting = false;

	void AutoRun();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDamageTextComponent> DamageTextComponentClass;
};
