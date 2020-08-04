#include "stdafx.h"
#include "Boss.h"
#include "Straight.h"
#include "Parabola.h"

Boss::Boss()
{
}


Boss::~Boss()
{
}

void Boss::Initialize()
{
	m_tInfo = { 250.f, 100.f, 48.f, 63.f };

	m_fSpeed = 2.f;
	m_fAngle = 90;
	m_iHP = 1;
	m_bDead = false;

	m_fAngle = 90;
	m_fAngle_2 = 180;
	m_fAngle_3 = 270;
	m_fAngle_4 = 360;
	
	m_iA = 5;

	m_tFrame = { 0, 3, 0, 120, GetTickCount(), 0 };

	m_dwCounter = GetTickCount();

	m_bPatter_1 = true;
	dwOldTime_1 = GetTickCount();

}

int Boss::Update()
{
	Obj::Update();

	if (m_dwOldCounter + m_dwCounter < GetTickCount())
	{
		m_dwOldCounter = GetTickCount();

		++pattern;

		//if (!m_bPatter_1 && 1 == pattern)
		//{
		//	dwOldTime_1 = GetTickCount();
		//}



		// 패턴 2가 false 일때
		// pattern 값이 2일때
		if (!m_bPatter_2 && 2 == pattern)
		{
			m_bPatter_1 = false;
			m_bPatter_2 = true;
			dwOldTime_2 = GetTickCount();
		}

		// 패턴 3이 false 일때
		// pattern 값이 3일때
		if (!m_bPatter_3 && 3 == pattern)
		{
			m_bPatter_2 = false;
			m_bPatter_3 = true;
			dwOldTime_3 = GetTickCount();
		}


		if (3 < pattern)
		{
			pattern = 1;
		}
	}

	switch (pattern)
	{

	case 1:
		if (m_tInfo.fX < 100)
		{
			m_eCurState = RIGHT;
			m_fSpeed *= -1.f;
		}

		if (m_tInfo.fX > 400)
		{
			m_eCurState = LEFT;
			m_fSpeed *= -1.f;
		}

		m_tInfo.fX -= m_fSpeed;

		//0.1초 주기로 호출 돌면서 총알 발사
		if (dwOldTime_1 + dwCurTime_1 < GetTickCount())
		{
			// 10초 주기로 각도를 반대로 바꿔줌
			if (dwRateTime_1 + dwLoedTime_1 < GetTickCount())
			{
				dwRateTime_1 = GetTickCount();
				m_iA *= -1;
			}

			dwOldTime_1 = GetTickCount();

			m_fAngle += m_iA;
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Straight>(m_fAngle), OBJ_BOSS_BULLET);

			m_fAngle_2 += m_iA;
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Straight>(m_fAngle_2), OBJ_BOSS_BULLET);

			m_fAngle_3 += m_iA;
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Straight>(m_fAngle_3), OBJ_BOSS_BULLET);

			m_fAngle_4 += m_iA;
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Straight>(m_fAngle_4), OBJ_BOSS_BULLET);

			ObjectMgr::GetInstance()->AddObject(CreateBullet<Straight>(275), OBJ_BOSS_BULLET);
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Straight>(260), OBJ_BOSS_BULLET);
		}
		break;

	case 2:

		// 0.3초 주기로 총알을 발사
		if (dwOldTime_2 + dwCurTime_2 < GetTickCount())
		{
			dwOldTime_2 = GetTickCount();
			
			// 좌우로 이동하며 아래로 발사함
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Parabola>(160), OBJ_BOSS_BULLET);
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Parabola>(240), OBJ_BOSS_BULLET);
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Parabola>(320), OBJ_BOSS_BULLET);
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Parabola>(360), OBJ_BOSS_BULLET);

			ObjectMgr::GetInstance()->AddObject(CreateBullet<Straight>(280), OBJ_BOSS_BULLET);
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Straight>(300), OBJ_BOSS_BULLET);
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Straight>(250), OBJ_BOSS_BULLET);
		}
		
		// 원으로 돎
		m_tInfo = PatternMgr::GetInstance()->Tonador(this, m_fAngle);

		m_fAngle += m_fSpeed;
		break;

	case 3:
		// 1초마다 호출
		if (dwOldTime_3 + dwCurTime_3 < GetTickCount())
		{
			dwOldTime_3 = GetTickCount();

			for (float i = 0.f; i < 360; i += 5.f)
			{
				ObjectMgr::GetInstance()->AddObject(CreateBullet<Straight>(i), OBJ_BOSS_BULLET);
			}

			for (float i = 120.f; i < 280; i += 30.f)
			{
				ObjectMgr::GetInstance()->AddObject(CreateBullet<Parabola>(i), OBJ_BOSS_BULLET);
				ObjectMgr::GetInstance()->AddObject(CreateBullet<Parabola>(i), OBJ_BOSS_BULLET);
			}

			Line++;
		}

		m_tInfo = PatternMgr::GetInstance()->Tonador(this, m_fAngle);

		m_fAngle += m_fSpeed;

		break;
	}

	SceneChange();
	IsAnimatime();

	return 0;
}

void Boss::Render(HDC hDC)
{
	Obj::Update();

	Bmp* pBmp = BmpMgr::GetInstance()->FindImage(L"Boss");

	if (pBmp == nullptr)
		return;

	GdiTransparentBlt(hDC, (int)m_tRect.left, (int)m_tRect.top
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, pBmp->GetMemDC()
		, (int)m_tFrame.iFrameStart * (int)m_tInfo.fCX, (int)m_tFrame.iScene * (int)m_tInfo.fCY
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, RGB(1, 1, 1));

	wchar_t         pos[64];
	swprintf_s(pos, L"X:%.2f Y:%.2f", m_tInfo.fX, m_tInfo.fY);
	SetTextAlign(hDC, TA_CENTER);
	SetBkMode(hDC, TRANSPARENT);
	TextOut(hDC, INT(m_tInfo.fX), INT(m_tInfo.fY - 60), pos, wcslen(pos));
}

void Boss::Release()
{
}


void Boss::SceneChange()
{
	if (m_ePrevState != m_eCurState)
	{
		switch (m_eCurState)
		{
		case IDLE:
			m_tFrame = { 0, 3, 0, 100, GetTickCount(), 0 };
			break;
		case LEFT:
			m_tFrame = { 0, 3, 1, 150, GetTickCount(), 0 };
			break;
		case RIGHT:
			m_tFrame = { 0, 3, 3, 150, GetTickCount(), 0 };
			break;
		}

		m_ePrevState = m_eCurState;
	}
}
