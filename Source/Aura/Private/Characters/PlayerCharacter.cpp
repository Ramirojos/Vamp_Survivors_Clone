// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerCharacter.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "Camera/CameraComponent.h"
#include "Game/PlayerCharacterState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerController/PlayerCharacterController.h"
#include "UI/HUD/AuraHUD.h"


APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	//Setting Spring Arm component
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->AddRelativeRotation(FRotator(0.0f, 45.0f, 0.0f));
	CameraBoom->TargetArmLength = 750.0f;
	CameraBoom->bInheritPitch = false;
	CameraBoom->bInheritRoll = false;
	CameraBoom->bInheritYaw = false;
	
	//Setting Camera component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComponent->SetupAttachment(CameraBoom);

	//Gameplay Ability components & attribute set
	AbilitySystemComponent = CreateDefaultSubobject<UBaseAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>(TEXT("AbilitySet"));
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();
}

/*/void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();
}*/
 //From AuraHUD InitOverlay:
 //  called en possesedby, we already the four key variables that will be used to create a WidgetController 
void APlayerCharacter::InitAbilityActorInfo()
{
	//we are both informing who the owner/avatar is for the playerCharacter,
	// (PLayerCharacterState/PlayerCharacter) and initializing the ASC/AT.
	APlayerCharacterState* PlayerCharacterState = GetPlayerState<APlayerCharacterState>();
	if (IsValid(PlayerCharacterState))
	{
		PlayerCharacterState->GetAbilitySystemComponent()->InitAbilityActorInfo(PlayerCharacterState, this);
		
		//set the ASC and ATT pointers
		AbilitySystemComponent = PlayerCharacterState->GetAbilitySystemComponent();
		AttributeSet = PlayerCharacterState->GetAttributeSet();

		if (APlayerCharacterController* PlayerCharacterController = Cast<APlayerCharacterController>(GetController()))
		{
			if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(PlayerCharacterController->GetHUD())) {
				AuraHUD->InitOverlay(PlayerCharacterController, PlayerCharacterState, AbilitySystemComponent, AttributeSet);
			}
		}
	}	
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

