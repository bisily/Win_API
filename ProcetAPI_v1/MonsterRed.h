#pragma once
#include "Obj.h"
class MonsterRed :
	public Obj
{
public:
	MonsterRed();
	virtual ~MonsterRed();

public:
	// Obj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	template <typename T>
	Obj* CreateBullet(float fAngle)
	{
		return AbstractFactroy<T>::CreateObj(m_tInfo.fX, m_tInfo.fY, fAngle);
	}

public:
	void SetDir(DIRECTION eID) { m_eDir = eID; }

private:
	DWORD		m_dwOldTime;
	DWORD		m_dwCurTime = 1000;
	DIRECTION	m_eDir;
};

