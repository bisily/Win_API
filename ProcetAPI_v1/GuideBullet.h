#pragma once
#include "Obj.h"
class GuideBullet :
	public Obj
{
public:
	GuideBullet();
	virtual ~GuideBullet();

public:
	// Obj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	Obj*		m_pTarget = nullptr;
	float		m_fDisX;
	float		m_fDisY;

	DWORD		dwOldTime = 0;
	DWORD		dwLifeTime = 2000;
	DWORD		dwMoveTime = 200;
};

