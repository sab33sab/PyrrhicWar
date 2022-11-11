// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#include "PWHubActor.h"
#include "Units/PWTroopActor.h"
#include "Engine/World.h"

//DEFINE_LOG_CATEGORY_STATIC(LogPWHubActor, All, All);

//class APWTroopActor;

// Sets default values
APWHubActor::APWHubActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void APWHubActor::BeginPlay()
{
    Super::BeginPlay();

    GenerateStartActors();
}

// Called every frame
void APWHubActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

//Generated started Trops, Leginos and Armies, inicialisated its, and set its on the GlobalMap
void APWHubActor::GenerateStartActors()
{
    FTransform Transform = FTransform(FRotator(0.0f, 90.0f, 0.0f), FVector(0.0f, 0.0f, 0.0f));
    CreatedType = ETroopType::Sarissophore;

    UWorld* World = GetWorld();
    if (World) 
    { 
        APWTroopActor* Troop = World->SpawnActor<APWTroopActor>(TroopClass, Transform);
        Troop->SetOnMapIcon(CreatedType);
        //Troop->SetHubActor(this);
    }
}

/*
void APWHubActor::PrintSelectActorInfo() 
{
    APWTroopActor* SelectTroop = Cast<APWTroopActor>(SelectActor);
    UE_LOG(LogPWHubActor, Display, TEXT("Select Actor's name's %s"), *SelectTroop->GetName());
}
*/