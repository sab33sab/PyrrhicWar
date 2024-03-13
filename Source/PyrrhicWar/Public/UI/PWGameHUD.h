// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PWGameHUD.generated.h"

class APWCityActor;

/**
 *
 */

UCLASS()
class PYRRHICWAR_API APWGameHUD : public AHUD
{
    GENERATED_BODY()

protected:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    APWCityActor* CurrentCityShownUI = NULL;

public:
    //void CityShownUI(APWCityActor* City) { CurrentCityShownUI = City; }
    void CityShownUI(APWCityActor* City);
    //void GlobalMapIsClicked();
    void MouseRightClickEvent();
};
