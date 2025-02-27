// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCode.h"

// Sets default values for this component's properties
UPlayerCode::UPlayerCode()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerCode::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerCode::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerCode::HandleOnMontageNotifyBegin(FName notifyName, const FBranchingPointNotifyPayload& branchingPayload)
{
	comboIndex--;
	if (comboIndex < 0)
	{
		UAnimInstance* pAnimInst = characterMesh->GetAnimInstance();
		if (pAnimInst != nullptr)
		{
			pAnimInst->Montage_Stop(0.4f, comboMontage);
		}
	}
}

void UPlayerCode::LightAttack()
{
	if (!isAttacking())
	{
		UAnimInstance* pAnimInst = characterMesh->GetAnimInstance();
		if (pAnimInst != nullptr)
		{
			pAnimInst->Montage_Play(comboMontage);
		}

	}
	else
	{
		comboIndex = 1;
	}
}

