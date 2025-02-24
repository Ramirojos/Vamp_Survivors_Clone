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

	/*
	* Secondary Attributtes
	*/
	
	/*STRENGHT*/

	//Related to projectile damage
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData ProjectileDamage;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, ProjectileDamage);

	//Related to armor penetration
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, ArmorPenetration);

	//Related to armor penetration
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData ProjectileSize;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, ProjectileSize);

	//Related to Critical Damage
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData CriticalDamage;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, CriticalDamage);

	/*DEXTERITY*/

	//Related to projectile spawn rate
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData ProjectileSpawnrate;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, ProjectileSpawnrate);

	//Related to projectile speed
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData ProjectileSpeed;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, ProjectileSpeed);

	//Related to Critical Chance
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData CriticalChance;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, CriticalChance);

	//Related to Evation
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData Evation;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Evation);

	//Related to Movement Speed
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MovementSpeed);

	/*CONSTITUTION*/

	//Related o health regeneration per second
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, HealthRegeneration);

	//Related to damage reduction
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Armor);

	/*INTELIGENCE*/

	//Related to spellDamage
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData SpellDamage;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, SpellDamage);

	//Related to habilities cooldown 
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData SpellCooldown;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, SpellCooldown);

	//Related to critical spell chance
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData CriticalSpellChance;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, CriticalSpellChance);

	//Related to spell critical damage
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData CriticalSpellDamage;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, CriticalSpellDamage);

	//Related to mana regeneration per second 
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, ManaRegeneration);


	/*
	*	Vital Attributtes
	*/
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attribute")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Health);

	/*CONSTITUTION*/
	
	UPROPERTY(BlueprintReadOnly, Category = "Vital Attribute")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHealth);
	
	/**/
	
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Mana);
	
	/*INTELIGENCE*/

	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxMana);
	
	/**/
	
	UPROPERTY(BlueprintReadOnly, Category = "Secondary Attribute")
	FGameplayAttributeData Experience;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Experience);
	
private:
	
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties Props);
};
