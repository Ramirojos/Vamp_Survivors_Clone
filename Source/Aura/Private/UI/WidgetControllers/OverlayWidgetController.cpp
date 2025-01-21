// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetControllers/OverlayWidgetController.h"
#include "UI/WidgetControllers/AuraWidgetController.h"
#include "AbilitySystem/BaseAttributeSet.h"



void UOverlayWidgetController::BroadcastInitialValues()
{
	//cast the AttributeSet from AuraWidgetController.
	const UBaseAttributeSet* BaseAttributeSet = CastChecked<UBaseAttributeSet>(AttributeSet);
	
	//Broadcasting initial values
	OnHealthChanged.Broadcast(BaseAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(BaseAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(BaseAttributeSet->GetMana());
	OnMaxmanaChanged.Broadcast(BaseAttributeSet->GetMaxMana());
	OnXPChanged.Broadcast(BaseAttributeSet->GetExperience());
}


