// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraBaseWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraBaseWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	//associate widget controller with calling WidgetControllerSet
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InputWidgetController);

	UPROPERTY(BlueprintReadOnly, Category = "Widget Controller")
	TObjectPtr<UObject> WidgetController;

protected:

	//call as soon the controller is set
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
