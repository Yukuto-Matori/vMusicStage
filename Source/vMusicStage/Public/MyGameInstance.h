// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class VMUSICSTAGE_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	/// @brief �A�v���������ɌĂяo������鏈��
	virtual void Init() override;

	/// @brief �A�v���I�����ɌĂяo������鏈��
	virtual void Shutdown() override;
};
