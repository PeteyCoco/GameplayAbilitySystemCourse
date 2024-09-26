// Copyright Peter Carsten Collins (2024)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

struct FInputActionValue;

class UInputMappingContext;
class UInputAction;

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

protected:
	// AActor overrides
	virtual void BeginPlay() override;

	// ACharacter overrides
	virtual void SetupInputComponent() override;
	virtual void PlayerTick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	// Move callback
	void Move(const FInputActionValue& InputActionValue);

	// Cursor trace
	void CursorTrace();

	// Actor hovered over in the previous cursor trace
	TScriptInterface<IEnemyInterface> LastActor;

	// Actor hovered over in the current cursor trace
	TScriptInterface<IEnemyInterface> ThisActor;
};
