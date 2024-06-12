// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/RomoAttributeSet.h"
#include "Net/UnrealNetwork.h"

URomoAttributeSet::URomoAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitMana(75.f);
	InitMaxMana(75.f);
}

void URomoAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(URomoAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URomoAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URomoAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(URomoAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void URomoAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URomoAttributeSet, Health, OldHealth);
}

void URomoAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URomoAttributeSet, MaxHealth, OldMaxHealth);
}

void URomoAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URomoAttributeSet, Mana, OldMana);
}

void URomoAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URomoAttributeSet, MaxMana, OldMaxMana);
}
