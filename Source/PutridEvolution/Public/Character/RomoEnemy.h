// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/RomoCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "RomoEnemy.generated.h"

/**
 * 
 */
UCLASS()
class PUTRIDEVOLUTION_API ARomoEnemy : public ARomoCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	ARomoEnemy();
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	
};
