// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBoss.h"
#include"Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"





// Sets default values
AMyBoss::AMyBoss()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Spheremesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Spheremesh"));
	Spheremesh->SetSimulatePhysics(true);	
	Deathboom = CreateDefaultSubobject<UBoxComponent>(TEXT("Deathboom"));

}

// Called when the game starts or when spawned
void AMyBoss::BeginPlay()
{
	Super::BeginPlay();

	auto mylittlepawn =UGameplayStatics::GetPlayerPawn(this, 0);//0表示默认的玩家
	auto pawnslocation = mylittlepawn->GetPawnViewLocation();
	
}

// Called every frame
void AMyBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
 
float AMyBoss::calculatehp(float GunDsamage)
{
	float tem=0.0;
	tem = defence / GunDsamage;
	hp -= tem;
	return hp;
}


