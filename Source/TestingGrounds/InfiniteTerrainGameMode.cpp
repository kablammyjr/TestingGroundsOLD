// Fill out your copyright notice in the Description page of Project Settings.

#include "InfiniteTerrainGameMode.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"


AInfiniteTerrainGameMode::AInfiniteTerrainGameMode()
{
	ActorPool = CreateDefaultSubobject<UActorPool>(FName("Actor Pool"));
}


void AInfiniteTerrainGameMode::PopulateActorPool()
{
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddActorToPool(*VolumeIterator);
		++VolumeIterator;
	}
}

void AInfiniteTerrainGameMode::AddActorToPool(class AActor *ActorToAdd)
{
	ActorPool->Add(ActorToAdd);
}