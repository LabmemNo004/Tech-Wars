// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBoss.h"
#include"Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "World.h"
#include "Actor.generated.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"
#include "Pawn.generated.h"
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
	auto pawnslocation = mylittlepawn->GetPawnViewLocation;
	fireshoot();






	
}

// Called every frame
void AMyBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (hp <= 0)
	{
		auto location =Deathboom->GetComponentLocation;
		auto scale = Deathboom->GetScaledBoxExtent;
		auto mine = UKismetMathLibrary::RandomPointInBoundingBox(location, scale);
		FRotator rotator = { 0.0,0.0,0.0 };
		FVector vector = { 1.0,1.0,1.0 };
		auto mine1 = UKismetMathLibrary::MakeTransform(mine, rotator, vector);
		AActor* SpawnedActor1 = SpawnActor(EXpoint, EXpoint, location);//经验点
		AActor* SpawnedActor1 = SpawnActor(HPpoint, HPpoint, location);//生命点
		
																	   
																	   
		//引入加分
		




		GetWorldTimerManager().SetTimer(MyTimerHand, this, 0.0f, true, 5.0f);
		GetWorldTimerManager().ClearTimer(MyTimerHand);






		Destroy(true);










	}











}
 
float AMyBoss::calculatehp(float GunDsamage)
{
	float tem=0.0;
	tem = defence / GunDsamage;
	hp -= tem;
}


