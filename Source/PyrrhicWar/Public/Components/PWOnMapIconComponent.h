// Blood And Sweat. Pyrrhic War. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteComponent.h"
#include "PWOnMapIconComponent.generated.h"

class APWCityActor;

/**
 *
 */
UCLASS()
class PYRRHICWAR_API UPWOnMapIconComponent : public UPaperSpriteComponent
{
    GENERATED_BODY()

public:

    void OnBeginCursorOver(AActor* Actor) {}
    void OnEndCursorOver(AActor* Actor) {}

    //void BeginCursorOver(AActor* Actor) {}
    //void EndCursorOver(AActor* Actor) {}

    UFUNCTION()
    void ShowOutline(AActor* Actor);

    UFUNCTION()
    void HideOutline(AActor* Actor);

    UFUNCTION()
    void ShowAdditionalIcons(AActor* Actor);

    UFUNCTION()
    void HideAdditionalIcons(AActor* Actor);

    virtual void BeginPlay() override;

};
