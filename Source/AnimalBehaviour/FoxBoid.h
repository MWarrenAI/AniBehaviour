
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "BoidManager.h"
#include "FoxBoid.generated.h"

UCLASS()
class ANIMALBEHAVIOUR_API AFoxBoid : public AActor
{
	GENERATED_BODY()
	
public:	
	AFoxBoid();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	FVector foxVelocity;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FoxFollow")
	AActor* FoxFollow;

	UPROPERTY(EditAnywhere)
	float foxSeperation;

	UPROPERTY(EditAnywhere)
	float foxCohesion;

	UPROPERTY(EditAnywhere)
	float foxWeight;

	FVector foxSpeedUp;
	FVector foxOffset;
	FVector foxCenter;
	FVector foxAvoidance;
	FVector foxAverage;

	void Turn(FVector vector);

protected:
	void Steer(float DeltaTime);
	//void WithinBoundary();

	ABoidManager* BoidManager;
};
