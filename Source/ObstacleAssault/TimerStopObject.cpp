#include "TimerStopObject.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerHUD.h"
#include "Engine/World.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

// Prototyp funkcji zapisu
void SaveTimeToFile(float TimeElapsed);

ATimerStopObject::ATimerStopObject()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ATimerStopObject::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ATimerStopObject::OnOverlapEnd);

	bIsInHitbox = false;
}

void ATimerStopObject::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
									   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
									   const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		ATimerHUD* MyHUD = Cast<ATimerHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
		if (MyHUD)
		{
			MyHUD->PauseTime(true);
			SaveTimeToFile(MyHUD->GetTimeElapsed());
		}
	}
}

void ATimerStopObject::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
									 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// Pusto, bo nie chcesz wznawiać czasu
}

void ATimerStopObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void SaveTimeToFile(float TimeElapsed)
{
	FString FilePath = FPaths::ProjectDir() + "SavedTimes.txt";
	FString TimeText = FString::Printf(TEXT("Czas: %.2f\n"), TimeElapsed);
	FFileHelper::SaveStringToFile(TimeText, *FilePath);
}
