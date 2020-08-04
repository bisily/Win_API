#include "stdafx.h"
#include "ScrollMgr.h"
#include "Obj.h"

IMPLEMENT_SINGLETON(ScrollMgr)

ScrollMgr::ScrollMgr()
{
}


ScrollMgr::~ScrollMgr()
{
}

void ScrollMgr::Update()
{
	Obj* pTarget = ObjectMgr::GetInstance()->FindObject(OBJ_PLAYER);

	if (nullptr == pTarget)
		return;

	if (m_fScrollY < 1480)
	{
		m_fScrollY += 1;
	}

	//if (m_fOffSet + 200.f < pTarget->GetInfo().fY + m_fScrollY)
	//	m_fScrollY -= 10.f;

	//if (m_fOffSet - 200.f > pTarget->GetInfo().fY + m_fScrollY)
	//	m_fScrollY += 10.f;

}
