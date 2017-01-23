// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "UE4_TopDown_ZoomPan.h"
#include "UE4_TopDown_ZoomPanPlayerController.h"
#include "Engine/LocalPlayer.h"
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

	// Input Handlers
	InputComponent->BindAxis("MoveForward", this, &AUE4_TopDown_ZoomPanPlayerController::OnMoveForwardAxis);
	InputComponent->BindAxis("MoveRight", this, &AUE4_TopDown_ZoomPanPlayerController::OnMoveRightAxis);
	InputComponent->BindAxis("MouseHorizontal", this, &AUE4_TopDown_ZoomPanPlayerController::OnMouseHorizontal);
	InputComponent->BindAxis("MouseVertical", this, &AUE4_TopDown_ZoomPanPlayerController::OnMouseVertical);
	InputComponent->BindAction("ZoomIn", EInputEvent::IE_Pressed, this, &AUE4_TopDown_ZoomPanPlayerController::OnZoomInAction);
	InputComponent->BindAction("ZoomOut", EInputEvent::IE_Pressed, this, &AUE4_TopDown_ZoomPanPlayerController::OnZoomOutAction);
	InputComponent->BindAction("LookAround", EInputEvent::IE_Pressed, this, &AUE4_TopDown_ZoomPanPlayerController::OnLookAroundStart);
	InputComponent->BindAction("LookAround", EInputEvent::IE_Released, this, &AUE4_TopDown_ZoomPanPlayerController::OnLookAroundStop);
}

void AUE4_TopDown_ZoomPanPlayerController::OnMoveForwardAxis(float axisValue)
{
	APawn* const Pawn = GetPawn();
	AUE4_TopDown_ZoomPanCharacter* character = Cast<AUE4_TopDown_ZoomPanCharacter>(Pawn);
	if (character)
	{
		character->MoveCharacterForward(axisValue);
	}
}

void AUE4_TopDown_ZoomPanPlayerController::OnMoveRightAxis(float axisValue)
{
	APawn* const Pawn = GetPawn();
	AUE4_TopDown_ZoomPanCharacter* character = Cast<AUE4_TopDown_ZoomPanCharacter>(Pawn);
	if (character)
	{
		character->MoveCharacterRight(axisValue);
	}
}

void AUE4_TopDown_ZoomPanPlayerController::OnMouseHorizontal(float axisValue)
{
	if (lookAroundEnabled)
	{
		APawn* const Pawn = GetPawn();
		Pawn->AddControllerYawInput(axisValue);
		Cast<ULocalPlayer>(Player)->ViewportClient->Viewport->SetMouse(mouseLockPositionX, mouseLockPositionY);
	}
}
void AUE4_TopDown_ZoomPanPlayerController::OnMouseVertical(float axisValue)
{
	if (lookAroundEnabled)
	{
		APawn* const Pawn = GetPawn();
		AUE4_TopDown_ZoomPanCharacter* character = Cast<AUE4_TopDown_ZoomPanCharacter>(Pawn);
		if (character)
		{
			character->RotateCameraArm(FRotator(axisValue, 0.0f, 0.0f));
		}
		Cast<ULocalPlayer>(Player)->ViewportClient->Viewport->SetMouse(mouseLockPositionX, mouseLockPositionY);
	}
}

void AUE4_TopDown_ZoomPanPlayerController::OnZoomInAction()
{
	APawn* const Pawn = GetPawn();
	AUE4_TopDown_ZoomPanCharacter* character = Cast<AUE4_TopDown_ZoomPanCharacter>(Pawn);
	if (character)
	{
		character->ChangeCameraArmLength(-1.0f);
	}
}

void AUE4_TopDown_ZoomPanPlayerController::OnZoomOutAction()
{
	APawn* const Pawn = GetPawn();
	AUE4_TopDown_ZoomPanCharacter* character = Cast<AUE4_TopDown_ZoomPanCharacter>(Pawn);
	if (character)
	{
		character->ChangeCameraArmLength(1.0f);
	}
}

void AUE4_TopDown_ZoomPanPlayerController::OnLookAroundStart()
{
	//Lock mouse cursor
	lookAroundEnabled = true;
	bShowMouseCursor = false;
	mouseLockPositionX = Cast<ULocalPlayer>(Player)->ViewportClient->Viewport->GetMouseX();
	mouseLockPositionY = Cast<ULocalPlayer>(Player)->ViewportClient->Viewport->GetMouseY();
}

void AUE4_TopDown_ZoomPanPlayerController::OnLookAroundStop()
{
	//Unlock mouse cursor
	lookAroundEnabled = false;
	bShowMouseCursor = true;
}
