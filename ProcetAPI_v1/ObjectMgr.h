#pragma once

class Obj;
class ObjectMgr
{
	DECLARE_SINGLETON(ObjectMgr)
private:
	ObjectMgr();
	~ObjectMgr();

public:
	Obj* FindObject(OBJID eID)
	{
		if (m_ObjectList[eID].empty())
			return nullptr;
		
		return m_ObjectList[eID].back();
	}

	Obj* FindTarget(Obj* pSrc, OBJID eID);
	OBJLIST& GetList(OBJID eID) { return m_ObjectList[eID]; }

public:
	void AddObject(Obj* pObj, OBJID eID);
	void Update();
	void Render(HDC hDC);
	void Release();
	void ReleaseObj(OBJID eID);

private:
	// 이터레이터 패턴
	OBJLIST		m_ObjectList[OBJ_END];
	int			m_MonsterCnt = 8;
	RECT		LEFT_FIELD = { 28, 30, 30, 600 };
	RECT		TOP_FIELD = { 28, 28, 450, 30 };
	RECT		RIGHT_FIELD = { 448, 28, 450, 600 };
	RECT		BOTTOM_FIELD = { 28, 598, 450, 600 };
};

