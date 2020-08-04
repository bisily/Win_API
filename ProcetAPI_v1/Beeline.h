#pragma once
#include "Obj.h"
class Beeline :
	public Obj
{
public:
	Beeline();
	virtual ~Beeline();

public:
	// Obj을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

