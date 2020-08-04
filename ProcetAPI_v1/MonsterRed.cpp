#include "stdafx.h"
#include "MonsterRed.h"
#include "Beeline.h"
#include "Straight_horizontal.h"

MonsterRed::MonsterRed()
{
}


MonsterRed::~MonsterRed()
{
}

void MonsterRed::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 25.f;
	m_tColli = { 25.f, 25.f };
	m_fAngle = 180;
	m_iHP = 1;
	m_bDead = false;

	m_fSpeed = 1.f;
	m_tFrame = { 0, 3, 0, 100, GetTickCount(), 0 };

	m_dwOldTime = GetTickCount();
}

int MonsterRed::Update()
{
	if (m_iHP <= 0)
	{
		SetDead();
		return 1;
	}

	Obj::Update();

	if (m_tRect.left < 30 || m_tRect.top < 30 || m_tRect.right > 447 || m_tRect.bottom > 600)
		return 1;

	IsAnimatime();

	switch (m_eDir)
	{
	case RIGHT:
		
		if (m_dwOldTime + 1000 < GetTickCount())
		{
			m_dwOldTime = GetTickCount();

			ObjectMgr::GetInstance()->AddObject(CreateBullet<Straight_horizontal>(0), OBJ_MONSTER_BULLET);
		}

		//m_tInfo = PatternMgr::GetInstance()->MoveRed(this, m_eDir);
		m_tInfo.fY += m_fSpeed;
		break;

	case LEFT:
		if (m_dwOldTime + 1000 < GetTickCount())
		{
			m_dwOldTime = GetTickCount();

			ObjectMgr::GetInstance()->AddObject(CreateBullet<Straight_horizontal>(180), OBJ_MONSTER_BULLET);
		}

		m_tInfo.fY += m_fSpeed;
		break;
	}


	return 0;
}

void MonsterRed::Render(HDC hDC)
{
	Obj::Update();

	Bmp* pBmp = BmpMgr::GetInstance()->FindImage(L"Monster_Red");

	if (pBmp == nullptr)
		return;

	GdiTransparentBlt(hDC, (int)m_tRect.left, (int)m_tRect.top
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, pBmp->GetMemDC()
		, (int)m_tFrame.iFrameStart * (int)m_tInfo.fCX, (int)m_tFrame.iScene * (int)m_tInfo.fCY
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, RGB(1, 1, 1));

	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void MonsterRed::Release()
{
}
