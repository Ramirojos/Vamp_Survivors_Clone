// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/PlayerCharacterState.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"

APlayerCharacterState::APlayerCharacterState()
{
	//Constructon ASC and Att.
	AbilitySystemComponent = CreateDefaultSubobject<UBaseAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>(TEXT("AbilitySet"));
}

//returns ASC pointer
UAbilitySystemComponent* APlayerCharacterState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void APlayerCharacterState::BeginPlay()
{
	Super::BeginPlay();
}
