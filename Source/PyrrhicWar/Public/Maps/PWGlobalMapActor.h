// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PWGlobalMapActor.generated.h"

class UPaperSpriteComponent;

DECLARE_MULTICAST_DELEGATE(FGlobalMapIsClicked)

UCLASS()
class PYRRHICWAR_API APWGlobalMapActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APWGlobalMapActor();

    //FGlobalMapIsClicked GlobalMapIsClicked;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Components")
    UPaperSpriteComponent* IconComponent;

    FGlobalMapIsClicked GlobalMapIsClicked;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void OnCliked(UPrimitiveComponent* ClickedComponent, FKey ButtonPressed);
};
