#include "stdafx.h"
#include "PlayerRockOn.h"


PlayerRockOn::PlayerRockOn()
{
}


PlayerRockOn::~PlayerRockOn()
{
}

void PlayerRockOn::Initialize()
{
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;
	m_bDead = false;

	m_fSpeed = 5.f;
	m_iAtt = 1;
}


int PlayerRockOn::Update()
{
	if (m_bDead)
		return 1;

	Obj::Update();

	if (m_tRect.left < 30 || m_tRect.top < 30 || m_tRect.right > 447 || m_tRect.bottom > 600)
		return 1;
	
	//m_tInfo = PatternMgr::GetInstance()->AngleLine(this, m_fAngle);

	m_fTX += cosf(m_fAngle * PI / 180.f) * m_fSpeed;
	m_fTY -= sinf(m_fAngle * PI / 180.f) * m_fSpeed;

	return 0;
}

void PlayerRockOn::Render(HDC hDC)
{
	Obj::Update();

	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void PlayerRockOn::Release()
{
}
