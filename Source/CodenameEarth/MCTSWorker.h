// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MCTSWorker.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CODENAMEEARTH_API UMCTSWorker : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMCTSWorker();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	typedef struct
	{
		int x;
		int y;
		int occupierID;
		bool isPlayer;
	} AI_BoardTile;

	typedef struct
	{
		AI_BoardTile line[8];
	} AI_BoardHLine;

	typedef struct
	{
		int x;
		int y;
		bool moved;
		bool isAlive;

	};

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable) void MCTSAI();
};
