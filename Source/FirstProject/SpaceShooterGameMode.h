// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpaceShooterGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECT_API ASpaceShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

		float MINIMUM_INTERVAL = 0.5f;
		float MAXIMUM_INTERVAL = 2.0f;
		float TIME_TO_MINIMUM_INTERVAL = 30.0f;

	public:
		virtual void BeginPlay() override;

		virtual void Tick(float DeltaTime) override;

		void IncrementScore();

		UPROPERTY(EditAnywhere, Category = "Spawning")
			TSubclassOf<class AEnemyController> EnemyBlueprint;

		float EnemyTimer;
		float GameTimer;

	protected:
		int score = 0;
};
