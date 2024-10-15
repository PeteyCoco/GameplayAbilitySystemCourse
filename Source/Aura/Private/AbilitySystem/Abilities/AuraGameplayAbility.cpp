// Copyright Peter Carsten Collins (2024)


#include "AbilitySystem/Abilities/AuraGameplayAbility.h"

#include "Kismet/KismetSystemLibrary.h"

void UAuraGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	UKismetSystemLibrary::PrintString(GetWorld(), FString("Activate ability (C++)"), true, true, FLinearColor::Yellow, 3.f);
}
