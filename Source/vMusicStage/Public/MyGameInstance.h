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
	/// @brief アプリ初期化に呼び出しされる処理
	virtual void Init() override;

	/// @brief アプリ終了時に呼び出しされる処理
	virtual void Shutdown() override;
};
