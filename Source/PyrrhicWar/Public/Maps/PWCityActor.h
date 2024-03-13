// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/CityDataAsset.h"
#include "PaperSprite.h"
#include "GameFramework/Actor.h"
#include "PWCityActor.generated.h"

class UPaperSpriteComponent;
class UPWOnMapIconComponent;
// class UUserWidget;

DECLARE_MULTICAST_DELEGATE_OneParam(FCityShownUI, APWCityActor*);

UCLASS()
class PYRRHICWAR_API APWCityActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APWCityActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Components")
    UPWOnMapIconComponent* OnMapIcon;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Components")
    UCityDataAsset* Data;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> CityWidgetClass;

    FCityShownUI CityShownUI;

    UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "UI")
    bool CityShowUI = false;

    UUserWidget* CityWidget;

public:
    UFUNCTION()
    void ShowCityUIWidget(UPrimitiveComponent* ClickedComponent, FKey ButtonPressed);

    UFUNCTION()
    void HideCityUIWidget();

    UFUNCTION()
    UCityDataAsset* const GetData() { return Data; }
};
