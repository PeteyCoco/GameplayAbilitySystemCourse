// Copyright Peter Carsten Collins (2024)


#include "AbilitySystem/AbilityTasks/TargetDataUnderMouse.h"
#include "AbilitySystemComponent.h"

UTargetDataUnderMouse* UTargetDataUnderMouse::CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility)
{
	UTargetDataUnderMouse* MyObj = NewAbilityTask<UTargetDataUnderMouse>(OwningAbility);
	return MyObj;
}

void UTargetDataUnderMouse::Activate()
{

	const bool bIsLocallyControlled = Ability->GetCurrentActorInfo()->IsLocallyControlled();
	if (bIsLocallyControlled)
	{
		SendMouseCursorData();
	}
	else
	{
		// Bind the target data set callback to the delegate on activation
		const FGameplayAbilitySpecHandle SpecHandle = GetAbilitySpecHandle();
		const FPredictionKey PredictionKey = GetActivationPredictionKey();

		/* Bind to the Target Data set delegate. Ideally done before the target data arrives on the server. */
		AbilitySystemComponent.Get()->AbilityTargetDataSetDelegate(SpecHandle, PredictionKey).AddUObject(this, &UTargetDataUnderMouse::OnTargetDataReplicatedCallback);

		/* Safeguard in case the replicated data arrives first and the delegate is broadcast before the server can bind to the Target Data set delegate, this will force the broadcast of the delegate again.*/
		const bool bCalledDelegate = AbilitySystemComponent.Get()->CallReplicatedTargetDataDelegatesIfSet(SpecHandle, PredictionKey); 
		if (!bCalledDelegate)
		{
			SetWaitingOnRemotePlayerData();
		}
	}

}

void UTargetDataUnderMouse::SendMouseCursorData()
{
	// Everything in here should be predicted
	FScopedPredictionWindow ScopedPrediction(AbilitySystemComponent.Get());

	APlayerController* PC = Ability->GetCurrentActorInfo()->PlayerController.Get();
	FHitResult CursorHit;
	PC->GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);

	// Gather the data
	FGameplayAbilityTargetDataHandle DataHandle;
	FGameplayAbilityTargetData_SingleTargetHit* Data = new FGameplayAbilityTargetData_SingleTargetHit();
	Data->HitResult = CursorHit;
	DataHandle.Add(Data);

	// Send data up to the server (where it will broadcast the target set delegate)
	AbilitySystemComponent->ServerSetReplicatedTargetData(
		GetAbilitySpecHandle(), 
		GetActivationPredictionKey(), 
		DataHandle, 
		FGameplayTag(),
		AbilitySystemComponent->ScopedPredictionKey
	);

	if (ShouldBroadcastAbilityTaskDelegates())
	{
		ValidData.Broadcast(DataHandle);
	}
}

void UTargetDataUnderMouse::OnTargetDataReplicatedCallback(const FGameplayAbilityTargetDataHandle& DataHandle, FGameplayTag ActivationTag)
{
	// Tell the ability system that data has been received (so it can clear cached data)
	AbilitySystemComponent->ConsumeClientReplicatedTargetData(GetAbilitySpecHandle(), GetActivationPredictionKey()); 

	if (ShouldBroadcastAbilityTaskDelegates())
	{
		ValidData.Broadcast(DataHandle);
	}
}
