// Fill out your copyright notice in the Description page of Project Settings.


#include "AppGameModeBase.h"

#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMesh.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"

void AAppGameModeBase::StartPlay()
{
  Super::StartPlay();

  UE_LOG(LogTemp, Warning, TEXT("Start Play!!!"));
  /*
  // �X�^�e�B�b�N���b�V���̎擾
  UStaticMesh* SphereMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere.Sphere"));
  if (!SphereMesh)
  {
    UE_LOG(LogTemp, Warning, TEXT("Could not find Sphere mesh"));
    return;
  }

  // �A�N�^�[�̐���
  FActorSpawnParameters SpawnParams;
  AStaticMeshActor* NewActor = GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), FVector(500.0f, 0.0f, 100.0f), FRotator::ZeroRotator, SpawnParams);
  if (!NewActor)
  {
    UE_LOG(LogTemp, Warning, TEXT("Could not spawn actor"));
    return;
  }

  // �X�^�e�B�b�N���b�V����ݒ�
  UStaticMeshComponent* MeshComponent = NewActor->GetStaticMeshComponent();
  if (!MeshComponent)
  {
    UE_LOG(LogTemp, Warning, TEXT("Could not get StaticMeshComponent"));
    return;
  }


  // ���r���e�B�� Movable �ɐݒ�
  MeshComponent->SetMobility(EComponentMobility::Movable);
  MeshComponent->SetStaticMesh(SphereMesh);
  // MeshComponent->RegisterComponent();

  // �A�N�^�� Transform ��ݒ�

  //FVector NewLocation(500.0f, 0.0f, 100.5f);
  //FRotator NewRotation(0.0f, 0.0f, 0.0f);
  //FVector NewScale(1.0f, 1.0f, 1.0f);

  //FTransform NewTransform(NewRotation, NewLocation, NewScale);
  //NewActor->SetActorTransform(NewTransform);


  NewActor->SetActorLabel(TEXT("TestActor"));

  */

  createCamera();
  UE_LOG(LogTemp, Warning, TEXT("Finish Play!!!"));
}

void AAppGameModeBase::createCamera()
{
  UE_LOG(LogTemp, Warning, TEXT("Generate Camera start."));

  // �A�N�^�𐶐�
  FVector ActorLocation = FVector(0.0f, 0.0f, 0.0f);
  FRotator ActorRotation = FRotator::ZeroRotator;
  AActor* NewActor = GetWorld()->SpawnActor<AActor>(ActorLocation, ActorRotation);
  NewActor->SetActorLabel(TEXT("StageCenterCamera"));

  // �J�����R���|�[�l���g���A�^�b�`
  UCameraComponent* CameraComponent = NewObject<UCameraComponent>(NewActor);
  CameraComponent->SetupAttachment(NewActor->GetRootComponent());
  CameraComponent->RegisterComponent(); // �s�v����


  CameraComponent->SetWorldLocation(ActorLocation);
  CameraComponent->SetWorldRotation(FRotator(0.0f, 0.0f, 0.0f));
  CameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;  // ���s���e���[�h�ɐݒ�
  CameraComponent->OrthoWidth = 1920.0f;
  CameraComponent->OrthoNearClipPlane = 0.0f;
  CameraComponent->OrthoFarClipPlane = 10000.0f;

  // �J�����̃T�C�Y����
  float AspectRatio = 1920.0f / 1080.0f;
  CameraComponent->SetOrthoWidth(1920.0f);
  CameraComponent->AspectRatio = AspectRatio;

  UE_LOG(LogTemp, Warning, TEXT("Generate Camera end."));
}
