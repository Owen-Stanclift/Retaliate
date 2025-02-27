// Fill out your copyright notice in the Description page of Project Settings.


#include "ComboCharacter.h"

// Sets default values
AComboCharacter::AComboCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AComboCharacter::BeginPlay()
{
	Super::BeginPlay();
	

	UAnimInstance* pAnimInst = GetMesh()->GetAnimInstance();
	if (pAnimInst != nullptr)
	{
		pAnimInst->OnPlayMontageNotifyBegin.AddDynamic(this, &AComboCharacter::HandleOnMontageNotifyBegin);
	}
}

// Called every frame
void AComboCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AComboCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AComboCharacter::HandleOnMontageNotifyBegin(FName notifyName, const FBranchingPointNotifyPayload& branchingPayload)
{
	comboIndex--;
	if (comboIndex < 0)
	{
		UAnimInstance* pAnimInst = GetMesh()->GetAnimInstance();
		if (pAnimInst != nullptr)
		{
			pAnimInst->Montage_Stop(0.4f, comboMontage);
		}
	}
}

void AComboCharacter::LightAttack()
{
	if (!isAttacking() && CanJump())
	{
		UAnimInstance* pAnimInst = GetMesh()->GetAnimInstance();
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

