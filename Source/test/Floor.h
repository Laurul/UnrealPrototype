// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floor.generated.h"

UCLASS()
class TEST_API AFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloor();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UBoxComponent* floor;

	UPROPERTY(EditAnywhere, Category = "Components")
		UStaticMeshComponent* track;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
