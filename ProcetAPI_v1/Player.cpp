#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "GuideBullet.h"

Player::Player()
{
}


Player::~Player()
{
}

void Player::Initialize()
{

	/*BmpMgr::GetInstance()->GetMapBit().insert(make_pair(L"Player"
		, (new Bmp)->LoadBmp(L"../Image/유카리.bmp")));*/


	m_tInfo = { 240.f, 550.f, 32.5f, 50.f };
	m_tColli = { 25.f, 25.f };
	m_fSpeed = 10.f;
	m_fAngle = 90;
	m_iHP = 1;
	m_iBomb = 3;
	m_iPower = 3;
	m_bDead = false;

	m_tFrame = { 0, 3, 0, 120, GetTickCount(), 0 };
}

int Player::Update()
{

	if (m_iHP <= 0)
		return 1;

	Obj::Update();

	// 플레이어 중심좌표로 계속 초기화 해줌
	m_fJudgmentX = m_tInfo.fX;
	m_fJudgmentY = m_tInfo.fY;

	KeyCheck();
	SceneChange();
	IsAnimatime();


	return 0;
}

void Player::Render(HDC hDC)
{
	Obj::Update();
	
	Bmp* pBmp = BmpMgr::GetInstance()->FindImage(m_pImageKey);

	if (pBmp == nullptr)
		return;

	GdiTransparentBlt(hDC, (int)m_tRect.left, (int)m_tRect.top
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, pBmp->GetMemDC()
		, (int)m_tFrame.iFrameStart * (int)m_tInfo.fCX, (int)m_tFrame.iScene * (int)m_tInfo.fCY
		, (int)m_tInfo.fCX, (int)m_tInfo.fCY, RGB(1, 1, 1));

	if (KEY_PRESSING(VK_SHIFT))
	{
		Ellipse(hDC, m_tCheck.left, m_tCheck.top, m_tCheck.right, m_tCheck.bottom);
	}

	//Ellipse(hDC, m_fJudgmentX - 5, m_fJudgmentY - 5, m_fJudgmentX + 5, m_fJudgmentY + 5);

	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

}

void Player::Release()
{
}

void Player::KeyCheck()
{
	// 이동 관련 키조작
	if (KEY_PRESSING(VK_LEFT))
	{
		m_eCurState = LEFT;
		if (KEY_PRESSING(VK_UP))
		{
			m_tInfo.fX -= m_fSpeed / sqrt(2.f);
			m_tInfo.fY -= m_fSpeed / sqrt(2.f);
		}
		else if (KEY_PRESSING(VK_DOWN))
		{
			m_tInfo.fX -= m_fSpeed / sqrt(2.f);
			m_tInfo.fY += m_fSpeed / sqrt(2.f);
		}

		else
			m_tInfo.fX -= m_fSpeed;
	}
	else if (KEY_PRESSING(VK_RIGHT))
	{
		m_eCurState = RIGHT;
		if (KEY_PRESSING(VK_UP))
		{
			m_tInfo.fX += m_fSpeed / sqrt(2.f);
			m_tInfo.fY -= m_fSpeed / sqrt(2.f);
		}
		else if (KEY_PRESSING(VK_DOWN))
		{
			m_tInfo.fX += m_fSpeed / sqrt(2.f);
			m_tInfo.fY += m_fSpeed / sqrt(2.f);

		}
		else
			m_tInfo.fX += m_fSpeed;
	}
	else if (KEY_PRESSING(VK_UP))
		m_tInfo.fY -= m_fSpeed;
	else if (KEY_PRESSING(VK_DOWN))
		m_tInfo.fY += m_fSpeed;
	else
		m_eCurState = IDLE;

	// 스피드 감소
	if (KEY_PRESSING(VK_SHIFT))
		m_fSpeed = 5;
	else
		m_fSpeed = 10;

	// 총알을 발사
	if (KEY_DOWN(0x5A))
	{
		if (1 == m_iPower)
		{
			float fX = m_tInfo.fX;
			if (50 > m_tInfo.fX)
				fX = 50;
			else if (432 < fX)
				fX = 432;

			ObjectMgr::GetInstance()->AddObject(CreateBullet<GuideBullet>(fX, 90.f), OBJ_BULLET);
		}
		
		else if (2 == m_iPower)
		{
			float fX = m_tInfo.fX;
			if (50 > m_tInfo.fX)
				fX = 50;
			else if (432 < fX)
				fX = 432;

			// 일반 탄환
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Bullet>(fX, 85.f), OBJ_BULLET);
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Bullet>(fX, 95.f), OBJ_BULLET);

			// 유도 탄환
			ObjectMgr::GetInstance()->AddObject(CreateBullet<GuideBullet>(fX, 90.f), OBJ_BULLET);
		}

		else if (3 == m_iPower)
		{
			float fX = m_tInfo.fX;
			if (50 > m_tInfo.fX)
				fX = 50;
			else if (432 < fX)
				fX = 432;

			// 일반 탄환
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Bullet>(fX, 90.f), OBJ_BULLET);
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Bullet>(fX, 75.f), OBJ_BULLET);
			ObjectMgr::GetInstance()->AddObject(CreateBullet<Bullet>(fX, 105.f), OBJ_BULLET);

			// 유도 탄환
			ObjectMgr::GetInstance()->AddObject(CreateBullet<GuideBullet>(fX, 60.f), OBJ_BULLET);
			ObjectMgr::GetInstance()->AddObject(CreateBullet<GuideBullet>(fX, 120.f), OBJ_BULLET);
		}
	}

}

void Player::SceneChange()
{
	if (m_ePrevState != m_eCurState)
	{
		switch (m_eCurState)
		{
		case IDLE:
			m_tFrame = { 0, 3, 0, 100, GetTickCount(), 0 };
			break;
		case LEFT:
			m_tFrame = { 0, 6, 1, 100, GetTickCount(), 0 };
			break;
		case RIGHT:
			m_tFrame = { 0, 6, 2, 100, GetTickCount(), 0 };
			break;
		}

		m_ePrevState = m_eCurState;
	}
}
