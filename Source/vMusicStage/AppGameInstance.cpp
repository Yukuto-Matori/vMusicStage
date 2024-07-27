#include "AppGameInstance.h"

#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMesh.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"

void UAppGameInstance::Init()
{
  Super::Init();
}


void UAppGameInstance::Shutdown()
{
  Super::Shutdown();
  // テストメッセージを出力
  UE_LOG(LogTemp, Warning, TEXT(
    "Shutdown() called."));
}

