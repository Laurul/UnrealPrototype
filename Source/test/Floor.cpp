// Fill out your copyright notice in the Description page of Project Settings.


#include "Floor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFloor::AFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	track = CreateDefaultSubobject<UStaticMeshComponent>("Track");
	track->SetWorldScale3D(FVector(10.0f, 1.0f, 0.2f));
	//floor = CreateDefaultSubobject<UBoxComponent>("Floor");
}

// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();
	
	//	floor->SetWorldScale3D(FVector(10.0f, 1.0f, 0.2f));
	
}

// Called every frame
void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

