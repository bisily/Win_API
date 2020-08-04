#pragma once
#include "Obj.h"
class Straight_horizontal :
	public Obj
{
public:
	Straight_horizontal();
	~Straight_horizontal();

public:
	// Obj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

