// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RomoCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/RomoPlayerState.h"

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

void ARomoCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the server
	InitAbilityActorInfo();

}

void ARomoCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// Init ability actor info for the client
	InitAbilityActorInfo();
}

void ARomoCharacter::InitAbilityActorInfo()
{
	ARomoPlayerState* RomoPlayerState = GetPlayerState<ARomoPlayerState>();
	check(RomoPlayerState);
	RomoPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(RomoPlayerState, this);
	AbilitySystemComponent = RomoPlayerState->GetAbilitySystemComponent();
	AttributeSet = RomoPlayerState->GetAttributeSet();
}

