// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPawn.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"
#include "Camera//CameraComponent.h"

// Sets default values
ACustomPawn::ACustomPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_floatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	Camera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	Camera->SetRelativeLocation(FVector(-500.0f, 0.0f, 0.0f));
	Camera->SetupAttachment(StaticMesh);
	SetRootComponent(StaticMesh);
}

// Called when the game starts or when spawned
void ACustomPawn::BeginPlay()
{
	Super::BeginPlay();

	StaticMesh->SetRelativeLocation(ActorsToManage[currentTrack]->GetActorLocation());


}

void ACustomPawn::MoveForward(float Amount)
{
	
//	m_floatingPawnMovement->AddInputVector(GetActorForwardVector() * Amount);

}

void ACustomPawn::MoveRight(float Amount)
{

	//m_floatingPawnMovement->AddInputVector(GetActorRightVector() * Amount);
	
}

void ACustomPawn::SwitchLeft()
{
	if (currentTrack > 0) {
		currentTrack--;
		StaticMesh->SetRelativeLocation(ActorsToManage[currentTrack]->GetActorLocation());

	}


}

void ACustomPawn::SwitchRight()
{
	if (currentTrack < ActorsToManage.Num()-1) {
		currentTrack++;
		StaticMesh->SetRelativeLocation(ActorsToManage[currentTrack]->GetActorLocation());

	}

}

// Called every frame
void ACustomPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	m_floatingPawnMovement->AddInputVector(FVector(0.1f, 0, 0));

	
		


}

// Called to bind functionality to input
void ACustomPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ACustomPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACustomPawn::MoveRight);
	PlayerInputComponent->BindAction("SwitchLeft", IE_Pressed, this, &ACustomPawn::SwitchLeft);
	PlayerInputComponent->BindAction("SwitchRight", IE_Pressed, this, &ACustomPawn::SwitchRight);
	//PlayerInputComponent->BindAction("SwitchRight", IE_Pressed, this, &ACustomPawn::SwitchRight);
}

