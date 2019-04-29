#pragma once
#include "DxLib.h"
#include "PlayerControll.h"

class CharacterBase
{
public:
	CharacterBase();
	~CharacterBase();

	//---主要関数-----------------------------------
	void Create();
	void Delete();
	void Init();
	void Update();
	void Draw();
	//---------------------------------------------

	//---Get関数-----------------------------------
	VECTOR GetPlayerPos() { return p_player->GetPos(); }
	bool GetPlayerIsGround() { return p_player->GetIsGround(); }
	//---------------------------------------------
	
	//---Set関数-----------------------------------
	void SetFloorPosToPlayer(VECTOR v) { p_player->SetFloorPos(v); }
	void SetIsCanMoveToPlayer(bool flag) { p_player->SetIsCanMove(flag); }
	//---------------------------------------------

private:
	PlayerControll *p_player;

};

