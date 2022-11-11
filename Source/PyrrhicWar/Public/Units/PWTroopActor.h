// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
//#include "PWHubActor.h"
#include "PWCoreTypes.h"
#include "GameFramework/Actor.h"
#include "PaperSprite.h"
#include "Engine/DataTable.h"
#include "PWTroopActor.generated.h"

class UPaperSpriteComponent;
//class UPWHubActor;
// struct FTroopData;
// enum class ETroopType;
// enum class EExperience;
// enum class EBranch;

/*
UENUM(BlueprintType)
enum class ETroopType : uint8
{
    Sarissophore,
    Hoplite,
    Peltast,
    ThessalianCavalry,
    Elephants,
    MAX_TYPES
};

UENUM(BlueprintType)
enum class EExperience : uint8
{
    Rookie,
    Trained,
    Veteran,
    Elite,
    MAX_EXPERIENCE
};

UENUM(BlueprintType)
enum class EBranch : uint8
{
    LightInfantry,
    HeavyInfantry,
    LightCavalry,
    HeavyCavalry,
    Elephants,
    NONE_BRANCH
};
*/

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
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    void SetOnMapIcon(ETroopType Type);

    //void SetHubActor(APWHubActor* Hub) { HubActor = Hub; }
    //const APWHubActor* GetHubActor() { return HubActor; }
};

/*
USTRUCT(BlueprintType)
struct FTroopData : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TroopData")
    ETroopType Type;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TroopData")
    FString Name;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TroopData")
    UPaperSprite* OnMapIcon;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TroopData")
    int32 CurrentSize;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TroopData")
    int32 MaxSize;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TroopData")
    int32 SpeedOnTheMarch;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TroopData")
    int32 ExperiencePoints;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TroopData")
    EExperience Experience;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TroopData")
    EBranch Branch;
};
*/