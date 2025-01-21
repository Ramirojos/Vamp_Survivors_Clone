// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/AuraBaseWidget.h"


void UAuraBaseWidget::SetWidgetController(UObject* InputWidgetController)
{
	WidgetController = InputWidgetController;
	WidgetControllerSet();
}