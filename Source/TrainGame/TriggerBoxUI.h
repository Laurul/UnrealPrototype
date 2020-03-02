// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "PlayerPawn.h"

#include "TriggerBoxUI.generated.h"

/**
 *
 */
UCLASS()
class TRAINGAME_API ATriggerBoxUI : public ATriggerBox
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

public:
    ATriggerBoxUI();
    virtual void Tick(float DeltaTime) override;
    UFUNCTION(BlueprintCallable)
        void OnOverlapBegin(class AActor* OverLappedActor, class AActor* OtherActor);
    UFUNCTION(BlueprintCallable)
        void OnOverlapEnd(class AActor* OverLappedActor, class AActor* OtherActor);

    UPROPERTY(EditAnywhere)
        class AActor* SpecificActor;
    UPROPERTY(EditAnywhere, Category = "Trigger Behaviour", BlueprintReadWrite)
        bool goRight;
    UPROPERTY(EditAnywhere, Category = "Trigger Behaviour", BlueprintReadWrite)
        bool goLeft;
    UPROPERTY(EditAnywhere, Category = "Trigger Behaviour", BlueprintReadWrite)
        bool beginMinigame;

    UPROPERTY(EditAnywhere, Category = "Movement")
        float PitchValue;
    UPROPERTY(EditAnywhere, Category = "Movement")
        float YawValue;
    UPROPERTY(EditAnywhere, Category = "Movement")
        float RollValue;
    /*   UPROPERTY(EditAnywhere, Category = "Player")
          class PlayerPawn* playerToManage;*/



};
