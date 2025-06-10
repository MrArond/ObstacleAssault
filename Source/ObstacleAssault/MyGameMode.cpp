#include "MyGameMode.h"

void AMyGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (BackgroundMusic)
    {
        AudioComponent = NewObject<UAudioComponent>(this);
        AudioComponent->bAutoActivate = false;
        AudioComponent->SetSound(BackgroundMusic);
        AudioComponent->RegisterComponent();
        AudioComponent->Play();
    }
}
