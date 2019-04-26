#pragma once
#include "DxLib.h"

class FieldObjectControll
{
public:
	FieldObjectControll();
	~FieldObjectControll();

	//---主要関数-----------------------------------
	void Init();
	void Update();
	void Draw();
	//---------------------------------------------

	//---Get関数-----------------------------------
	VECTOR GetFloorPos() { return m_floorPos; }
	bool GetIsEndRising() { return m_isEndRising; }
	//---------------------------------------------

	//---Set関数-----------------------------------
	void SetIsRising(bool flag) { m_isRising = flag; }
	//---------------------------------------------
private:
	void MoveFloor();

	int m_modelHandleFloor;
	int m_modelHandleTower;
	int m_modelHandleFrame;

	VECTOR m_floorPos;

	bool m_isRising;
	bool m_isEndRising;
};

