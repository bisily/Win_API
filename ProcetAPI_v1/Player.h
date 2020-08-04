#pragma once
#include "Obj.h"

class Player :
	public Obj
{
public:
	Player();
	virtual ~Player();

public:
	enum Stance { IDLE, RIGHT, LEFT, END };

public:
	void UseBomb() { --m_iBomb; }

public:
	// Obj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	void KeyCheck();
	void SceneChange();

private:
	template <typename T>
	Obj* CreateBullet(float fX, float fAngle)
	{
		return AbstractFactroy<T>::CreateObj(fX, m_tInfo.fY, fAngle);
	}

private:
	int		m_iBomb;
	TCHAR*	m_pImageKey = L"Player";
	Stance	m_eCurState = IDLE;
	Stance	m_ePrevState = IDLE;
	float	m_fJudgmentX;
	float	m_fJudgmentY;
	int		m_iPower = 1;
};

