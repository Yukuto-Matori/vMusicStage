#include "MyGameInstance.h"
#include "Engine/Engine.h"


void UMyGameInstance::Init()
{
  Super::Init();

  // �e�X�g���b�Z�[�W���o��
  UE_LOG(LogTemp, Warning, TEXT("MyGameInstance has been initialized!"));
}

void UMyGameInstance::Shutdown()
{
}
