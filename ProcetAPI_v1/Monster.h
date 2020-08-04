#pragma once
#include "Obj.h"
class Monster :
	public Obj
{
public:
	Monster();
	virtual ~Monster();

public:
	// Obj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	void SetDir(DIRECTION eID) { m_eDir = eID; }

private:
	template <typename T>
	Obj* CreateBullet(float fAngle)
	{
		return AbstractFactroy<T>::CreateObj(m_tInfo.fX, m_tInfo.fY, fAngle);
	}

	template <typename T>
	Obj* CreateBullet(float fX, float fY)
	{
		return AbstractFactroy<T>::CreateObj(m_tInfo.fX, m_tInfo.fY, fX, fY);
	}



private:
	DWORD		m_dwOldTime;
	DWORD		m_dwCurTime = 1000;
	DIRECTION	m_eDir;
};

