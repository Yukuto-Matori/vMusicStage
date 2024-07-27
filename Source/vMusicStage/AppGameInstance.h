// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AppGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class VMUSICSTAGE_API UAppGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	/// @brief 
	void Init() override;

	/// @brief 
	void Shutdown() override;

};
