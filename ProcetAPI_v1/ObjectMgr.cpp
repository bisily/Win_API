#include "stdafx.h"
#include "ObjectMgr.h"
#include "Obj.h"

IMPLEMENT_SINGLETON(ObjectMgr)

ObjectMgr::ObjectMgr()
{
}


ObjectMgr::~ObjectMgr()
{
	Release();
}

Obj * ObjectMgr::FindTarget(Obj * pSrc, OBJID eID)
{
	if (m_ObjectList[eID].empty())
		return nullptr;

	Obj* pTarget = m_ObjectList[eID].front();
	float fDist = MathMgr::CalcDistance(pTarget, pSrc);

	for (auto dest : m_ObjectList[eID])
	{
		float fCmpDist = MathMgr::CalcDistance(dest, pSrc);

		if (fCmpDist < fDist)
		{
			pTarget = dest;
			fDist = fCmpDist;
		}
	}

	return pTarget;
}


void ObjectMgr::AddObject(Obj * pObj, OBJID eID)
{
	m_ObjectList[eID].push_back(pObj);
}

void ObjectMgr::Update()
{
	// 이터레이터 패턴을 이용하면 CObj를 상속받는 자식들을 한번에 관리할 수 있다.
	for (int i = 0; i < OBJ_END; ++i)
	{
		OBJITER begin = m_ObjectList[i].begin();
		OBJITER end = m_ObjectList[i].end();

		for (; begin != end; )
		{
			int iEvent = (*begin)->Update();

			if (OBJ_EVENT_DEAD == iEvent)
			{
				SafeDelete<Obj*>(*begin);
				begin = m_ObjectList[i].erase(begin);

			}
			else if (2 == iEvent)
			{

			}
			else
				++begin;
		}
	}

	CollisionMgr::CollisionGround(*m_ObjectList[OBJ_PLAYER].back());
	CollisionMgr::CollisionSphere(m_ObjectList[OBJ_BULLET], m_ObjectList[OBJ_MONSTER]);

	//if(!m_ObjectList[OBJ_PLAYER].empty())
	//	CollisionMgr::CollisionSphere(m_ObjectList[OBJ_MONSTER_BULLET], m_ObjectList[OBJ_PLAYER]);
}

void ObjectMgr::Render(HDC hDC)
{
	// 이터레이터 패턴을 이용하면 CObj를 상속받는 자식들을 한번에 관리할 수 있다.
	for (int i = 0; i < OBJ_END; ++i)
	{
		OBJITER begin = m_ObjectList[i].begin();
		OBJITER end = m_ObjectList[i].end();

		for (; begin != end; ++begin)
			(*begin)->Render(hDC);
	}

	// 왼쪽
	Rectangle(hDC, LEFT_FIELD.left, LEFT_FIELD.top, LEFT_FIELD.right, LEFT_FIELD.bottom);
	// 위쪽
	Rectangle(hDC, TOP_FIELD.left, TOP_FIELD.top, TOP_FIELD.right, TOP_FIELD.bottom);
	// 오른쪽
	Rectangle(hDC, RIGHT_FIELD.left, RIGHT_FIELD.top, RIGHT_FIELD.right, RIGHT_FIELD.bottom);
	// 아래쪽
	Rectangle(hDC, BOTTOM_FIELD.left, BOTTOM_FIELD.top, BOTTOM_FIELD.right, BOTTOM_FIELD.bottom);
}

void ObjectMgr::Release()
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjectList[i].begin(), m_ObjectList[i].end(),
		[](Obj*& pObj)
		{
			if (pObj)
			{
				delete pObj;
				pObj = nullptr;
			}
		});

		m_ObjectList[i].clear();
	}
}

void ObjectMgr::ReleaseObj(OBJID eID)
{
	for_each(m_ObjectList[eID].begin(), m_ObjectList[eID].end(),
		[](Obj*& pObj)
	{
		if (pObj)
		{
			delete pObj;
			pObj = nullptr;
		}
	});

	m_ObjectList[eID].clear();
}
