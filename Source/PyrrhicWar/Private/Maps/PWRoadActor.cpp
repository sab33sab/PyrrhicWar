// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#include "Maps/PWRoadActor.h"

// Sets default values
APWRoadActor::APWRoadActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    Spline = CreateDefaultSubobject<USplineComponent>("Spline");
    Spline->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void APWRoadActor::BeginPlay()
{
    Super::BeginPlay();
}
