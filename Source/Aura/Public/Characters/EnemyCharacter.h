// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "Interaction/CombatInterface.h"
#include "Interaction/EnemyInterface.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AEnemyCharacter : public ACharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	
public:

	AEnemyCharacter();

	//Enemy Interface

	//Combat Interface
	virtual int32 GetPlayerLevel() override;

protected:
	virtual void InitAbilityActorInfo() override;

	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BLueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;
private:

	
};
