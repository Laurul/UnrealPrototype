// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CustomPawn.generated.h"

UCLASS()
class TEST_API ACustomPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACustomPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Amount);
	void MoveRight(float Amount);
	void SwitchLeft();
	void SwitchRight();



	class UFloatingPawnMovement* m_floatingPawnMovement;


	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* StaticMesh;

	
	UPROPERTY(EditAnywhere, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	TArray<AActor*> ActorsToManage;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	int currentTrack = 0;
	bool moveRight = false;
	bool moveLeft=false;
};
