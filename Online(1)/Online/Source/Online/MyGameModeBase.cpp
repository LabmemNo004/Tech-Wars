// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameModeBase.h"
#include "string"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "GameplayStatics.generated.h"
//#include "Engine/Source/Runtime/Core/Public/Containers/Array.h"
void AMyGameModeBase::Calculate_PLayers()
{
	TArray<AActor*> FoundActors;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), , FoundActors);
	Number_Player = FoundActors.Num();
}


void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> FoundActors;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), , FoundActors);
	//void UGameplayStatics::GetAllActorsOfClass()
	//rand = FoundActors.Num();

	FTimerHandle TimerHandle;
	FTimerDelegate TimerDel;
	UWorld* const World = GetWorld();
	//GetWorldTimerManager().SetTimer(TimerHandle, rand->randhp, 1.0f, true);
	//GetWorldTimerManager().SetTimer(TimerHandle, rand->randex, 1.0f, true);
	//GetWorldTimerManager().SetTimer(TimerHandle, AMyGameModeBase::Calculate_PLayers(), 1.0f, true);

}

void AMyGameModeBase::OnPostLogin(APlayerController * NewPlayer)
{
	APlayerController * controller2 = Cast<AMyPlayerController>(NewPlayer);
	//&(Controller1[0]) = Cast<AMyPlayerController>(NewPlayer);
	if (controller2 == nullptr)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("OnPostLogin: cast to desired PlayerController failed"));
		}
	}
	else
	{
		
		//players.AddUnique(TArray<AMyPlayerController, FDefaultAllocator>);
		//players.Add(controller2);有问题
		if (this->GetNumPlayers() == 1)
		{
			//Controller2.waitingtosatrt();
		}
		else
		{
			//players[0].RemoveWaiting();
		}
		//Controller2.PawnChoice();
	}
}

void AMyGameModeBase::SetPlayer(AMyPlayerController * Player)
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
	for (const uint8 i = 0; i < players.Num(); i++)
	{
		//<AMyPlayerController, FDefaultAllocator>*p = &(players[i]);
		if (&(players[i]) != nullptr)
		{
			temp.Append(BytesToString(i, 0));
			break;
		}
	}
	FName temp1 = FName(*temp);
	TArray<AActor*> FoundActors;
	UWorld* const World = GetWorld();
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), temp1, FoundActors);
	FoundActors[0]->GetActorTransform();
	
	if (World != NULL)
	{
		if (Player->Pawns == 1)
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
		else if (Player->Pawns == 2)
		{
			/*World->SpawnActor<>()//带初始化及人物设置。
				template< class T >
			T* SpawnActor(UClass* Class, FoundActors[0]->GetActorTransform(), const FActorSpawnParameters& SpawnParameters = FActorSpawnParameters())
			{
				return CastChecked<T>(SpawnActor(Class, &Transform, SpawnParameters), ECastCheckedType::NullAllowed);
			}*/


			//Player->Possess(TWWPawnChild1);
		}
		else if (Player->Pawns == 3)
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
	
	PlayerID++;
}


