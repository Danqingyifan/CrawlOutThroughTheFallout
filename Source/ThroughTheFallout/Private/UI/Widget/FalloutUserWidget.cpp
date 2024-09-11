// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/FalloutUserWidget.h"

void UFalloutUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	OnWidgetControllerSet();
}

