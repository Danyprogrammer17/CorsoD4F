// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipController.h"
#include "Components/BoxComponent.h"
#include "EnemyController.h"
#include "Bullet.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AShipController::AShipController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AShipController::OnTriggerEnter);


	AutoPossessPlayer = EAutoReceiveInput::Player0;//player di default sarà quello nella scena
}

// Called when the game starts or when spawned
void AShipController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShipController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CurrentVelocity.IsZero()) 
	{
		FVector NewLocation = GetActorLocation() + (speed * CurrentVelocity * DeltaTime); //ogni qualvolta la velocità corrente del player non
		SetActorLocation(NewLocation);													// è zero, si prende la posizione istante per istante
																						// e la settiamo all'actor
	}
}

// Called to bind functionality to input
void AShipController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveX", this, &AShipController::Move_XAxis);//diciamo che a MoveX corrisponde la funzione Move_XAxis
	InputComponent->BindAxis("MoveY", this, &AShipController::Move_YAxis);//diciamo che a MoveX corrisponde la funzione Move_YAxis
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AShipController::OnShoot);
}

void AShipController::Move_XAxis(float AxisValue)
{
	CurrentVelocity.X = AxisValue * 75.0f;
}

void AShipController::Move_YAxis(float AxisValue)
{
	CurrentVelocity.Y = AxisValue * 75.0f;
}

void AShipController::OnShoot()
{
	UWorld* World = GetWorld(); //mi faccio restituire il mondo
	
	if (World) { //se esiste
		FVector Location = GetActorLocation();//prendo la posizione del player poichè il bullet partirà da lì
		World->SpawnActor<ABullet>(BulletBP, Location, FRotator::ZeroRotator); //spawno il bullet con location del giocatore e rotazione zero
	}
}

void AShipController::OnTriggerEnter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("TRIGGER"));
	if (OtherActor->IsA(AEnemyController::StaticClass())) 
	{
		UE_LOG(LogTemp, Warning, TEXT("TRIGGER WITH ENEMY"));
		Died = true;
		this->SetActorHiddenInGame(true);

		//gioco in pausa
		UGameplayStatics::SetGamePaused(GetWorld(), true);

	}

}

