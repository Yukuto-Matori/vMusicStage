#include "MyGameInstance.h"
#include "Engine/Engine.h"


void UMyGameInstance::Init()
{
  Super::Init();

  // テストメッセージを出力
  UE_LOG(LogTemp, Warning, TEXT("MyGameInstance has been initialized!"));
}

void UMyGameInstance::Shutdown()
{
}
