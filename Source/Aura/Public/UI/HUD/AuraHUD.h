// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAuraBaseWidget;
class UAttributeSet;
class UAbilitySystemComponent;
class UOverlayWidgetController;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	//Store the widget itself once created
	UPROPERTY()
	TObjectPtr<UAuraBaseWidget> OverlayWidget;
	
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:

	
private:
	
	//we need to know the class of the widget
	UPROPERTY(EditAnywhere);
	TSubclassOf<UAuraBaseWidget>OverlayWidgetClass;

	//stores widget controller
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	//for the overlay widget controller class
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
