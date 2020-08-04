#pragma once

#include "Bmp.h"

class BmpMgr
{
	DECLARE_SINGLETON(BmpMgr)

public:
	typedef map<const TCHAR*, Bmp*> MAPBIT;

private:
	BmpMgr();
	~BmpMgr();

public:
	MAPBIT& GetMapBit() { return m_MapBit; }
	void LoadByScene(SceneMgr::SceneID eID);

public:
	Bmp* FindImage(const TCHAR* pImageKey);

private:
	MAPBIT	m_MapBit;
};

