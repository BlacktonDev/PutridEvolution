// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RomoCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

ARomoCharacter::ARomoCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

