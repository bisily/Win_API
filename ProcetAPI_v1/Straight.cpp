#include "stdafx.h"
#include "Straight.h"


Straight::Straight()
{
}


Straight::~Straight()
{
}

void Straight::Initialize()
{
	m_tInfo.fCX = 25.f;
	m_tInfo.fCY = 25.f;
	m_tColli = { 30.f, 30.f };
	m_iAtt = 1;
	m_fSpeed = 2.f;
	m_bDead = false;

	m_tFrame = { 0, 0, 0, 100, GetTickCount(), 0 };
}

int Straight::Update()
{
	if (m_bDead)
		return 1;

	Obj::Update();

	if (m_tRect.left < 30 || m_tRect.top < 30 || m_tRect.right > 447 || m_tRect.bottom > 600)
		return 1;

	m_tInfo.fX += cosf(m_fAngle * PI / 180.f) * m_fSpeed;
	m_tInfo.fY -= sinf(m_fAngle*PI / 180.f)* m_fSpeed;

	return 0;
}

void Straight::Render(HDC hDC)
{
	Obj::Update();

	Bmp* pBmp = BmpMgr::GetInstance()->FindImage(L"BossÃÑ¾Ë");

	if (pBmp == nullptr)
		return;

	GdiTransparentBlt(hDC, (int)m_tRect.left, (int)m_tRect.top
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, pBmp->GetMemDC()
		, (int)m_tFrame.iFrameStart * (int)m_tInfo.fCX, (int)m_tFrame.iScene * (int)m_tInfo.fCY
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, RGB(1, 1, 1));


	//Ellipse(hDC, m_tCheck.left, m_tCheck.top, m_tCheck.right, m_tCheck.bottom);
}

void Straight::Release()
{
}
