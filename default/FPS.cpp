#include "FPS.h"

//---------------------
// コンストラクタ
//---------------------
FPS::FPS()
{
	m_startTime = 0;
	m_count = 0;
	m_fps = 0;
}

//---------------------
// デストラクタ
//---------------------
FPS::~FPS()
{
	// 処理なし
}

//---------------------
// 更新
//---------------------
bool FPS::Update()
{
	// 1フレーム目なら時刻を取得
	if (m_count == 0)
	{
		m_startTime = GetNowCount();
	}

	// 60フレーム目なら平均を計算する
	if (m_count == N)
	{
		int t = GetNowCount();
		m_fps = 1000.f / ((t - m_startTime) / (float)N);
		m_count = 0;
		m_startTime = t;
	}
	m_count++;
	return true;
}

//---------------------
// 待機
//---------------------
void FPS::Wait()
{
	int tookTime = GetNowCount() - m_startTime;		// かかった時間
	int waitTime = m_count * 1000 / Fps - tookTime;	// 待つべき時間
	if (waitTime > 0)
	{
		Sleep(waitTime);	// 待機
	}
}
