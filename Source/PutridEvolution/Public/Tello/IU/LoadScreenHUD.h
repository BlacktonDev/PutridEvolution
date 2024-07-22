// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Widget/LoadScreenWidget.h"
#include "ViewModel/MVVM_LoadScreen.h"
#include "LoadScreenHUD.generated.h"

/**
 * 
 */
UCLASS()
class PUTRIDEVOLUTION_API ALoadScreenHUD : public AHUD
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> LoadScreenWidgetClass;

	UPROPERTY(BlueprintReadOnly, Category = "UI")
	TObjectPtr<ULoadScreenWidget> LoadScreenWidget = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "ViewModel")
	TSubclassOf<UMVVM_LoadScreen> LoadScreenViewModelClass;

	UPROPERTY(BlueprintReadOnly, Category = "ViewModel")
	TObjectPtr<UMVVM_LoadScreen> LoadScreenViewModel = nullptr;
protected:
	virtual void BeginPlay() override;
};
