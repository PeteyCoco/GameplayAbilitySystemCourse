// Copyright Peter Carsten Collins (2024)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class USphereComponent;

/*
* Base class for actors that apply gameplay effects on overlap
*/
UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();

	// Overlap handlers
	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	// Begin AActor overrides
	virtual void BeginPlay() override;
	// End AActor overrides

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
};
