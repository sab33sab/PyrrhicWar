// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#include "Maps/PWCityActor.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"

// Sets default values
APWCityActor::APWCityActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    OnMapIconComponent = CreateDefaultSubobject<UPaperSpriteComponent>("OnMapIconComponent");
    OnMapIconComponent->SetupAttachment(GetRootComponent());

    static ConstructorHelpers::FObjectFinder<UPaperSprite> Icon(
        TEXT("PaperSprite'/Game/ExternalContent/City126x100_Sprite.City126x100_Sprite'"));
    if (Icon.Succeeded()) { OnMapIconComponent->SetSprite(Icon.Object); }
}

// Called when the game starts or when spawned
void APWCityActor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void APWCityActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
