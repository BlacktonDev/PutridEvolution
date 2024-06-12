// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RomoCharacterBase.h"

ARomoCharacterBase::ARomoCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ARomoCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ARomoCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

