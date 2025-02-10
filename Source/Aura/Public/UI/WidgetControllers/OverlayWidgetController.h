// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetControllers/AuraWidgetController.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "OverlayWidgetController.generated.h"


USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag MessageTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText TextMessage = FText();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class UAuraBaseWidget> MessageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Image = nullptr;

};

class UAuraBaseWidget;
class UBaseAttributeSet;
struct FOnAttributeChangeData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAtttibuteChangedSignature, float, NewValue);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageWidgetRowSignature, FUIWidgetRow, Row);

/**
 * 
 */



UCLASS(BLueprintType, Blueprintable)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
		
		virtual void BroadcastInitialValues() override;

		virtual void BindCallbacksToDependencies() override;

		//  All Attrubtes Will be binded in blueprint.
		UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnAtttibuteChangedSignature OnHealthChanged;

		UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnAtttibuteChangedSignature OnMaxHealthChanged;

		UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnAtttibuteChangedSignature OnManaChanged;

		UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnAtttibuteChangedSignature OnMaxManaChanged;

		UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
		FOnAtttibuteChangedSignature OnXPChanged;
	
		UPROPERTY(BlueprintAssignable, Category = "GAS|Messages")
		FMessageWidgetRowSignature MessageWidgetRowDelegate;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadonly, Category = "Widget Data")
	TObjectPtr<UDataTable> MessageWidgetDataTable;

	template<typename T>
	T* GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag);
};

template<typename T>
inline T* UOverlayWidgetController::GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag)
{
	return DataTable->FindRow<T>(Tag.GetTagName(), TEXT(""));
}
