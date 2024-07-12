// Fill out your copyright notice in the Description page of Project Settings.


#include "Tello/IU/LoadScreenHUD.h"
#include "Tello/IU/Widget/LoadScreenWidget.h"
#include "Tello/IU/ViewModel/MVVM_LoadScreen.h"
#include "Blueprint/UserWidget.h"

void ALoadScreenHUD::BeginPlay() 
{
	
	Super::BeginPlay();

	LoadScreenViewModel = NewObject<UMVVM_LoadScreen>(this, LoadScreenViewModelClass);

	LoadScreenWidget = CreateWidget<ULoadScreenWidget>(GetWorld(), LoadScreenWidgetClass);
	LoadScreenWidget->AddToViewport();
}