#include "stdafx.h"
#include "Beeline.h"


Beeline::Beeline()
{
}


Beeline::~Beeline()
{
}

void Beeline::Initialize()
{
	m_tInfo.fCX = 16.f;
	m_tInfo.fCY = 15.f;
	m_tColli = { 12.f, 12.f };
	m_bDead = false;
	m_iHP = 1;

	m_fSpeed = 2.f;

	m_tFrame = { 0, 0, 0, 120, GetTickCount(), 0 };
}

int Beeline::Update()
{
	if (m_bDead)
		return 1;

	Obj::Update();

	if (m_tRect.left < 30 || m_tRect.top < 30 || m_tRect.right > 447 || m_tRect.bottom > 600)
		return 1;

	m_tInfo.fY -= sinf(m_fAngle * PI / 180.f) * m_fSpeed;
	
	return 0;
}

void Beeline::Render(HDC hDC)
{
	Obj::Update();

	Bmp* pBmp = BmpMgr::GetInstance()->FindImage(L"¸ó½ºÅÍÃÑ¾Ë");

	if (pBmp == nullptr)
		return;

	GdiTransparentBlt(hDC, (int)m_tRect.left, (int)m_tRect.top
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, pBmp->GetMemDC()
		, (int)m_tFrame.iFrameStart * (int)m_tInfo.fCX, (int)m_tFrame.iScene * (int)m_tInfo.fCY
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, RGB(1, 1, 1));

	//Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void Beeline::Release()
{
}
