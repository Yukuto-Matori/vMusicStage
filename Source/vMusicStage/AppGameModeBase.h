// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AppGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class VMUSICSTAGE_API AAppGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	/// @brief �X�e�[�W�N�����ɌĂяo�����
	void StartPlay() override;

	/// @brief �J��������
	void createCamera();
};
