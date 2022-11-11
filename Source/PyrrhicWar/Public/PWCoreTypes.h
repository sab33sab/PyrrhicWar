#pragma once

//#include "Units/PWTroopActor.h"
#include "PaperSprite.h"
#include "Engine/DataTable.h"
#include "PWCoreTypes.generated.h"


USTRUCT(BlueprintType)
struct FTroopDataTemp
{
    GENERATED_USTRUCT_BODY()

    FString TroopType;
    int32 MaxSpeed;
    int32 CurrentNumber;
};

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