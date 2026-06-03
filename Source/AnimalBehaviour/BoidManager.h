#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoidManager.generated.h"

UCLASS()
class ANIMALBEHAVIOUR_API ABoidManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ABoidManager();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(EditAnywhere)
	float foxMinSpeed;

	UPROPERTY(EditAnywhere)
	float foxMaxSpeed;

	UPROPERTY(EditAnywhere)
	float foxRadius;

	UPROPERTY(EditAnywhere)
	float foxWeight;

public:
	float GetfoxMinSpeed();
	float GetfoxMaxSpeed();
	float GetfoxRadius();
};
