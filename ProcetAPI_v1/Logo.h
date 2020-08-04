#pragma once
#include "Scene.h"
class Logo :
	public Scene
{
public:
	Logo();
	virtual ~Logo();

public:
	// Scene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	DWORD	m_dwOldTime = 0;
	DWORD	m_dwCurTime = 5000;
};

