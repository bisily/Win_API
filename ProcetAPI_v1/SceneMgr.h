#pragma once

class Scene;
class SceneMgr
{
	DECLARE_SINGLETON(SceneMgr)

public:
	enum SceneID { LOGO, MENU, EDIT, STAGE, ENDING, END };

private:
	SceneMgr();
	~SceneMgr();

public:
	SceneID GetCurScene() { return m_eCurScene; }

public:
	void SceneChange(SceneID eScene);
	void Update();
	void Render(HDC hDC);
	void Release();

private:
	Scene*		m_pScene;
	SceneID		m_eCurScene;
};

