// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerBoxUI.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"

ATriggerBoxUI::ATriggerBoxUI() {
	OnActorBeginOverlap.AddDynamic(this, &ATriggerBoxUI::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ATriggerBoxUI::OnOverlapEnd);
	PitchValue = 0.0f;
	YawValue = 0.0f;
	RollValue = 0.0f;
}

void ATriggerBoxUI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ATriggerBoxUI::OnOverlapBegin(AActor* OverLappedActor, AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this) && OtherActor == SpecificActor) {
		if (GEngine)
		{

			/*do  {
				FRotator newRotation = FRotator(PitchValue, YawValue, RollValue);
				FQuat qRotation = FQuat(newRotation);
				OtherActor->AddActorLocalRotation(qRotation, false, 0, ETeleportType::None);
			} while (OtherActor->GetActorRotation().Yaw < 20);*/
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Blue, TEXT("Overlap Begin"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Overlapping Actor = %s"), *OverLappedActor->GetName()));
		}
	}
}

void ATriggerBoxUI::OnOverlapEnd(AActor* OverLappedActor, AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this) && OtherActor == SpecificActor) {
		if (GEngine)
		{

			//FRotator newRotation = FRotator(PitchValue, YawValue * -1.0f, RollValue);
			//FQuat qRotation = FQuat(newRotation);
			//do {
			//	
			//	OtherActor->AddActorLocalRotation(qRotation, false, 0, ETeleportType::None);
			//} while (OtherActor->GetActorRotation().Yaw >0);
			//if ((OtherActor->GetActorRotation().Yaw < 0)) {
			//	newRotation= FRotator(PitchValue, OtherActor->GetActorRotation().Yaw *-1.0f, RollValue);
			//	qRotation = FQuat(newRotation);
			//	OtherActor->AddActorLocalRotation(qRotation, false, 0, ETeleportType::None);
			// }
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Blue, TEXT("Overlap Ended"));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("%s has left the Trigger Box"), *OtherActor->GetName()));
		}
	}
}

void ATriggerBoxUI::BeginPlay() {
	Super::BeginPlay();
	//playerToManage=UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Blue, true, -1, 0, 5);
}

