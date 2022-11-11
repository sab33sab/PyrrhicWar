// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Units/PWTroopActor.h"
#include "PWCoreTypes.h"
#include "PWHubActor.generated.h"

class APWTroopActor;
//enum class ETroopType : uint8;

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
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // void SetSelectActor(AActor* Actor) { SelectActor = Actor; }
    // AActor* GetSelectActor() { return SelectActor; }

    // void PrintSelectActorInfo();
};
