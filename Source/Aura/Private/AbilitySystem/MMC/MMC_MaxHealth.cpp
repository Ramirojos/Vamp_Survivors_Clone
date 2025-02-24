// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MMC/MMC_MaxHealth.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	ConstDef.AttributeToCapture = UBaseAttributeSet::GetConstitutionAttribute();
	ConstDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;

	//we capture the attribute as soon as the gameplay spec is created
	ConstDef.bSnapshot = false;

	//that ae relevant to the calculation
	RelevantAttributesToCapture.Add(ConstDef);
}

//Returns the value result from the modifier calculation.
float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{

	//Get the tags associated to the source and the target
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	//Capture attributes and get magnitude
	FAggregatorEvaluateParameters EvalParameters;
	EvalParameters.SourceTags = SourceTags;
	EvalParameters.TargetTags = TargetTags;
	
	//Magnitude value
	float Constitution = 0.f;

	GetCapturedAttributeMagnitude(ConstDef, Spec, EvalParameters, Constitution);

	//Clamp the magnitude
	Constitution = FMath::Max<float>(Constitution, 0.f);

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	//Value returned form mod calculation
	return 80.f + (2.5f * Constitution) + 10 * PlayerLevel;
}
