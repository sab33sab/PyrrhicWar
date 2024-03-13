// Blood And Sweat. Pyrrhic War. All Rights Reserved.


#include "UI/PWGameHUD.h"
#include "Maps/PWCityActor.h"

DEFINE_LOG_CATEGORY_STATIC(LogPWGameHUD, All, All);

void APWGameHUD::CityShownUI(APWCityActor* City)
{
    CurrentCityShownUI = City;

    UE_LOG(LogPWGameHUD, Display, TEXT("CityShownUI is %s"), *CurrentCityShownUI->GetName());
}

void APWGameHUD::MouseRightClickEvent()
{
    if (!CurrentCityShownUI)
    {
        UE_LOG(LogPWGameHUD, Display, TEXT("No city width shown UI"));
        return;
    }
    else
    {
        UE_LOG(LogPWGameHUD, Display, TEXT("City width shown UI was %s"), *CurrentCityShownUI->GetName());
        CurrentCityShownUI = NULL;
        UE_LOG(LogPWGameHUD, Display, TEXT("And now no city width shown UI"));
    }
}