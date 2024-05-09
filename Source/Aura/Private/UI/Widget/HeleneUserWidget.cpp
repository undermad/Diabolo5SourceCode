// Copyright Ectimel


#include "UI/Widget/HeleneUserWidget.h"

void UHeleneUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
