// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ONLINE_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Pawnchoice;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool LevelLock2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool LevelLock3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Maps;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString playername;
public:
	UFUNCTION(BlueprintCallable)
		FString getplayername() { return playername; }
	UFUNCTION(BlueprintCallable)
		FString getplayername(FString Yourname) { playername = Yourname; }
	UFUNCTION(BlueprintCallable)
		FString getplayername(Error Type);
	//枚举和文本类型无法使用。
	//ENetworkFailure<error-type> type;

	
};
