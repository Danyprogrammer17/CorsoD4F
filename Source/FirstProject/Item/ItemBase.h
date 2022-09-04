// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

UCLASS()
class FIRSTPROJECT_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();
	virtual void Tick(float DeltaTime) override;

	int addXP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int score;
	bool flag;
	FString description;
	int xp;

	void ShowLogs();
	void addScore(int points);

private:	
	// Called every frame
	

};
