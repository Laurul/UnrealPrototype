// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core.h"
#include "CoreUObject.h"
#include "CoreMinimal.h"
#include "Engine.h"

#include "InputCore.h"
#include "UMG.h"

#include "Slate.h"
#include "SlateCore.h"
#include "GameFramework/Pawn.h"

#include "PlayerPawn.generated.h"


UCLASS()
class TRAINGAME_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Amount);
	void MoveRight(float Amount);
	void SwitchLeft();
	void SwitchRight();
	void CloseGame();

	void DoOnce();
	void OnTouchBegin(ETouchIndex::Type touchType, FVector newTouchLocation);

	class UFloatingPawnMovement* m_floatingPawnMovement;


	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* StaticMesh;


	UPROPERTY(EditAnywhere, Category = "Components")
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		TArray<AActor*> ActorsToManage;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float PitchValue;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float YawValue;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float RollValue;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	//	TSubclassOf<UUserWidget> WidgetBPReference;

	//UUserWidget* WidgetInstance;

	UPROPERTY(BlueprintReadWrite)
		float passangerMeter;

	UFUNCTION(BlueprintCallable)
		void PressedTrue();
	UFUNCTION(BlueprintCallable)
		void PressedFalse();
	UFUNCTION(BlueprintCallable)
		void Redress();

private:
	FTimerHandle timerHandle;
	int currentTrack = 0;
	bool moveRight = false;
	bool moveLeft = false;
	APlayerController* playerController;
	FVector2D TouchStart2dVector;
	FVector2D TouchEnd2dVector;
	bool isPressed = false;
	FVector2D subtractStartEnd;
	FVector2D currentTouch;
	FVector2D subtract;

};
