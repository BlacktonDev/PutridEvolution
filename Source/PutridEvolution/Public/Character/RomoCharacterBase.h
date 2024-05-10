// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RomoCharacterBase.generated.h"

UCLASS(Abstract)
class PUTRIDEVOLUTION_API ARomoCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ARomoCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
