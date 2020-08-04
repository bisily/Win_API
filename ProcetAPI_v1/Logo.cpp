#include "stdafx.h"
#include "Logo.h"


Logo::Logo()
{
}


Logo::~Logo()
{
	Release();
}

void Logo::Initialize()
{
	BmpMgr::GetInstance()->LoadByScene(SceneMgr::LOGO);

	m_dwOldTime = GetTickCount();
}

void Logo::Update()
{
	if (m_dwOldTime + m_dwCurTime < GetTickCount())
		SceneMgr::GetInstance()->SceneChange(SceneMgr::MENU);
	if(KEY_DOWN(VK_RETURN))
		SceneMgr::GetInstance()->SceneChange(SceneMgr::MENU);
}

void Logo::Render(HDC hDC)
{
	Bmp* pBmp = BmpMgr::GetInstance()->FindImage(L"Logo_2");

	if (nullptr != pBmp)
	{
		BitBlt(hDC, 0, 0, WINCX, WINCY,
			pBmp->GetMemDC(), 0, 0, SRCCOPY);
	}

	pBmp = BmpMgr::GetInstance()->FindImage(L"Logo_Moon");

	RECT rc = { 0, 0, 85, 85 };
	
	if (nullptr != pBmp)
	{
		GdiTransparentBlt(hDC, 550, 580, 85, 85
			, pBmp->GetMemDC(), rc.left, rc.top, rc.right, rc.bottom, RGB(1, 1, 1));
	}

	/*BitBlt(hDC, 700, 500, 85, 85,
		pBmp->GetMemDC(), 0, 0, )*/

}

void Logo::Release()
{
}
