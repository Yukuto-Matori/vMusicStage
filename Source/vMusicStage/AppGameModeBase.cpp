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
  //createCamera();

  // �v���C���[�R���g���[���[�ɃJ������ݒ�
  //APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
  //if (PlayerController)
  //{
  //  PlayerController->SetViewTarget(this);
  //}

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
  CameraComponent->OrthoFarClipPlane = 10000.0f;  // �`��N���b�s���O�̍ő勗

  // �J�����̃T�C�Y����
  float AspectRatio = 1920.0f / 1080.0f;
  CameraComponent->SetOrthoWidth(1920.0f);
  CameraComponent->AspectRatio = AspectRatio;

  UE_LOG(LogTemp, Warning, TEXT("Generate Camera end."));
}
