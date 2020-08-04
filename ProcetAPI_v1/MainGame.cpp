#include "stdafx.h"
#include "MainGame.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	/*SoundMgr::GetInstance()->PlayBGM(L"Eastern_Night.wav");*/
	
	SceneMgr::GetInstance()->SceneChange(SceneMgr::LOGO);

}

void MainGame::Update()
{
	SceneMgr::GetInstance()->Update();
	ScrollMgr::GetInstance()->Update();
	KeyMgr::GetInstance()->Update();
}

void MainGame::Render()
{
	SceneMgr::GetInstance()->Render(m_hDC);
}

void MainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	KeyMgr::GetInstance()->DestroyInstance();
	ScrollMgr::GetInstance()->DestroyInstance();
	SoundMgr::GetInstance()->DestroyInstance();
	BmpMgr::GetInstance()->DestroyInstance();

}
