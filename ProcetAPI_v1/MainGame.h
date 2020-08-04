#pragma once

class Obj;
class MainGame
{
public:
	MainGame();
	~MainGame();

public:
	void Initialize();
	void Update();
	void Render();
	void Release();

private:
	HDC		m_hDC;
	Obj*	m_pPlayer; 
	
	RECT LEFT_FIELD = { 28, 30, 30, 600 };
	RECT TOP_FIELD = { 28, 28, 450, 30 };
	RECT RIGHT_FIELD = { 448, 28, 450, 600 };
	RECT BOTTOM_FIELD = { 28, 598, 450, 600 };
};

