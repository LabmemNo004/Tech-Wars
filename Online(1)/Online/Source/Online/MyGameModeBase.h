// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyPlayerController.h"
#include "Engine.h"
#include "MyGameModeBase.generated.h"
//#include "DelegateCombinations.h"
/**
 * 
 */
UCLASS()
class ONLINE_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	//AMyGameModeBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int PlayerID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Number_Player;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
		//class Random * rand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AMyPlayerController*> &players;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AMyPlayerController*> &Controller1;



public:
	UFUNCTION(BlueprintCallable)
		void Calculate_PLayers();

	virtual void BeginPlay()override;

	UFUNCTION(BlueprintCallable)
	    void OnPostLogin(APlayerController * NewPlayer);

	UFUNCTION(BlueprintCallable)
		void SetPlayer(AMyPlayerController * Player);



	

};
