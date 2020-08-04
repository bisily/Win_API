#pragma once
class Obj
{
public:
	Obj();
	virtual ~Obj();

public:
	void SetPos(float fX, float fY) { m_tInfo.fX = fX, m_tInfo.fY = fY; }
	void SetX(float fX) { m_tInfo.fX += fX; }
	void SetY(float fY) { m_tInfo.fY += fY; }
	void SetAngle(float fAngle) { m_fAngle = fAngle; }
	void SetDamage(int Att) { m_iHP -= Att; }
	void SetDead() { m_bDead = true; }

public:
	bool GetDead() { return m_bDead; }
	const RECT& GetRect() const { return m_tRect; }
	const INFO& GetInfo() const { return m_tInfo; }
	const RECT& GetCheck() const { return m_tCheck; }
	const COLLI& GetColli() const { return m_tColli; }
	const float GetSpeed() const { return m_fSpeed; }
	const int GetAtt() { return m_iAtt; }

public:
	virtual void Initialize() = 0;
	virtual int Update();
	virtual void Render(HDC hDC) = 0;
	virtual void Release() = 0;

public:
	void IsAnimatime();

protected:
	INFO	m_tInfo;
	RECT	m_tRect;
	COLLI	m_tColli;
	RECT	m_tCheck;
	FRAME	m_tFrame;

	float	m_fSpeed;
	float	m_fAngle;
	bool	m_bDead;

	int		m_iHP;
	int		m_iAtt;
};

