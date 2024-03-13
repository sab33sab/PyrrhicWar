// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#include "Maps/PWGlobalMapActor.h"
#include "PaperSpriteComponent.h"
#include "UI/PWGameHUD.h"
#include "PaperSprite.h"

DEFINE_LOG_CATEGORY_STATIC(LogPWGlobalMapActor, All, All);

// Sets default values
APWGlobalMapActor::APWGlobalMapActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    IconComponent = CreateDefaultSubobject<UPaperSpriteComponent>("IconComponent");
    IconComponent->SetupAttachment(GetRootComponent());

    UPaperSprite* GlobalMap = Cast<UPaperSprite>(
        StaticLoadObject(UPaperSprite::StaticClass(), NULL, TEXT("PaperSprite '/Game/ExternalContent/TestMap_Sprite.TestMap_Sprite'")));

    IconComponent->SetSprite(GlobalMap);
}

// Called when the game starts or when spawned
void APWGlobalMapActor::BeginPlay()
{
    Super::BeginPlay();

    IconComponent->OnClicked.AddDynamic(this, &APWGlobalMapActor::OnCliked);

    /*
    APWGameHUD* HUD = Cast<APWGameHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
    GlobalMapIsClicked.AddUObject(HUD, &APWGameHUD::GlobalMapIsClicked);
    UE_LOG(LogPWGlobalMapActor, Display, TEXT("GlobalMap BeginPlay is worked Delegate is Binding"));
    */
}

// Called every frame
void APWGlobalMapActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APWGlobalMapActor::OnCliked(UPrimitiveComponent* ClickedComponent, FKey ButtonPressed)
{
    GlobalMapIsClicked.Broadcast();
    UE_LOG(LogPWGlobalMapActor, Display, TEXT("GlobalMap is cliked"));
}