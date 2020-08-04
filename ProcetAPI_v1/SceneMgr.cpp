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

// State ����(���� ����)
// FSM(���� ���� �ӽ�)�� ���̽��� �ϴ� ����
// Ŭ������ �����Ͽ� ���, ������ ���� ������Ѽ� ����� �����ϰ� ������ ����.

// FSM(���� ���� �ӽ�): ��� Ȥ�� ��ġ�� ������ �Ѱ��� ���۸� ���� �ִ´�.


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
