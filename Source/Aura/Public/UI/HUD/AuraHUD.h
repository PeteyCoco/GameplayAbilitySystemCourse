// Copyright Peter Carsten Collins (2024)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"


class UAuraUserWidget;
class UAbilitySystemComponent;
class UAttributeSet;
class UOverlayWidgetController;

struct FWidgetControllerParams;


/**
 * HUD class for Aura project.
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;

	// Initializer to be called when the dependencies are available.
	// This will eventually be called from the character class.
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

	/** 
	* Singleton-like getter for the Overlay Widget Controller
	* 
	* NOTE: The dependencies are injected since we want to be sure they are available when this is called.
	**/
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
