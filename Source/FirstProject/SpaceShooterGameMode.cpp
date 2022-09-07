// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceShooterGameMode.h"
#include "EnemyController.h"

void ASpaceShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ASpaceShooterGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GameTimer += DeltaTime;
	EnemyTimer -= DeltaTime;

	UE_LOG(LogTemp, Warning, TEXT("EnemyTimer: %f"), EnemyTimer);
	if (EnemyTimer <= 0.0f)
	{
		float difficultyPercentage = FMath::Min(GameTimer / TIME_TO_MINIMUM_INTERVAL, 1.0f);
		EnemyTimer = MAXIMUM_INTERVAL - (MAXIMUM_INTERVAL - MINIMUM_INTERVAL) * difficultyPercentage;

		UE_LOG(LogTemp, Warning, TEXT("Time is %f"), EnemyTimer);
		UWorld* World = GetWorld();

		if (World)
		{
			FVector location = FVector(2952.0f, FMath::RandRange(570.0f, 2850.0f), 100.0f);
			UE_LOG(LogTemp, Error, TEXT("Location: %f"), location.X);
			World->SpawnActor<AEnemyController>(EnemyBlueprint, location, FRotator::ZeroRotator);
		}
	}
}

void ASpaceShooterGameMode::IncrementScore()
{
	score += 100;
}
