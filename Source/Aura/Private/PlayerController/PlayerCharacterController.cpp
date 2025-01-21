// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/PlayerCharacterController.h"
#include "Interaction/EnemyInterface.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubSystems.h"


APlayerCharacterController::APlayerCharacterController()
{
	//for multiplayer purposes
	bReplicates = true;

}

void APlayerCharacterController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);


	//CursorTrace();
}

void APlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();

	check(PlayerContext);
	
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem) {
		Subsystem->AddMappingContext(PlayerContext, 0);
	}

	//we want to sow the mouse when in menus/widgets
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	//settings for when mouse interacts with UI
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void APlayerCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
		
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacterController::Move);
}

void APlayerCharacterController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
	
}

/*void APlayerCharacterController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);

	
	//does implement Enemy Interface?
	if (!CursorHit.bBlockingHit) {
		
		return;
	}	

	//What actor was in the last frame
	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	/**
	*Possible cases for highlight (line trace from cursor)
	* A. LastActor is null && ThisActor is null(no interface)
	*	- Nothing.
	* B. LastActor is null && ThisActor is valid
	*	- Highlight ThisActor
	* C. LastActor is valid and ThisActor is null.
	*	- Unhighlight LastActor.
	* D. Both Actors are valid but Last != This
	*	- Unhighlight LastActor && Highlight ThisActor
	* E. Both Actors are valid and are the same
	*	Do Nothing
	

	if (LastActor == nullptr) {
		if (ThisActor != nullptr) {
			ThisActor->HighlightActor();
		}
		//if this actor is null, do nothing
	}
	else {
		if (ThisActor ==nullptr) {
			LastActor->UnhighlightActor();

		}
		else {
			//both actors are valid
			if (ThisActor != LastActor) {
				LastActor->UnhighlightActor();
				ThisActor->HighlightActor();
			}
			//if both are the same do nothing
		}
	}

}*/


