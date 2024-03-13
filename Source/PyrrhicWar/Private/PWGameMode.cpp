// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#include "PWGameMode.h"
#include "Player/PWPlayerCameraPawn.h"
#include "Player/PWPlayerController.h"
#include "UI/PWGameHUD.h"

APWGameMode::APWGameMode()
{
    DefaultPawnClass = APWPlayerCameraPawn::StaticClass();
    PlayerControllerClass = APWPlayerController::StaticClass();
    HUDClass = APWGameHUD::StaticClass();
}
