// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSprite.h"
#include "PWCityActor.generated.h"

class UPaperSpriteComponent;

UCLASS()
class PYRRHICWAR_API APWCityActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APWCityActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Components")
    UPaperSpriteComponent* OnMapIconComponent;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};
