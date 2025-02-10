// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "BaseAttributeSet.generated.h"


//Define macros to access the accessors methods.
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
class FGameplayEffectModCallback;

USTRUCT()
struct FEffectProperties {
	
	GENERATED_BODY()

	FEffectProperties() {};

	FGameplayEffectContextHandle EEffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;
	
	UPROPERTY()
	AController* SourceController = nullptr;
	
	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;
	
	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr; 
	
	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;

};


UCLASS()
class AURA_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	UBaseAttributeSet();

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data);


	/*
	* Primary Attributtes
	*/

	//Related to projectile damage
	UPROPERTY(BlueprintReadOnly, Category = "Primary Attribute")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Strength);

	//Related to attack rate and evasion
	UPROPERTY(BlueprintReadOnly, Category = "Primary Attribute")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Dexterity);

	//Related to max health and health regeneration
	UPROPERTY(BlueprintReadOnly, Category = "Primary Attribute")
	FGameplayAttributeData Constitution;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Constitution);

	//Related to magical damage, max mana and mana regenation
	UPROPERTY(BlueprintReadOnly, Category = "Primary Attribute")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Intelligence);

	//Related to armor (Damage reduction)
	UPROPERTY(BlueprintReadOnly, Category = "Primary Attribute")
	FGameplayAttributeData Endurance;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Endurance);

	//Related to character movement speed
	UPROPERTY(BlueprintReadOnly, Category = "Primary Attribute")
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Speed);

	/*
	*	Vital Attributtes
	*/
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attribute")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, Category = "Vital Attribute")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Mana);
	
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxMana);

	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData Experience;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Experience);
	
private:
	
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties Props);
};
