// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#include "Units/PWTroopActor.h"
#include "CoreMinimal.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "Kismet/GamePlayStatics.h"
#include "Engine/DataTable.h"
//#include "PWHubActor.h"

DEFINE_LOG_CATEGORY_STATIC(LogPWTroopActor, All, All);

struct FTroopData;

// Sets default values
APWTroopActor::APWTroopActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    OnMapIconComponent = CreateDefaultSubobject<UPaperSpriteComponent>("OnMapIconComponent");
    OnMapIconComponent->SetupAttachment(GetRootComponent());

    static ConstructorHelpers::FObjectFinder<UDataTable> TroopsDataTable(TEXT("DataTable'/Game/Data/TroopsData.TroopsData'"));
    if (TroopsDataTable.Succeeded()) { TroopsData = TroopsDataTable.Object; }
}

// Called when the game starts or when spawned
void APWTroopActor::BeginPlay()
{
    Super::BeginPlay();

    OnMapIconComponent->OnClicked.AddDynamic(this, &APWTroopActor::OnSelected);

    //HubActor->SetSelectActor(this);
}

// Called every frame
void APWTroopActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APWTroopActor::OnSelected(UPrimitiveComponent* ClickedComponent, FKey ButtonPressed)
{
    UE_LOG(LogPWTroopActor, Display, TEXT("Troop is cliked"));
    //HubActor->PrintSelectActorInfo();
}

void APWTroopActor::SetOnMapIcon(ETroopType TroopType)
{
    if (!TroopsData) return;

    FName CreatedType;

    switch (TroopType)
    {
        case ETroopType::Sarissophore: CreatedType = "Sarissophore"; break;
        case ETroopType::Hoplite: CreatedType = "Hoplite"; break;
        case ETroopType::Peltast: CreatedType = "Peltast"; break;
        case ETroopType::ThessalianCavalry: CreatedType = "ThessalianCavalry"; break;
        case ETroopType::Elephants: CreatedType = "Elephants"; break;
        default: CreatedType = "MAX_TYPES"; break;
    }

    static const FString ContextString(TEXT("Troop Data Context"));
    FTroopData* CreatedTroopData= TroopsData->FindRow<FTroopData>(CreatedType, ContextString, true);
    if (!CreatedTroopData) return;
    UPaperSprite* Icon = CreatedTroopData->OnMapIcon;
    OnMapIconComponent->SetSprite(Icon);
}