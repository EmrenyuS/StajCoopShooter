// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterPlayerState.h"
#include "StajCoopShooter/Character/BlasterCharacter.h"
#include "StajCoopShooter/PlayerController/BlasterPlayerController.h"
#include "Net/UnrealNetwork.h"

void ABlasterPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABlasterPlayerState, Defeats);
}

void ABlasterPlayerState::AddToScore(float ScoreAmount)
{
	SetScore(GetScore() + ScoreAmount);
	/*Character = Character == nullptr ? Cast<ABlasterCharacter>(GetPawn()) : Character;
	if (Character && Character->Controller)
	{
		Controller = Controller == nullptr ? Cast<ABlasterPlayerController>(Character->Controller) : Controller;
		if (Controller)
		{
			Controller->SetHUDScore(GetScore());
		}
	}
	*/
	Controller = Controller == nullptr ? Cast<ABlasterPlayerController>(GetOwningController()) : Controller;
	if (Controller)
	{
		Controller->SetHUDScore(GetScore());
	}
}

void ABlasterPlayerState::OnRep_Score()
{
	Super::OnRep_Score();

	Controller = Controller == nullptr ? Cast<ABlasterPlayerController>(GetOwningController()) : Controller;
	if (Controller)
	{
		Controller->SetHUDScore(GetScore());
	}

}

void ABlasterPlayerState::AddToDefeats(int32 DefeatsAmount)
{
	Defeats += DefeatsAmount;

	Controller = Controller == nullptr ? Cast<ABlasterPlayerController>(GetOwningController()) : Controller;
	if (Controller)
	{
		Controller->SetHUDDefeats(Defeats);
	}
}

void ABlasterPlayerState::OnRep_Defeats()
{
	
	/*Character = Character == nullptr ? Cast<ABlasterCharacter>(GetPawn()) : Character;
	if (Character && Character->Controller)
	{
		Controller = Controller == nullptr ? Cast<ABlasterPlayerController>(Character->Controller) : Controller;
	}
	Old Code (Course code) no need to character in ue 5.7.4 if u use it it will not work when someone died */

	Controller = Controller == nullptr ? Cast<ABlasterPlayerController>(GetOwningController()) : Controller;
	if (Controller)
	{
		Controller->SetHUDDefeats(Defeats);
	}
}

