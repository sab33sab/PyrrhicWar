// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#include "Units/Components/PWArmyTroopsComponent.h"
#include "Kismet/KismetMathLibrary.h"

DEFINE_LOG_CATEGORY_STATIC(LogArmyTroopsComponent, All, All)

// Sets default values for this component's properties
UPWArmyTroopsComponent::UPWArmyTroopsComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = false;
}

void UPWArmyTroopsComponent::BeginPlay()
{
    Super::BeginPlay();

    SetStartTroops();
    PrintArmyData();
}

void UPWArmyTroopsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPWArmyTroopsComponent::SetStartTroops()
{
    UE_LOG(LogArmyTroopsComponent, Display, TEXT("======================"));

    for (int32 TroopIndex = 0; TroopIndex < NumberTroopsInArmy; ++TroopIndex)
    {
        switch (UKismetMathLibrary::RandomInteger(5))
        {
            case 0:
                //TroopsInArmy.Add(FTroopsInitializationList::Sarissophore);
                TroopsInArmy.Add(Sarissophore);
                UE_LOG(LogArmyTroopsComponent, Display, TEXT("Add Sarissophore in army"));
                break;
            case 1:
                TroopsInArmy.Add(Hoplite);
                UE_LOG(LogArmyTroopsComponent, Display, TEXT("Add Hoplite in army"));
                break;
            case 2:
                TroopsInArmy.Add(Peltast);
                UE_LOG(LogArmyTroopsComponent, Display, TEXT("Add Peltast in army"));
                break;
            case 3:
                TroopsInArmy.Add(ThessalianCavalry);
                UE_LOG(LogArmyTroopsComponent, Display, TEXT("Add ThessalianCavalry in army"));
                break;
            case 4:
                TroopsInArmy.Add(Elephant);
                UE_LOG(LogArmyTroopsComponent, Display, TEXT("Add Elephant in army"));
                break;
        }
    }
}

/*
ETroopNames UPWArmyTroopsComponent::GetRandomTypeTroop()
{
    int32 MAX_TROOP_NAMES = ETroopNames::MAX_TROOP_NAMES - 1;
    ETroopNames RandomTroopName = StaticCast<ETroopNames>((MAX_TROOP_NAMES));

    UE_LOG(LogArmyTroopsComponent, Display, TEXT("RandomTroopName: %s"), *FString::FromInt(RandomTroopName));

    return RandomTroopName;
}
*/

void UPWArmyTroopsComponent::PrintArmyData()
{
    UE_LOG(LogArmyTroopsComponent, Warning, TEXT("======Army data======"));
    UE_LOG(LogArmyTroopsComponent, Warning, TEXT("There is %i troops in army"), TroopsInArmy.Num());
    for (const auto Troop : TroopsInArmy)
    {
        UE_LOG(LogArmyTroopsComponent, Warning, TEXT("%s"), *Troop.TroopType);
    }
}