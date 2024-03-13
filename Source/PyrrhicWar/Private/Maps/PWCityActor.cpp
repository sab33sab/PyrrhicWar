// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#include "Maps/PWCityActor.h"
#include "PaperSpriteComponent.h"
#include "Components/PWOnMapIconComponent.h"
#include "PaperSprite.h"
#include "UI/PWGameHUD.h"
#include "UI/PWCityUserWidget.h"
#include "Player/PWPlayerCameraPawn.h"
#include "UObject/UObjectGlobals.h"

DEFINE_LOG_CATEGORY_STATIC(LogPWCityActor, All, All);

// Sets default values
APWCityActor::APWCityActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    Data = Cast<UCityDataAsset>(
        StaticLoadObject(UCityDataAsset::StaticClass(), NULL, TEXT("CityDataAsset'/Game/Data/BaseCityData.BaseCityData'")));

    OnMapIcon = CreateDefaultSubobject<UPWOnMapIconComponent>("OnMapIcon");
    OnMapIcon->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void APWCityActor::BeginPlay()
{
    Super::BeginPlay();

    APWGameHUD* HUD = Cast<APWGameHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
    CityShownUI.AddUObject(HUD, &APWGameHUD::CityShownUI);

    APWPlayerCameraPawn* CurrentPawn = Cast<APWPlayerCameraPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
    CityShownUI.AddUObject(CurrentPawn, &APWPlayerCameraPawn::CityShownUI);

    CurrentPawn->HideCityUIWidget.AddUObject(this, &APWCityActor::HideCityUIWidget);
}

void APWCityActor::ShowCityUIWidget(UPrimitiveComponent* ClickedComponent, FKey ButtonPressed)
{
    if (CityShowUI) return;

    UE_LOG(LogPWCityActor, Display, TEXT("City is cliked"));

    CityWidget = CreateWidget<UUserWidget>(GetWorld(), CityWidgetClass);

    if (CityWidget) { CityWidget->AddToViewport(); }

    CityShowUI = true;

    CityShownUI.Broadcast(this);
}

void APWCityActor::HideCityUIWidget()
{
    CityWidget->RemoveFromViewport();
    CityShowUI = false;
}
