#include "FieldObjectControll.h"
#include "Sound.h"

FieldObjectControll::FieldObjectControll()
{
	m_modelHandleFloor = MV1LoadModel("data/model/scaffold.mqo");	//床
	m_modelHandleFrame = MV1LoadModel("data/model/frame.mqo");		//枠
	m_modelHandleTower = MV1LoadModel("data/model/tower.x");		//タワー
}


FieldObjectControll::~FieldObjectControll()
{
	MV1DeleteModel(m_modelHandleFloor);
	MV1DeleteModel(m_modelHandleFrame);
	MV1DeleteModel(m_modelHandleTower);
}

void FieldObjectControll::Init()
{
	m_floorPos = VGet(0.f, -150.f, 0.f);

	m_isRising = false;
	m_isEndRising = false;
}

void FieldObjectControll::Update()
{
	MoveFloor();
}

void FieldObjectControll::Draw()
{
	// ３Dモデルのポジション設定
	MV1SetPosition(m_modelHandleFloor, m_floorPos);
	MV1SetPosition(m_modelHandleTower, VGet(0, 0, 0));
	MV1SetPosition(m_modelHandleFrame, VGet(0, 0, 0));

	// ３Ｄモデルの描画
	MV1DrawModel(m_modelHandleFloor);
	MV1DrawModel(m_modelHandleTower);
	MV1DrawModel(m_modelHandleFrame);
}

void FieldObjectControll::MoveFloor()
{
	// 床が動いている間、効果音再生
	if (m_floorPos.y != 0)
	{
		playSound(SE_SCAF);
	}
	else
	{
		stopSound(SE_SCAF);
		resetSound(SE_SCAF);
	}

	if (m_floorPos.y >= 0 && !m_isRising)
	{
		m_floorPos.y = 0.f;
		m_isEndRising = true;
	}
	else
	{
		m_floorPos.y += 2.f;
		m_isEndRising = false;
	}
}
