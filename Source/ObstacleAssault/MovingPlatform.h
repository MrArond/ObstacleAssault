#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector PlatformVelocity = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float MoveDistance = 100;

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	bool DoesPlatformRotate = false;

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	int Time = 0;
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float dmg = 0;

	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity;



	FVector StartLocation;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;

	FTimerHandle MyTimerHandle;

	void RotatingPlatform();

	// ZMIANA: zmienne do płynnego obrotu
	bool bIsRotating = false;                        // czy trwa obrót
	FRotator RotationStart;                          // początek obrotu
	FRotator RotationTarget;                         // koniec obrotu
	float RotationElapsed = 0.0f;                    // czas od rozpoczęcia
	float RotationDuration = 0.5f;                   // ile ma trwać obrót (sekundy)
};
