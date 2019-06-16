// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameClientModeBase.h"
#include "MyGameModeBase.h"
#include "MyGameInstance.h"
#include "Engine.h"

void AMyGameClientModeBase::OnPostLogin(APlayerController * NewPlayer)
{
	gameinstance = Cast<MyGameinstance>(GetGameInstance());
	AMyPlayerController * controller = Cast<AMyPlayerController>(NewPlayer);
	if (controller == nullptr)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("OnPostLogin: cast to desired PlayerController failed"));
		}
	}
	else
	{
		UPlayer* some = Cast<UPlayer>(NewPlayer);
		FInputModeGameOnly inputmode;
		inputmode.SetConsumeCaptureMouseDown(true);
		//FInputModeDataBase& Data = Cast<FInputModeDataBase>(inputmode);
		controller->SetInputMode(inputmode);
		NewPlayer->SetPlayer(some);
	}




}


void AMyGameClientModeBase::SetPlayer(AMyPlayerController * Player)
{
	Player->online = true;
	FString temp = "PlayerStart_";
	/*if(Cast<TWW_PlayerState>(Player->GetPlayerState))
	{
		//	设置HP，LV等，有待完善；

	}
	else
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("GameMode cast PlayerState  failed"));
		}
	}
	*/
	//find无法找到实现
	
	FName temp1 = FName(*temp);
	TArray<AActor*> FoundActors;
	UWorld* const World = GetWorld();
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), temp1, FoundActors);
	//FoundActors[0]->GetActorTransform();!!!

	if (World != NULL)
	{
		//if (gameinstance.Pawnchoice == 1)是gameinstance里面有bug,最初来源于数组引用，无法解决
		{
			//transform已经填好！！！！



			/*World->SpawnActor<>()//带初始化及人物设置。
				template< class T >
			T* SpawnActor(UClass* Class, FoundActors[0]->GetActorTransform(), const FActorSpawnParameters& SpawnParameters = FActorSpawnParameters())
			{
				return CastChecked<T>(SpawnActor(Class, &Transform, SpawnParameters), ECastCheckedType::NullAllowed);
			}*/

			//Player->Possess(TWWPawnChild1);

			//注意possess与蓝图不符。


		}
		//else if (gameinstance.Pawnchoice == 2)
		{
			/*World->SpawnActor<>()//带初始化及人物设置。
				template< class T >
			T* SpawnActor(UClass* Class, FoundActors[0]->GetActorTransform(), const FActorSpawnParameters& SpawnParameters = FActorSpawnParameters())
			{
				return CastChecked<T>(SpawnActor(Class, &Transform, SpawnParameters), ECastCheckedType::NullAllowed);
			}*/


			//Player->Possess(TWWPawnChild1);
		}
		//else 
		{
			/*World->SpawnActor<>()//带初始化及人物设置。
				template< class T >
			T* SpawnActor(UClass* Class, FoundActors[0]->GetActorTransform(), const FActorSpawnParameters& SpawnParameters = FActorSpawnParameters())
			{
				return CastChecked<T>(SpawnActor(Class, &Transform, SpawnParameters), ECastCheckedType::NullAllowed);
			}*/


			//Player->Possess(TWWPawnChild1);
		}
	}
}
void AMyGameClientModeBase::Win()
{

	FName temp1 = "Boss";
	TArray<AActor*> FoundActors;
	//TArray<*> Found1Actors;括号内填写控件类型
	UWorld* const World = GetWorld();
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), temp1, FoundActors);
	TSubclassOf<AActor> TS;

	if (FoundActors.Num() == 0)
	{
		/*
		添加控件并显示在屏幕上
		*/
		APlayerController* controller= UGameplayStatics::GetPlayerController(GetWorld(), 0);
		controller->ShouldShowMouseCursor();

		//GetPlayerController();
		//UGameplayStatics::GetAllActorsOfClass(GetWorld(), TS, Found1Actors);
		//gameinstance->LevelLock(FoundActors.Num());
	}
}

