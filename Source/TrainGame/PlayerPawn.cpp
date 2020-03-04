// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"
#include "Camera//CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"




// Sets default values
APlayerPawn::APlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_floatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	Camera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	Camera->SetRelativeLocation(FVector(-500.0f, 0.0f, 0.0f));
	Camera->SetupAttachment(StaticMesh);
	SetRootComponent(StaticMesh);
	playerController = UGameplayStatics::GetPlayerController(this, 0);
	

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	StaticMesh->SetRelativeLocation(FVector(this->GetActorLocation().X, ActorsToManage[currentTrack]->GetActorLocation().Y, ActorsToManage[currentTrack]->GetActorLocation().Z + 10));
	passangerMeter = 100.0f;

	/*if (WidgetBPReference) {
		WidgetInstance = CreateWidget<UUserWidget>(this, WidgetBPReference);
		if (WidgetInstance) {
			WidgetInstance->AddToViewport();
		}

	}*/
}

void APlayerPawn::SwitchLeft()
{
	if (currentTrack > 0) {
		currentTrack--;
		StaticMesh->SetRelativeLocation(FVector(this->GetActorLocation().X, ActorsToManage[currentTrack]->GetActorLocation().Y, ActorsToManage[currentTrack]->GetActorLocation().Z + 10));

	}
}

void APlayerPawn::SwitchRight()
{
	if (currentTrack < ActorsToManage.Num() - 1) {
		currentTrack++;
		StaticMesh->SetRelativeLocation(FVector(this->GetActorLocation().X, ActorsToManage[currentTrack]->GetActorLocation().Y, ActorsToManage[currentTrack]->GetActorLocation().Z + 10));

	}
}

void APlayerPawn::PressedTrue()
{
	moveRight = true;
	moveLeft = false;
	/*isPressed = true;
	playerController->GetInputTouchState(ETouchIndex::Touch1, TouchStart2dVector.X, TouchStart2dVector.Y, isPressed);*/
}

void APlayerPawn::PressedFalse()
{
	moveLeft = true;
	moveRight = false;
	//isPressed = false;

}

void APlayerPawn::Redress()
{
	moveRight = false;
	moveLeft = false;
}

APlayerController* APlayerPawn::returnPlayerID()
{
	
	return playerController;
}

void APlayerPawn::DoOnce()
{
	/*if (isPressed == true) {
		playerController->GetInputTouchState(ETouchIndex::Touch1, TouchEnd2dVector.X, TouchEnd2dVector.Y, isPressed);
		subtractStartEnd = TouchStart2dVector - TouchEnd2dVector;

		if (abs(subtractStartEnd.X) > abs(subtractStartEnd.Y)&&GEngine) {
			if (subtractStartEnd.X > 0) {
				GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Blue, TEXT("Swipe Left"));
			}
			else {
				GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Blue, TEXT("Swipe Right"));
			}
		}
		else if (abs(subtractStartEnd.X) < abs(subtractStartEnd.Y) && GEngine) {
			if (subtractStartEnd.Y > 0) {
				GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Blue, TEXT("Swipe Up"));
			}
			else {
				GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Blue, TEXT("Swipe Down"));
			}
		}
	}
	else return;*/
}

void APlayerPawn::OnTouchBegin(ETouchIndex::Type touchType, FVector TouchLocation)
{


}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (passangerMeter > 0.0f) {
		passangerMeter -= 0.01f;
	}
	else if (passangerMeter < 0.0f) {
		passangerMeter = 0.0f;
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Blue, TEXT("NOT WORKING!"));
		}
	}


	m_floatingPawnMovement->AddInputVector(this->GetActorForwardVector() / 1.5f);


	if (moveRight == true) {
		if (YawValue < 0) {
			YawValue *= -1;
		}
		FRotator newRotation = FRotator(PitchValue, YawValue, RollValue);
		FQuat qRotation = FQuat(newRotation);
		if (this->GetActorRotation().Yaw < rotationAngle) {
			this->AddActorLocalRotation(qRotation, false, 0, ETeleportType::None);
			isPressed = true;
		}

	}
	if (moveLeft == true) {
		if (YawValue > 0) {
			YawValue *= -1;
		}
		FRotator newRotation = FRotator(PitchValue, YawValue, RollValue);
		FQuat qRotation = FQuat(newRotation);
		if (this->GetActorRotation().Yaw > -rotationAngle) {
			this->AddActorLocalRotation(qRotation, false, 0, ETeleportType::None);
			isPressed = false;
		}
	}

	if (moveRight == false && moveLeft == false) {
		if (isPressed == true) {
			YawValue = -1.0f;
			FRotator newRotation = FRotator(PitchValue, YawValue, RollValue);
			FQuat qRotation = FQuat(newRotation);
			if (this->GetActorRotation().Yaw > 0) {
				this->AddActorLocalRotation(qRotation, false, 0, ETeleportType::None);
			}
			if (this->GetActorRotation().Yaw < 0) {
				 newRotation = FRotator(0.0f, 0.0f, 0.0f);
				 qRotation = FQuat(newRotation);
				this->SetActorRotation(qRotation, ETeleportType::None);
			}

		}
		if (isPressed == false) {
			YawValue = 1.0f;
			FRotator newRotation = FRotator(PitchValue, YawValue, RollValue);
			FQuat qRotation = FQuat(newRotation);
			if (this->GetActorRotation().Yaw < 0) {
				this->AddActorLocalRotation(qRotation, false, 0, ETeleportType::None);
			}
			if (this->GetActorRotation().Yaw > 0) {
				 newRotation = FRotator(0.0f, 0.0f, 0.0f);
				 qRotation = FQuat(newRotation);
				this->SetActorRotation(qRotation, ETeleportType::None);
			}

		}

	}
	/*if (isPressed == true) {
		playerController->GetInputTouchState(ETouchIndex::Touch1, currentTouch.X, currentTouch.Y, isPressed);
		subtract = TouchStart2dVector - currentTouch;
		if (subtract.Size() > 100.0f) {
			DoOnce();
		}


	}*/

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Right", IE_Pressed, this, &APlayerPawn::PressedTrue);
	PlayerInputComponent->BindAction("Left", IE_Pressed, this, &APlayerPawn::PressedFalse);
	PlayerInputComponent->BindAction("Redress", IE_Pressed, this, &APlayerPawn::Redress);
}



