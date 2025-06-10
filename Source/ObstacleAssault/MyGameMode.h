#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class OBSTACLEASSAULT_API AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    virtual void BeginPlay() override;

protected:
UPROPERTY(EditAnywhere, Category="Audio")
    USoundCue* BackgroundMusic;

private:
    UAudioComponent* AudioComponent;
};
