// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#include "Player/PWPlayerCameraPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetMathLibrary.h"

DEFINE_LOG_CATEGORY_STATIC(LogPlayerCameraPawn, All, All)

APWPlayerCameraPawn::APWPlayerCameraPawn()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
    RootComponent = StaticMeshComponent;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);

    SetActorLocation(StartCameraPosition);
}

void APWPlayerCameraPawn::BeginPlay()
{
    Super::BeginPlay();

    // SetActorLocation(StartCameraPosition);
}

void APWPlayerCameraPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    SetCamera();
}

void APWPlayerCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APWPlayerCameraPawn::SetCamera()
{
    if (!GetWorld()) return;

    FVector2D MousePosition;
    GetWorld()->GetGameViewport()->GetMousePosition(MousePosition);

    FVector2D ViewportSize;
    GetWorld()->GetGameViewport()->GetViewportSize(ViewportSize);

    if (MousePosition.X <= 0.001 && MousePosition.Y <= 0.001) return;

    //UE_LOG(LogPlayerCameraPawn, Display, TEXT("MousePosition: %s"), *MousePosition.ToString());

    if (MousePosition.X < ViewportSize.X * 0.05f) CameraMoveLeft(MousePosition, ViewportSize);
    if (MousePosition.X > ViewportSize.X * 0.95f) CameraMoveRight(MousePosition, ViewportSize);
    if (MousePosition.Y < ViewportSize.Y * 0.05f) CameraMoveUp(MousePosition, ViewportSize);
    if (MousePosition.Y > ViewportSize.Y * 0.95f) CameraMoveDown(MousePosition, ViewportSize);
    return;
}

void APWPlayerCameraPawn::CameraMoveLeft(FVector2D MousePosition, FVector2D ViewportSize)
{
    float NormalizeMousePosition;
    NormalizeMousePosition = UKismetMathLibrary::NormalizeToRange(MousePosition.X, 0.0f, ViewportSize.X * BorderOfScreenMovement);

    float CameraSpeedDecline;
    CameraSpeedDecline = 1 - UKismetMathLibrary::FClamp(NormalizeMousePosition, 0.0f, 1.0f);

    FVector CameraPosition;
    CameraPosition = GetActorLocation();

    CameraPosition.Y =
        UKismetMathLibrary::FClamp((CameraPosition.Y - CameraSpeed * CameraSpeedDecline), -GlobalMapSize.Y / 2, GlobalMapSize.Y / 2);
    
    /*
    FString CalledFunction = "CameraMoveLeft";
    PrintLog(CalledFunction, MousePosition, ViewportSize, NormalizeMousePosition, CameraSpeedDecline, CameraPosition);
        */

    SetActorLocation(CameraPosition);

    return;
}

void APWPlayerCameraPawn::CameraMoveRight(FVector2D MousePosition, FVector2D ViewportSize)
{
    float NormalizeMousePosition;
    NormalizeMousePosition =
        UKismetMathLibrary::NormalizeToRange(MousePosition.X, ViewportSize.X * (1 - BorderOfScreenMovement), ViewportSize.X);

    float CameraSpeedDecline;
    CameraSpeedDecline = UKismetMathLibrary::FClamp(NormalizeMousePosition, 0.0f, 1.0f);

    FVector CameraPosition;
    CameraPosition = GetActorLocation();

    CameraPosition.Y =
        UKismetMathLibrary::FClamp((CameraPosition.Y + CameraSpeed * CameraSpeedDecline), -GlobalMapSize.Y / 2, GlobalMapSize.Y / 2);

    /*
    FString CalledFunction = "CameraMoveRight";
    PrintLog(CalledFunction, MousePosition, ViewportSize, NormalizeMousePosition, CameraSpeedDecline, CameraPosition);
        */

    SetActorLocation(CameraPosition);

    return;
}

void APWPlayerCameraPawn::CameraMoveUp(FVector2D MousePosition, FVector2D ViewportSize)
{
    float NormalizeMousePosition;
    NormalizeMousePosition = UKismetMathLibrary::NormalizeToRange(MousePosition.Y, 0.0f, ViewportSize.Y * BorderOfScreenMovement);

    float CameraSpeedDecline;
    CameraSpeedDecline = 1 - UKismetMathLibrary::FClamp(NormalizeMousePosition, 0.0f, 1.0f);

    FVector CameraPosition;
    CameraPosition = GetActorLocation();

    CameraPosition.Z =
        UKismetMathLibrary::FClamp((CameraPosition.Z + CameraSpeed * CameraSpeedDecline), -GlobalMapSize.X / 2, GlobalMapSize.X / 2);

    /*
    FString CalledFunction = "CameraMoveUp";
    PrintLog(CalledFunction, MousePosition, ViewportSize, NormalizeMousePosition, CameraSpeedDecline, CameraPosition);
       */

    SetActorLocation(CameraPosition);

    return;
}

void APWPlayerCameraPawn::CameraMoveDown(FVector2D MousePosition, FVector2D ViewportSize)
{
    if (MousePosition.Y < ViewportSize.Y * (1 - BorderOfScreenMovement)) return;

    float NormalizeMousePosition;
    NormalizeMousePosition =
        UKismetMathLibrary::NormalizeToRange(MousePosition.Y, ViewportSize.Y * (1 - BorderOfScreenMovement), ViewportSize.Y);

    float CameraSpeedDecline;
    CameraSpeedDecline = UKismetMathLibrary::FClamp(NormalizeMousePosition, 0.0f, 1.0f);

    FVector CameraPosition;
    CameraPosition = GetActorLocation();

    CameraPosition.Z =
        UKismetMathLibrary::FClamp((CameraPosition.Z - CameraSpeed * CameraSpeedDecline), -GlobalMapSize.X / 2, GlobalMapSize.X / 2);

    /*
    FString CalledFunction = "CameraMoveDown";
    PrintLog(CalledFunction, MousePosition, ViewportSize, NormalizeMousePosition, CameraSpeedDecline, CameraPosition);
        */

    SetActorLocation(CameraPosition);

    return;
}

/*
void APWPlayerCameraPawn::PrintLog(FString CalledFunction, FVector2D MousePosition, FVector2D ViewportSize, float NormalizeMousePosition,
    float CameraSpeedDecline, FVector CurrentCameraPosition)
{
    UE_LOG(LogPlayerCameraPawn, Display, TEXT("                                 "));
    UE_LOG(LogPlayerCameraPawn, Display, TEXT("=======CalledFunction: %s========"), *CalledFunction);
    UE_LOG(LogPlayerCameraPawn, Display, TEXT("MousePosition: %s"), *MousePosition.ToString());
    UE_LOG(LogPlayerCameraPawn, Display, TEXT("ViewportSize: %s"), *ViewportSize.ToString());
    UE_LOG(LogPlayerCameraPawn, Display, TEXT("NormalizeMousePosition: %f"), NormalizeMousePosition);
    UE_LOG(LogPlayerCameraPawn, Display, TEXT("CameraSpeedDecline: %f"), CameraSpeedDecline);
    UE_LOG(LogPlayerCameraPawn, Display, TEXT("CurrentCameraPosition: %s"), *CurrentCameraPosition.ToString());
}
*/