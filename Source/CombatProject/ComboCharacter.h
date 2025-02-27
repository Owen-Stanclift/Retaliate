// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ComboCharacter.generated.h"

UCLASS()
class COMBATPROJECT_API AComboCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AComboCharacter();


	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Animation")
	UAnimMontage* comboMontage;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void LightAttack();
	bool isAttacking();
	int comboIndex = 0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void HandleOnMontageNotifyBegin(FName notifyName, const FBranchingPointNotifyPayload& branchingPayload);

};
