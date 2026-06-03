#include "BoidManager.h"

ABoidManager::ABoidManager()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABoidManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABoidManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ABoidManager::GetfoxMinSpeed()
{
	return foxMinSpeed;
}

float ABoidManager::GetfoxMaxSpeed()
{
	return foxMaxSpeed;
}

float ABoidManager::GetfoxRadius()
{
	return foxRadius;
}

