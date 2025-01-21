// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetControllers/AuraWidgetController.h"
#include "AttributeSet.h"
//#include "Game/PlayerCharacterState.h"
//#include "PlayerController/PlayerCharacterController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

//virtual because any controller that inherits this class 
// should be able to broadcast it's own initial values
void UAuraWidgetController::BroadcastInitialValues()
{

}
