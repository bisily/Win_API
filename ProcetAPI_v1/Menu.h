#pragma once
#include "Scene.h"
class Menu :
	public Scene
{
public:
	Menu();
	virtual ~Menu();

public:
	// Scene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
};

