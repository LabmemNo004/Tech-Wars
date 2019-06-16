// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h" 
#include "MyPlayerController.h"
#include "MyGameInstance.h"
#include "MyGameClientModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ONLINE_API AMyGameClientModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int choice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int BossID;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
		//class Random * rand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class MyGameinstance * gameinstance;
public:
	UFUNCTION(BlueprintCallable)
		void OnPostLogin(APlayerController * NewPlayer);

	UFUNCTION(BlueprintCallable)
		void SetPlayer(AMyPlayerController * Player);
	UFUNCTION(BlueprintCallable)
		void Win();
};
