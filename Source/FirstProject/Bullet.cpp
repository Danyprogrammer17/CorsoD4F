// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/BoxComponent.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	SetRootComponent(RootBox);
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//muoviamo il proiettile

	FVector NewLocation = GetActorLocation();
	NewLocation.X += (speed * DeltaTime);
	SetActorLocation(NewLocation);

	UE_LOG(LogTemp, Warning, TEXT("Bullet location: %f"), NewLocation.X)
	UE_LOG(LogTemp, Warning, TEXT("Bullet location: %f"), NewLocation.Y)
	//se i proiettili vanno fuori la scena distruggiamoli
	if (NewLocation.X > 3500.0f)
	{
		this->Destroy();
	}
}

