// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetControllers/OverlayWidgetController.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystemComponent.h"
//#include "Engine/DataTable.h"
//#include "GameplayTagContainer.h"
#include "UI/Widgets/AuraBaseWidget.h"
#include "UI/WidgetControllers/AuraWidgetController.h"



void UOverlayWidgetController::BroadcastInitialValues()
{
	//cast the AttributeSet from AuraWidgetController.
	const UBaseAttributeSet* BaseAttributeSet = CastChecked<UBaseAttributeSet>(AttributeSet);
	
	//Broadcasting initial values
	OnHealthChanged.Broadcast(BaseAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(BaseAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(BaseAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(BaseAttributeSet->GetMaxMana());
	OnXPChanged.Broadcast(BaseAttributeSet->GetExperience());

}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UBaseAttributeSet* BaseAttributeSet = CastChecked<UBaseAttributeSet>(AttributeSet);

	//lets the controller see when the attributes change
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetHealthAttribute()).AddLambda(
	[this](const FOnAttributeChangeData Data) {
			OnHealthChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData Data) {
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData Data) {
			OnManaChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetMaxManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData Data) {
			OnMaxManaChanged.Broadcast(Data.NewValue);
		}
	);

	//callback for the broadcasted delegate declared in BaseAbilitySystemComponent
	Cast<UBaseAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				//Example "Message.HealthPotion"
				// "Message.HealthPotion".MatchesTag("Message") will return True, 
				// "Message".MatchesTag("Message.HealthPotion") will return False

				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));

				if (Tag.MatchesTag(MessageTag)) {
					//we get the message data table's row by tag name. The row has the same
					//name as the tag.
					FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);
}









