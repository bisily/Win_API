#pragma once
#include "Obj.h"
class Parabola :
	public Obj
{
public:
	Parabola();
	virtual ~Parabola();

public:
	// Obj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	float		m_fAcc = 0.f;
	float		m_fPow = 15.f;
};

