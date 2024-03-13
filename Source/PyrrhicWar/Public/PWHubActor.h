// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PWCoreTypes.h"
#include "PWHubActor.generated.h"

class APWTroopActor;

UCLASS()
class PYRRHICWAR_API APWHubActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APWHubActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere)
    TSubclassOf<APWTroopActor> TroopClass;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "TroopData")
    ETroopType CreatedType = ETroopType::MAX_TYPES;

    // AActor* SelectActor = nullptr;

    void GenerateStartActors();

public:

    // void SetSelectActor(AActor* Actor) { SelectActor = Actor; }
    // AActor* GetSelectActor() { return SelectActor; }

    // void PrintSelectActorInfo();
};
