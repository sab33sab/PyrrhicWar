// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "PWRoadActor.generated.h"


UCLASS()
class PYRRHICWAR_API APWRoadActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APWRoadActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Components")
    USplineComponent* Spline;

public:

};
