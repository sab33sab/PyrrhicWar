// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperSprite.h"
#include "Engine/DataAsset.h"
#include "CityDataAsset.generated.h"

/**
 *
 */
UCLASS()
class PYRRHICWAR_API UCityDataAsset : public UDataAsset
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, Category = "Icons")
    UPaperSprite* BaseOnMapIcon;

    UPROPERTY(EditDefaultsOnly, Category = "Icons")
    UPaperSprite* SmallOnMapIcon;

    UPROPERTY(EditDefaultsOnly, Category = "AdditionalIcons")
    TArray<UPaperSprite*> AdditionalIcons;

public:
    UPaperSprite* GetBaseOnMapIcon() { return BaseOnMapIcon; }
    UPaperSprite* GetSmallOnMapIcon() { return SmallOnMapIcon; }
    TArray<UPaperSprite*> GetAdditionalAcons() { return AdditionalIcons; }
};
