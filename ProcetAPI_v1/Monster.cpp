#include "stdafx.h"
#include "Monster.h"
#include "Beeline.h"

Monster::Monster()
{
}


Monster::~Monster()
{
}

void Monster::Initialize()
{
	m_tInfo = { 240.f, 200.f, 22.f, 26.f };
	m_tColli = { 15.f, 15.f };
	m_fAngle = 180;
	m_iHP = 1;
	m_bDead = false;

	m_fSpeed = 1.f;

	m_tFrame = { 0, 3, 0, 100, GetTickCount(), 0 };
	
	m_dwOldTime = GetTickCount();
}

int Monster::Update()
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

	if (m_dwOldTime + 1000 < GetTickCount())
	{
		m_dwOldTime = GetTickCount();

		ObjectMgr::GetInstance()->AddObject(CreateBullet<Beeline>(270), OBJ_MONSTER_BULLET);
	}

	switch (m_eDir)
	{
	case RIGHT:
		m_tInfo = PatternMgr::GetInstance()->AngleLine(this, 30);
		break;
	case LEFT:
		m_tInfo = PatternMgr::GetInstance()->AngleLine(this, 200);
		break;
	}

	return 0;
}

void Monster::Render(HDC hDC)
{
	Obj::Update();
	Bmp* pBmp = BmpMgr::GetInstance()->FindImage(L"Monster_Blue");

	if (pBmp == nullptr)
		return;

	GdiTransparentBlt(hDC, (int)m_tRect.left, (int)m_tRect.top
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, pBmp->GetMemDC()
		, (int)m_tFrame.iFrameStart * (int)m_tInfo.fCX, (int)m_tFrame.iScene * (int)m_tInfo.fCY
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, RGB(1, 1, 1));

	
	//Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	
}

void Monster::Release()
{
}
