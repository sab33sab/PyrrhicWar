// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#include "Units/PWArmyActor.h"
#include "PaperSpriteComponent.h"
#include "Units/Components/PWArmyTroopsComponent.h"

// Sets default values
APWArmyActor::APWArmyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    ArmyIconComponent = CreateDefaultSubobject<UPaperSpriteComponent>("ArmyIconComponent");
    //ArmyIconComponent->SetupAttachment();

    ArmyTroopsComponent = CreateDefaultSubobject<UPWArmyTroopsComponent>("ArmyTroopsComponent");
}

void APWArmyActor::BeginPlay()
{
    Super::BeginPlay();
}

void APWArmyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
