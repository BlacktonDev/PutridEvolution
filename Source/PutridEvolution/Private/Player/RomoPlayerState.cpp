// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/RomoPlayerState.h"

#include "AbilitySystem/RomoAbilitySystemComponent.h"
#include "AbilitySystem/RomoAttributeSet.h"

ARomoPlayerState::ARomoPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<URomoAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<URomoAttributeSet>("AttributeSet");
	
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* ARomoPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
