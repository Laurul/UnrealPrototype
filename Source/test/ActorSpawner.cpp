// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorSpawner.h"
#include "CustomActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components//InputComponent.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"

// Sets default values
AActorSpawner::AActorSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorSpawner::BeginPlay()
{
	Super::BeginPlay();
	UWorld* world = GetWorld();
	if (world) {
		FActorSpawnParameters spawnParams;
		for (int i = 0; i < ActorsToSpawn.Num(); i++) {
			if (ActorsToSpawn[i] != nullptr) {

				world->SpawnActor<AActor>(ActorsToSpawn[i], FVector(-290, 0, 310), FRotator(40, 10, 70));
			}
		}

	}

}

void AActorSpawner::SpawnObject(FVector loc, FRotator rot)
{
	UWorld* world = GetWorld();
	if (world) {
		FActorSpawnParameters spawnParams;
		AActor* SpawnedActorRef = world->SpawnActor<AActor>(ActorsToSpawn[1], loc, rot, spawnParams);
	}
}




// Called every frame
void AActorSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

