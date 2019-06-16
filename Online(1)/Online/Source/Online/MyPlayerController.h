// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Classes/GameFramework/Pawn.h"
#include "MyPlayerController.generated.h"
/**
 * 
 */
UCLASS()
class ONLINE_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool online;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Pause_;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Pawns;
public:
	UFUNCTION(BlueprintCallable)
		void Name(UTextProperty* name);
	

	
};
