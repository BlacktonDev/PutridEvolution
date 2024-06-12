// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/RomoPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

ARomoPlayerController::ARomoPlayerController()
{
	bReplicates = true;
}

void ARomoPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void ARomoPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;
	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	/**
	 * Line trace del cursor, hay varias posibilidades
	 *	A. LastActor es Null && ThisActor es Null
	 *		- No se hace nada
	 *	B. LastActor es Null && ThisActor es valido
	 *		- Highlight ThisActor
	 *	C. LastActor es valido && ThisActor es null
	 *		- UnHighlight LastActor
	 *	D. Los dos son validos pero LastActor != ThisActor
	 *		- UnHighlight LastActor, Highlight ThisActor
	 *	E. Los dos son validos y son el mismo
	 *		- No se hace nada
	 */
	if (LastActor == nullptr)
	{
		if(ThisActor != nullptr)
		{
			//Caso B
			ThisActor->HighlightActor();
		}
		else
		{
			// Caso A. Los dos son nulos, no se hace nada
		}
	}
	else //LastActor es valido
	{
		if (ThisActor == nullptr)
		{
			// Case C
			LastActor->UnHighlightActor();
		}
		else //los dos actores son validos
		{
			if (LastActor != ThisActor)
			{
				// Caso D.
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else 
			{
				//Caso E, no se hace nada
			}
		}
	}
}

void ARomoPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(RomoContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(RomoContext, 0);
	}
	check(Subsystem);
	Subsystem->AddMappingContext(RomoContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ARomoPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARomoPlayerController::Move);
}

void ARomoPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection =  FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}


