#pragma once
#include "Scene.h"
class Stage :
	public Scene
{
public:
	Stage();
	virtual ~Stage();

public:
	// Scene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	DWORD		dwOldTime = 0;
	DWORD		dwCurTime = 5000;
	int			MonsterCnt = 0;

	DWORD		dwOldTimeRed = 0;
	DWORD		dwCurTimeRed = 15000;
	int			MonsterRedCnt = 0;

	bool		IsExist = false;
	DWORD		dwBossTime = 0;
	DWORD		dwBirthTime = 50000;
};

