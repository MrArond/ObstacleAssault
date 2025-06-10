#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
	GetWorldTimerManager().SetTimer(MyTimerHandle, this, &AMovingPlatform::RotatingPlatform, Time, true);
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	FString Name = GetName();
	UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *Name);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

	// ZMIANA: płynne obracanie gdy aktywne
	if (bIsRotating)
	{
		RotationElapsed += DeltaTime;
		float Alpha = FMath::Clamp(RotationElapsed / RotationDuration, 0.0f, 1.0f);

		FRotator NewRotation = FMath::Lerp(RotationStart, RotationTarget, Alpha);
		SetActorRotation(NewRotation);

		if (Alpha >= 1.0f)
		{
			bIsRotating = false;
		}
	}
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReturn())
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = GetActorLocation();
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		AddActorWorldOffset(PlatformVelocity * DeltaTime);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorWorldRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

void AMovingPlatform::RotatingPlatform()
{
	if (DoesPlatformRotate && !bIsRotating) // ZMIANA: jeśli nie trwa już obrót
	{
		int32 Direction = FMath::RandRange(1,2);

		RotationElapsed = 0.0f;
		bIsRotating = true;

		RotationStart = GetActorRotation();
		switch(Direction)
		{
			case 1: RotationTarget = RotationStart + FRotator(90.0f, 0 , 0);
			break;
			case 2: RotationTarget = RotationStart + FRotator(-90.0f, 0 , 0);
			break;
		} 
	}
}
