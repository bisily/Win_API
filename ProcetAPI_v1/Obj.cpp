#include "stdafx.h"
#include "Obj.h"


Obj::Obj()
	: m_tInfo{}
	, m_tRect{}
	, m_fSpeed(0.f)
	, m_fAngle(0.f)
	, m_bDead(true)
	, m_iHP(0)
	, m_iAtt(0)
{
}


Obj::~Obj()
{
}

int Obj::Update()
{
	m_tRect.left	= LONG(m_tInfo.fX - m_tInfo.fCX / 2);
	m_tRect.top		= LONG(m_tInfo.fY - m_tInfo.fCY / 2);
	m_tRect.right	= LONG(m_tInfo.fX + m_tInfo.fCX / 2);
	m_tRect.bottom	= LONG(m_tInfo.fY + m_tInfo.fCY / 2);

	m_tCheck.left	= LONG(m_tInfo.fX - m_tColli.fCX / 4);
	m_tCheck.top	= LONG(m_tInfo.fY - m_tColli.fCY / 4);
	m_tCheck.right	= LONG(m_tInfo.fX + m_tColli.fCX / 4);
	m_tCheck.bottom	= LONG(m_tInfo.fY + m_tColli.fCY / 4);
	return 0;
}

void Obj::IsAnimatime()
{
	m_tFrame.dwFrameCur = GetTickCount();

	if (m_tFrame.dwFrameOld + m_tFrame.dwFrameSpd < m_tFrame.dwFrameCur)
	{
		m_tFrame.iFrameStart++;
		m_tFrame.dwFrameOld = m_tFrame.dwFrameCur;
	}

	if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
		m_tFrame.iFrameStart = 0;

}
