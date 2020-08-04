#include "stdafx.h"
#include "Menu.h"


Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::Initialize()
{
	BmpMgr::GetInstance()->LoadByScene(SceneMgr::MENU);
}

void Menu::Update()
{
	if (KEY_DOWN(VK_RETURN))
		SceneMgr::GetInstance()->SceneChange(SceneMgr::STAGE);

}

void Menu::Render(HDC hDC)
{
	Bmp* pBmp = BmpMgr::GetInstance()->FindImage(L"Title");

	if (nullptr != pBmp)
	{
		BitBlt(hDC, 0, 0, WINCX, WINCY,
			pBmp->GetMemDC(), 0, 0, SRCCOPY);
	}
}

void Menu::Release()
{
}
