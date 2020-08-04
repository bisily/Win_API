#pragma once
#include "Obj.h"
class Bullet :
	public Obj
{
public:
	Bullet();
	virtual ~Bullet();

public:
	// Obj��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

