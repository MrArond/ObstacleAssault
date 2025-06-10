
#include "MainCharacterWidget.h"
#include "Components/ProgressBar.h"
void UMainCharacterWidget::SetHealth(float CurrentHealth, float MaxHealth)
{
    if (HealthBar)
    {
        HealthBar->SetPercent(CurrentHealth / MaxHealth);
    }
    
}

