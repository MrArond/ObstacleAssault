#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class OBSTACLEASSAULT_API UMainCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
UFUNCTION(BlueprintCallable, Category = "HealthBar")
	void SetHealth(float CurrentHealth, float MaxHealth);

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* HealthBar;


};
