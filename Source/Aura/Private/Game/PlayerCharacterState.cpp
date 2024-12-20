// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/PlayerCharacterState.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"

APlayerCharacterState::APlayerCharacterState()
{
	//Constructon ASC and Att.Set, replication no needed since it's a single player game
	AbilitySystemComponent = CreateDefaultSubobject<UBaseAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	//AbilitySystemComponent->SetIsReplicated(true);
	//AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>(TEXT("AbilitySet"));

	//how often update the client
	//NetUpdateFrequency = 100.f;
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
