#pragma once
#include "Obj.h"
class Straight :
	public Obj
{
public:
	Straight();
	~Straight();

public:
	// Obj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

