#pragma once

#define MAX_VIRTUAL_KEY 0xFF

class KeyMgr
{
	DECLARE_SINGLETON(KeyMgr)

private:
	KeyMgr();
	~KeyMgr();

public:
	bool GetKeyPreesing(int iKey);
	bool GetKeyDown(int iKey);
	bool GetKeyUp(int iKey);

public:
	void Update();

private:
	bool m_bKey[MAX_VIRTUAL_KEY];
};

#define KEY_PRESSING(iKey) KeyMgr::GetInstance()->GetKeyPreesing(iKey)

#define KEY_UP(iKey) KeyMgr::GetInstance()->GetKeyUp(iKey)

#define KEY_DOWN(iKey) KeyMgr::GetInstance()->GetKeyUp(iKey)