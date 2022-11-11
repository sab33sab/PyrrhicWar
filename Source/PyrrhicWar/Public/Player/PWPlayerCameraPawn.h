// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PWPlayerCameraPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;

UCLASS()
class PYRRHICWAR_API APWPlayerCameraPawn : public APawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    APWPlayerCameraPawn();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* StaticMeshComponent;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Camera")
    float CameraSpeed = 20.0f;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Camera")
    FVector2D GlobalMapSize{1000, 1000};

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Camera")
    float BorderOfScreenMovement = 0.05f;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Camera")
    FVector StartCameraPosition = {0.0f, 0.0f, 0.0f};

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void SetCamera();
    void CameraMoveLeft(FVector2D MousePosition, FVector2D ViewportSize);
    void CameraMoveRight(FVector2D MousePosition, FVector2D ViewportSize);
    void CameraMoveUp(FVector2D MousePosition, FVector2D ViewportSize);
    void CameraMoveDown(FVector2D MousePosition, FVector2D ViewportSize);

    /*
    void PrintLog(FString CalledFunction, FVector2D MousePosition, FVector2D ViewportSize, float NormalizeMousePosition,
        float CameraSpeedDecline, FVector CurrentCameraPosition);
        */
};
