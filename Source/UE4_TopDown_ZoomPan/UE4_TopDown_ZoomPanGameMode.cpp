// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "UE4_TopDown_ZoomPan.h"
#include "UE4_TopDown_ZoomPanGameMode.h"
#include "UE4_TopDown_ZoomPanPlayerController.h"
#include "UE4_TopDown_ZoomPanCharacter.h"

AUE4_TopDown_ZoomPanGameMode::AUE4_TopDown_ZoomPanGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AUE4_TopDown_ZoomPanPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}