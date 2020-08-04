#include "stdafx.h"
#include "Parabola.h"


Parabola::Parabola()
{
}


Parabola::~Parabola()
{
}

void Parabola::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;
	m_tColli = { 30.f, 30.f };
	m_iAtt = 1;
	m_fSpeed = 2.f;
	m_bDead = false;

	m_tFrame = { 0, 0, 0, 100, GetTickCount(), 0 };
}

int Parabola::Update()
{
	if (m_bDead)
		return 1;

	Obj::Update();

	if (m_tRect.left < 30 || m_tRect.top < 30 || m_tRect.right > 460 || m_tRect.bottom > 620)
		return 1;

	m_fAngle;

	m_tInfo = PatternMgr::GetInstance()->Parabola(this, m_fAngle);

	m_fAngle += m_fSpeed;

	return 0;
}

void Parabola::Render(HDC hDC)
{

	Bmp* pBmp = BmpMgr::GetInstance()->FindImage(L"BossÃÑ¾Ë2");

	if (pBmp == nullptr)
		return;

	GdiTransparentBlt(hDC, (int)m_tRect.left, (int)m_tRect.top
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, pBmp->GetMemDC()
		, (int)m_tFrame.iFrameStart * (int)m_tInfo.fCX, (int)m_tFrame.iScene * (int)m_tInfo.fCY
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, RGB(1, 1, 1));

	//Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void Parabola::Release()
{
}
