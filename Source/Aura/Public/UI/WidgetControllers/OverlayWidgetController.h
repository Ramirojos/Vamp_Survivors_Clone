// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetControllers/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature, float, NewMaxMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnXPChangedSignature, float, NewXP);

/**
 * 
 */

class UBaseAttributeSet;

UCLASS(BLueprintType, Blueprintable)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
		
		virtual void BroadcastInitialValues() override;

		//  All Attrubtes Will be binded in blueprint.
		UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnHealthChangedSignature OnHealthChanged;

		UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnMaxHealthChangedSignature OnMaxHealthChanged;

		UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnManaChangedSignature OnManaChanged;

		UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnMaxManaChangedSignature OnMaxmanaChanged;

		UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnXPChangedSignature OnXPChanged;


};
