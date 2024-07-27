// Fill out your copyright notice in the Description page of Project Settings.


#include "StageCameraActor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"


// Sets default values
AStageCameraActor::AStageCameraActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and attach the camera component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	RootComponent = CameraComponent;
}

// Called when the game starts or when spawned
void AStageCameraActor::BeginPlay()
{
	Super::BeginPlay();
	// テストメッセージを出力
	UE_LOG(LogTemp, Warning, TEXT("Camera Begin!"));

  SetupCamera();

  // Set this camera as the view target for the player controller
  APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
  if (PlayerController)
  {
    PlayerController->SetViewTarget(this);
  }

  UE_LOG(LogTemp, Warning, TEXT("Camera End!"));
}

// Called every frame
void AStageCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStageCameraActor::SetupCamera()
{
  // Set camera location and rotation
  CameraComponent->SetWorldLocation(FVector(0.0f, 0.0f, 0.0f));
  CameraComponent->SetWorldRotation(FRotator(0.0f, 0.0f, 0.0f));
  CameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
  CameraComponent->OrthoWidth = 1920.0f;
  CameraComponent->OrthoNearClipPlane = 0.0f;
  CameraComponent->OrthoFarClipPlane = 10000.0f;

  float AspectRatio = 1920.0f / 1080.0f;
  CameraComponent->SetOrthoWidth(1920.0f);
  CameraComponent->AspectRatio = AspectRatio;
}

