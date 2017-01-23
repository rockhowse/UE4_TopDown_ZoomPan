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

	// Input handlers
	void OnMoveForwardAxis(float axisValue);
	void OnMoveRightAxis(float axisValue);
	void OnMouseHorizontal(float axisValue);
	void OnMouseVertical(float axisValue);
	void OnZoomInAction();
	void OnZoomOutAction();
	void OnLookAroundStart();
	void OnLookAroundStop();

protected:

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

private:
	bool lookAroundEnabled = false;
	int32 mouseLockPositionX;
	int32 mouseLockPositionY;
};


