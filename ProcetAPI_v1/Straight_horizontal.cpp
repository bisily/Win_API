#include "stdafx.h"
#include "Straight_horizontal.h"


Straight_horizontal::Straight_horizontal()
{
}


Straight_horizontal::~Straight_horizontal()
{
}

void Straight_horizontal::Initialize()
{
	m_tInfo.fCX = 14.f;
	m_tInfo.fCY = 14.f;
	m_tColli = { 12.f, 12.f };
	m_iAtt = 1;
	m_fSpeed = 2.f;
	m_bDead = false;

	m_tFrame = { 0, 0, 0, 100, GetTickCount(), 0 };
}

int Straight_horizontal::Update()
{

	if (m_bDead)
		return 1;

	Obj::Update();

	if (m_tRect.left < 30 || m_tRect.top < 30 || m_tRect.right > 447 || m_tRect.bottom > 600)
		return 1;

	m_tInfo.fX += cosf(DegreeToRadian(m_fAngle)) * m_fSpeed;

	return 0;
}

void Straight_horizontal::Render(HDC hDC)
{

	Bmp* pBmp = BmpMgr::GetInstance()->FindImage(L"¸ó½ºÅÍÃÑ¾Ë2");

	if (pBmp == nullptr)
		return;

	GdiTransparentBlt(hDC, (int)m_tRect.left, (int)m_tRect.top
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, pBmp->GetMemDC()
		, (int)m_tFrame.iFrameStart * (int)m_tInfo.fCX, (int)m_tFrame.iScene * (int)m_tInfo.fCY
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, RGB(1, 1, 1));


	//Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void Straight_horizontal::Release()
{
}
