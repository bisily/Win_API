#include "stdafx.h"
#include "SceneMgr.h"
#include "Logo.h"
#include "Stage.h"
#include "Menu.h"
#include "Edit.h"

IMPLEMENT_SINGLETON(SceneMgr)

SceneMgr::SceneMgr()
	: m_pScene(nullptr)
	, m_eCurScene(END)
{
}

// State 패턴(상태 패턴)
// FSM(유한 상태 머신)을 베이스로 하는 패턴
// 클래스를 도입하여 상속, 다형성 등을 접목시켜서 더욱더 유연하게 패턴을 구성.

// FSM(유한 상태 머신): 기계 혹은 장치는 오로지 한가지 동작만 갖고 있는다.


SceneMgr::~SceneMgr()
{
	Release();
}

void SceneMgr::SceneChange(SceneID eScene)
{
	if (m_eCurScene != eScene)
	{
		SafeDelete<Scene*>(m_pScene);

		switch (eScene)
		{
		case SceneMgr::LOGO:
			m_pScene = new Logo;
			break;
		case SceneMgr::MENU:
			m_pScene = new Menu;
			break;
		case SceneMgr::EDIT:
			break;
		case SceneMgr::STAGE:
			m_pScene = new Stage;
			break;
		case SceneMgr::ENDING:
			break;
		}

		if (nullptr == m_pScene)
			return;

		m_pScene->Initialize();
		m_eCurScene = eScene;
	}
}

void SceneMgr::Update()
{
	if (nullptr == m_pScene)
		return;

	m_pScene->Update();
}

void SceneMgr::Render(HDC hDC)
{
	if (nullptr == m_pScene)
		return;

	m_pScene->Render(hDC);
}

void SceneMgr::Release()
{
	SafeDelete<Scene*>(m_pScene);
}
