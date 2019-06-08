// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include"Components/WidgetComponent.h"
#include "Components/BoxComponent.h"
#include "MyBoss.generated.h"
#include "time.h"
#include"Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"
#include "Kismet/GameplayStatics.h"



UCLASS()
class THIRDTRY_API AMyBoss : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBoss();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent * Spheremesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBoxComponent * Deathboom;
public:
	float calculatehp(float GunDamage);
	int score = 500;
	float hp = 1.0;
	float defence = 0.2;
	float GunDsamage = 0.2;
	FTimerHandle MyTimerHand;//¶¨Ê±Æ÷¾ä±ú
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
