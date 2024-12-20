// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;


UCLASS()
class AURA_API APlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:

	APlayerCharacter();
	virtual void Tick(float DeltaTime) override;

	//for ASC owner and avatar information
	virtual void PossessedBy(AController* NewController) override;
	//virtual void OnRep_PlayerState() override;

	void InitAbilityActorInfo();
protected:

	virtual void BeginPlay() override;
	

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent>CameraComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent>CameraBoom;
};
