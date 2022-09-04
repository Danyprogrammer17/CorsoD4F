// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"

// Sets default values
AItemBase::AItemBase() :
	score(12),
	flag(false),
	description("Questa è una descrizione"),
	xp(0)

{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	ShowLogs();
	addScore(10);
	addXP();
	UE_LOG(LogTemp, Error, TEXT("XP: %d"), xp);
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AItemBase::addXP()
{
	xp = score * 10;
	return 0;
}

void AItemBase::ShowLogs()
{
	UE_LOG(LogTemp, Display, TEXT("Log eseguiti dalla funzione"));
	UE_LOG(LogTemp, Error, TEXT("Score: %d"), score);
	UE_LOG(LogTemp, Error, TEXT("Flag: %d"), flag);
	UE_LOG(LogTemp, Error, TEXT("Description: %s"), *description);
}

void AItemBase::addScore(int points)
{
	score += points;
}
