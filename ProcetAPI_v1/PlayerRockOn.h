#pragma once
#include "Obj.h"
class PlayerRockOn :
	public Obj
{
public:
	PlayerRockOn();
	virtual ~PlayerRockOn();

public:
	void SetTargetPos(float _fX, float _fY) { m_fTX = _fX, m_fTY = _fY; }

public:
	// Obj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	float		m_fTX;
	float		m_fTY;

	float		m_fDis;
	float		m_fWidth;
	float		m_fHeigt;
};

