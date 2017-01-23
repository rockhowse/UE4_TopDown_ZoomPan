// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "UE4_TopDown_ZoomPan.h"
#include "UE4_TopDown_ZoomPanPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "UE4_TopDown_ZoomPanCharacter.h"

AUE4_TopDown_ZoomPanPlayerController::AUE4_TopDown_ZoomPanPlayerController()
{
	bShowMouseCursor = true;
}

void AUE4_TopDown_ZoomPanPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void AUE4_TopDown_ZoomPanPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();
}
