// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#include "Maps/PWCityActor.h"
#include "Components/PWOnMapIconComponent.h"
#include "UObject/UObjectGlobals.h"

DEFINE_LOG_CATEGORY_STATIC(LogUPWOnMapIconComponent, All, All);

void UPWOnMapIconComponent::BeginPlay()
{
    Super::BeginPlay();

    //AActor* Owner = GetOwner();
    APWCityActor* Owner = Cast<APWCityActor>(GetOwner());
    if (Owner) 
    { 
        SetSprite(Owner->GetData()->GetBaseOnMapIcon());

        Owner->OnBeginCursorOver.AddDynamic(this, &UPWOnMapIconComponent::OnBeginCursorOver);
        Owner->OnEndCursorOver.AddDynamic(this, &UPWOnMapIconComponent::OnEndCursorOver);
    }
}

void UPWOnMapIconComponent::BeginCursorOver(AActor* Actor)
{
    //ShowOutline(Actor);
    UE_LOG(LogUPWOnMapIconComponent, Display, TEXT("Cursor over %s"), *GetName());

    //ShowAdditionalIcons(Actor);

}
void UPWOnMapIconComponent::EndCursorOver(AActor* Actor)
{
    UE_LOG(LogUPWOnMapIconComponent, Display, TEXT("Cursor leave %s"), *GetName());

   //HideAdditionalIcons(Actor);
}


void UPWOnMapIconComponent::ShowOutline(AActor* Actor) 
{
    // auto Data = Actor->GetData();
    // SetSprite(Data->GetSmallOnMapIcon());
}


void UPWOnMapIconComponent::HideOutline(AActor* Actor)
{
    //auto Data = Actor->GetData();
    //SetSprite(Data->GetBaseOnMapIcon());
}

void UPWOnMapIconComponent::ShowAdditionalIcons(AActor* Actor)
{
}

void UPWOnMapIconComponent::HideAdditionalIcons(AActor* Actor)
{
}