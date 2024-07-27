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
  // スタティックメッシュの取得
  UStaticMesh* SphereMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere.Sphere"));
  if (!SphereMesh)
  {
    UE_LOG(LogTemp, Warning, TEXT("Could not find Sphere mesh"));
    return;
  }

  // アクターの生成
  FActorSpawnParameters SpawnParams;
  AStaticMeshActor* NewActor = GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), FVector(500.0f, 0.0f, 100.0f), FRotator::ZeroRotator, SpawnParams);
  if (!NewActor)
  {
    UE_LOG(LogTemp, Warning, TEXT("Could not spawn actor"));
    return;
  }

  // スタティックメッシュを設定
  UStaticMeshComponent* MeshComponent = NewActor->GetStaticMeshComponent();
  if (!MeshComponent)
  {
    UE_LOG(LogTemp, Warning, TEXT("Could not get StaticMeshComponent"));
    return;
  }


  // モビリティを Movable に設定
  MeshComponent->SetMobility(EComponentMobility::Movable);
  MeshComponent->SetStaticMesh(SphereMesh);
  // MeshComponent->RegisterComponent();

  // アクタの Transform を設定

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

  // アクタを生成
  FVector ActorLocation = FVector(0.0f, 0.0f, 0.0f);
  FRotator ActorRotation = FRotator::ZeroRotator;
  AActor* NewActor = GetWorld()->SpawnActor<AActor>(ActorLocation, ActorRotation);
  NewActor->SetActorLabel(TEXT("StageCenterCamera"));

  // カメラコンポーネントをアタッチ
  UCameraComponent* CameraComponent = NewObject<UCameraComponent>(NewActor);
  CameraComponent->SetupAttachment(NewActor->GetRootComponent());
  CameraComponent->RegisterComponent(); // 不要かも


  CameraComponent->SetWorldLocation(ActorLocation);
  CameraComponent->SetWorldRotation(FRotator(0.0f, 0.0f, 0.0f));
  CameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;  // 平行投影モードに設定
  CameraComponent->OrthoWidth = 1920.0f;
  CameraComponent->OrthoNearClipPlane = 0.0f;
  CameraComponent->OrthoFarClipPlane = 10000.0f;

  // カメラのサイズ調整
  float AspectRatio = 1920.0f / 1080.0f;
  CameraComponent->SetOrthoWidth(1920.0f);
  CameraComponent->AspectRatio = AspectRatio;

  UE_LOG(LogTemp, Warning, TEXT("Generate Camera end."));
}
