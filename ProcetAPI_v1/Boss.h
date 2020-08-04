#pragma once
#include "Obj.h"
class Boss :
	public Obj
{
public:
	Boss();
	virtual ~Boss();

private:
	enum Stance { IDLE, RIGHT, LEFT, STANCE_END };
	enum PATTERN { CIRCLE, TWO, THREE, END };

public:
	// Obj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	void SceneChange();
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

	Stance	m_eCurState = IDLE;
	Stance	m_ePrevState = IDLE;
	
	DWORD		m_dwCounter;
	DWORD		m_dwOldCounter = 5000;
	int			pattern = 1;


	bool		m_bPatter_1 = false;
	DWORD		dwOldTime_1;
	DWORD		dwCurTime_1 = 300;
	DWORD		dwRateTime_1 = 0;
	DWORD		dwLoedTime_1 = 10000;
	float		m_fAngle_2;
	float		m_fAngle_3;
	float		m_fAngle_4;
	int			m_iA;

	bool		m_bPatter_2 = false;
	DWORD		dwOldTime_2;
	DWORD		dwCurTime_2 = 300;

	bool		m_bPatter_3 = false;
	DWORD		dwOldTime_3;
	DWORD		dwCurTime_3 = 10000;
	int			Line = 0;
	float		m_fAngle_5 = 240;


	PATTERN		m_eID = TWO;
};

