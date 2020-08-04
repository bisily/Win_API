#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
	Release();
}

void Bullet::Initialize()
{
	m_tInfo.fCX = 15.f;
	m_tInfo.fCY = 15.f;
	m_tColli = { 10.f, 10.f };
	m_bDead = false;
	m_iHP = 1;

	m_fSpeed = 12.f;
	m_iAtt = 1;

	m_tFrame = { 0, 0, 0, 100, GetTickCount(), 0 };
}

int Bullet::Update()
{
	if (m_bDead)
		return 1;

	Obj::Update();

	if (m_tRect.left < 30 || m_tRect.top < 30 || m_tRect.right > 447 || m_tRect.bottom > 600)
		return 1;

	m_tInfo.fX += cosf(m_fAngle * PI / 180.f) * m_fSpeed;
	m_tInfo.fY -= sinf(m_fAngle * PI / 180.f) * m_fSpeed;

	return 0;
}

void Bullet::Render(HDC hDC)
{
	Obj::Update();

	Bmp* pBmp = BmpMgr::GetInstance()->FindImage(L"Bullet");

	if (pBmp == nullptr)
		return;

	//BitBlt(hBackBuff, 0, 0, WINCX, WINCY, pBmp->GetMemDC(), 0, 0, SRCCOPY);
	
	BitBlt(hDC, m_tInfo.fX, m_tInfo.fY, m_tInfo.fCX, m_tInfo.fCY, pBmp->GetMemDC(), 0, 0, SRCCOPY);

	//GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, (int)m_tInfo.fCX, (int)m_tInfo.fCY
	//	, pBmp->GetMemDC(), m_tFrame.iFrameStart * (int)m_tInfo.fCX, m_tFrame.iScene * (int)m_tInfo.fCY
	//	, (int)m_tInfo.fCX, (int)m_tInfo.fCY, RGB(1, 1, 1));

	//Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

}

void Bullet::Release()
{
}
