// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerCode.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMBATPROJECT_API UPlayerCode : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerCode();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* comboMontage;

	UPROPERTY(VisibleDefaultsOnly,Category = "Mesh")
	USkeletalMeshComponent* characterMesh;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void LightAttack();
	bool isAttacking();
	int comboIndex = 0;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void HandleOnMontageNotifyBegin(FName notifyName, const FBranchingPointNotifyPayload& branchingPayload);

		
};
