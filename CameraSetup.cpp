#include "MyGameCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AMyGameCharacter::AMyGameCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // Camera Boom (spring arm component)
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 300.0f; // Set the camera distance
    CameraBoom->bUsePawnControlRotation = true;

    // Camera Component
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    CameraComponent->SetupAttachment(CameraBoom);

    // Character Rotation
    bUseControllerRotationYaw = false;
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
}

// Called when the game starts
void AMyGameCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AMyGameCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Bind functionality to user input
void AMyGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
