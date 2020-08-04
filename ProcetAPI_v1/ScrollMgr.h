#pragma once
class ScrollMgr
{
	DECLARE_SINGLETON(ScrollMgr)
private:
	ScrollMgr();
	~ScrollMgr();

public:
	float GetScrollY() { return m_fScrollY; }

public:
	void Update();

private:
	float m_fScrollX = 0.f;
	float m_fScrollY = 0.f;
	float m_fOffSet = 250.f;
};

