// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PWCoreTypes.h"
#include "PWArmyTroopsComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PYRRHICWAR_API UPWArmyTroopsComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPWArmyTroopsComponent();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Army Composition")
    TArray<FTroopDataTemp> TroopsInArmy;

    FTroopDataTemp Sarissophore{"Sarissophore", 3, 2};
    FTroopDataTemp Hoplite{"Hoplite", 3, 2};
    FTroopDataTemp Peltast{"Peltast", 3, 2};
    FTroopDataTemp ThessalianCavalry{"ThessalianCavalry", 3, 2};
    FTroopDataTemp Elephant{"Elephant", 3, 2};

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Army Composition")
    int32 NumberTroopsInArmy = 3;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    void SetStartTroops();
    // ETroopNames GetRandomTypeTroop();
    void PrintArmyData();
};