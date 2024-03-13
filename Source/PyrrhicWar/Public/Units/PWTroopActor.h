// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PWCoreTypes.h"
#include "GameFramework/Actor.h"
#include "PaperSprite.h"
#include "Engine/DataTable.h"
#include "PWTroopActor.generated.h"

class UPaperSpriteComponent;

UCLASS()
class PYRRHICWAR_API APWTroopActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APWTroopActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Components")
    UPaperSpriteComponent* OnMapIconComponent;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Data")
    UDataTable* TroopsData;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Data")
    ETroopType Type;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Data")
    int32 CurrentSize;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Data")
    int32 MaxSize;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Data")
    int32 SpeedOnTheMarch;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Data")
    int32 ExperiencePoints;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Data")
    EExperience Experience;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Data")
    EBranch Branch;

    UFUNCTION()
    void OnSelected(UPrimitiveComponent* ClickedComponent, FKey ButtonPressed);

    //APWHubActor* HubActor;

public:

    void SetOnMapIcon(ETroopType Type);

    //void SetHubActor(APWHubActor* Hub) { HubActor = Hub; }
    //const APWHubActor* GetHubActor() { return HubActor; }
};
