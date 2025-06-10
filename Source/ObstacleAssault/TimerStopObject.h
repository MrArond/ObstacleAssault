#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerStopObject.generated.h"

UCLASS()
class OBSTACLEASSAULT_API ATimerStopObject : public AActor
{
	GENERATED_BODY()

public:
	ATimerStopObject();

protected:
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
						class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
						const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
					  class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	class UBoxComponent* CollisionBox;

private:
	bool bIsInHitbox;
};
