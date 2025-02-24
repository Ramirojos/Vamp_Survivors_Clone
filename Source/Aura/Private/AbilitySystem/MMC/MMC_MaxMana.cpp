// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MMC/MMC_MaxMana.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	IntDef.AttributeToCapture = UBaseAttributeSet::GetIntelligenceAttribute();
	IntDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;

	//we capture the attribute as soon as the gameplay spec is created
	IntDef.bSnapshot = false;

	//that ae relevant to the calculation
	RelevantAttributesToCapture.Add(IntDef);
}


//Returns the value result from the modifier calculation.
float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	//Get the tags associated to the source and the target
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	//Capture attributes and get magnitude
	FAggregatorEvaluateParameters EvalParameters;
	EvalParameters.SourceTags = SourceTags;
	EvalParameters.TargetTags = TargetTags;

	//Magnitude value
	float Intelligence = 0.f;

	GetCapturedAttributeMagnitude(IntDef, Spec, EvalParameters, Intelligence);

	//Clamp the magnitude
	Intelligence = FMath::Max<float>(Intelligence, 0.f);

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	//Value returned form mod calculation
	return 40.f + (2.5f * Intelligence) + 10 * PlayerLevel;
}
