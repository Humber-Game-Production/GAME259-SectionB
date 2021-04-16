// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchPlayerState.h"

void AMatchPlayerState::SetEffectBox(UHorizontalBox* box)
{
	effectBox = box;
}

UHorizontalBox* AMatchPlayerState::GetEffectBox() const
{
	return effectBox;
}
