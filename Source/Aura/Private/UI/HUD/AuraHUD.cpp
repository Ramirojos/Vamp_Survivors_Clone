// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "UI/Widgets/AuraBaseWidget.h"
#include "UI/WidgetControllers/AuraWidgetController.h"
#include "UI/WidgetControllers/OverlayWidgetController.h"


//Checks if any Overlay Widget Controller has been created, if it has, it store it on the pointer and return the controller 
UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		//create a new overlay widget controller if pointer is null
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		return OverlayWidgetController;
	}
	//if not nullptr, return the widget controller
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_AuraHud"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_AuraHud"));

	//create widget
	UUserWidget* Widget = CreateWidget<UAuraBaseWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraBaseWidget>(Widget);

	//create struct from AuraWidgetController.h
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);

	//construct the widget controller with GetOverlayWidgetController.
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	//Tie overlay widget and controller
	OverlayWidget->SetWidgetController(WidgetController);

	//tell widget controller to broadcast initial values
	WidgetController->BroadcastInitialValues();            

	Widget->AddToViewport();
}

