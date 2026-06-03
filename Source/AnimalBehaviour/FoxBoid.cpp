#include "FoxBoid.h"

AFoxBoid::AFoxBoid()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AFoxBoid::BeginPlay()
{
	Super::BeginPlay();

	BoidManager = Cast<ABoidManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ABoidManager::StaticClass()));

	FVector foxCurrentLoc = GetActorLocation();
	float LockedZ = foxCurrentLoc.Z;
	foxCurrentLoc.Z = 0.f;
	
	FVector CurrentfoxVel = foxVelocity;
	CurrentfoxVel.Z = 0.f;

	if (CurrentfoxVel.IsNearlyZero())
	{
		CurrentfoxVel = GetActorForwardVector() * 100.f;
	}

	foxVelocity = GetActorForwardVector();
	foxVelocity = foxVelocity.GetSafeNormal();
	foxVelocity *= FMath::RandRange(BoidManager->GetfoxMinSpeed(), BoidManager->GetfoxMaxSpeed());
}

// Called every frame
void AFoxBoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Steer(DeltaTime);
	//WithinBoundary();
}

//void AFoxBoid::Turn(FVector vectorin)
//{
//	FVector foxVelocityAim = vectorin.GetSafeNormal() * BoidManager->GetfoxMaxSpeed();
//	FVector loc = foxVelocityAim - foxVelocity;
//	float foxdist = FVector::Dist()
//}

void AFoxBoid::Steer(float DeltaTime)
{
	FVector foxCurrentLoc = GetActorLocation();
	FRotator foxCurrentRot = GetActorRotation();

	FVector foxSpeed = FVector::ZeroVector;

	TArray<AActor*> FoundHunter;

	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), AActor::StaticClass(), FName("Hunter"), FoundHunter);
	if (FoundHunter.Num() > 0)
	{
		if (USceneComponent* VisualComponent = Cast<USceneComponent>(FoundHunter[0]))
		{
			FVector HunterLoc = VisualComponent->GetComponentLocation();
			foxOffset = (HunterLoc - foxCurrentLoc);

			//foxSpeedUp = Turn(foxOffset) * foxWeight;
			foxCenter /= 3;
			FVector offsetfoxCenter = (foxCenter - foxCurrentLoc);
			//FVector foxAlign = Turn(foxAverage) * foxAlign;
			//FVector foxCoh = Turn(offsetfoxCenter) * foxWeight;
			//FVector foxSep = Turn(foxAvoidance) * foxSeperation;

			//foxVelocity += foxAlign;
			//foxVelocity += foxCoh;
			//foxVelocity += foxSep;

			foxVelocity += foxSpeedUp * DeltaTime;
			//float foxSpeed = foxVelocity.Size();
			//FVector foxDir = foxVelocity / foxSpeed;
			//foxSpeed = FMath::Clamp(foxSpeed, BoidManager->GetfoxMinSpeed(), BoidManager->GetfoxMaxSpeed());
			//foxVelocity = foxDir * foxSpeed;
		}
	}

	/*FVector FoxAcceleration = FVector::ZeroVector;

	foxVelocity += FoxAcceleration + DeltaTime;

	SetActorLocation(GetActorLocation() + (foxVelocity + DeltaTime));*/


}
//void AFoxBoid::WithinBoundary()
//{
//	FVector CurrentLocation = GetActorLocation();
//
//	if (CurrentLocation.X < -2000)
//	{
//		CurrentLocation.X = 2000;
//	}
//
//	else if (CurrentLocation.X > 2000)
//	{
//		CurrentLocation.X = -2000;
//	}
//
//	SetActorLocation(CurrentLocation);
//}

