// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/PlayerController.h"
#include "UE4_TopDown_ZoomPanPlayerController.generated.h"

UCLASS()
class AUE4_TopDown_ZoomPanPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AUE4_TopDown_ZoomPanPlayerController();

protected:

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface
};


