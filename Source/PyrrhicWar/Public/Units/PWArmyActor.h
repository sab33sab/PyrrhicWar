// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PWArmyActor.generated.h"

class UPaperSpriteComponent;
class UPWArmyTroopsComponent;

UCLASS()
class PYRRHICWAR_API APWArmyActor : public AActor
{
    GENERATED_BODY()

public:
    APWArmyActor();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Components")
    UPaperSpriteComponent* ArmyIconComponent;

    UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Components")
    UPWArmyTroopsComponent* ArmyTroopsComponent;

public:
    virtual void Tick(float DeltaTime) override;
};
