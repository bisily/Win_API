#pragma once
#include "Obj.h"
class Straight_horizontal :
	public Obj
{
public:
	Straight_horizontal();
	~Straight_horizontal();

public:
	// Obj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

