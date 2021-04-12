// Fill out your copyright notice in the Description page of Project Settings.


#include "W_Friend.h"



void UW_Friend::UpdateInfo(FBPFriendInfo friendInfo_, UTexture2D* Avatar_)
{
	
	friendInfo = friendInfo_;
	
	Avatar = Avatar_;

	FriendName->SetText(FText::FromString(friendInfo.DisplayName));

	FriendImage->SetBrushFromTexture(Avatar);
}



