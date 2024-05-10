// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/RomoCharacterBase.h"

ARomoCharacterBase::ARomoCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
}

void ARomoCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

