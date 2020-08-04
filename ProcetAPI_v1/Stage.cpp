#include "stdafx.h"
#include "Stage.h"
#include "Player.h"
#include "Monster.h"
#include "MonsterRed.h"
#include "Boss.h"
#include "Parabola.h"

Stage::Stage()
{
}


Stage::~Stage()
{
}

void Stage::Initialize()
{
	srand(unsigned int(time(NULL)));

	BmpMgr::GetInstance()->LoadByScene(SceneMgr::STAGE);

	ObjectMgr::GetInstance()->AddObject(
		AbstractFactroy<Player>::CreateObj()
		, OBJ_PLAYER);

	dwOldTime = GetTickCount();
	dwOldTimeRed = GetTickCount(); 
	dwBossTime = GetTickCount();
}

void Stage::Update()
{
	
	// 5초마다 생성
	//if (dwOldTime + dwCurTime < GetTickCount() && MonsterCnt < 8)
	//{
		// 몬스터를 만든 횟수 
		//++MonsterCnt;

	if (KEY_DOWN('2'))
	{
		// 몬스터 생성 범이 X 50 + @ ~ 100, Y 60 + @ ~ 100
		float fX = float(50 + rand() % 100);
		float fY = float(60 + rand() % 100);

		dwOldTime = GetTickCount();
		ObjectMgr::GetInstance()->AddObject(
			AbstractFactroy<Monster>::CreateObj(fX, fY, DIRECTION::RIGHT)
			, OBJ_MONSTER);

		fX =float(300 + rand() % 100);
		fY = float(60 + rand() % 100);

		ObjectMgr::GetInstance()->AddObject(
			AbstractFactroy<Monster>::CreateObj(fX, fY, DIRECTION::LEFT)
			, OBJ_MONSTER);
	}
	//}

	// 빨간 몬스터 15초 마다 생성
	//if (dwOldTimeRed + dwCurTimeRed < GetTickCount() && MonsterCnt < 3)
	//{
		//++MonsterRedCnt;
	if (KEY_DOWN('3'))
	{

		dwOldTimeRed = GetTickCount();
		ObjectMgr::GetInstance()->AddObject(
			AbstractFactroy<MonsterRed>::CreateObj(100.f, 60.f, DIRECTION::RIGHT)
			, OBJ_MONSTER);

		ObjectMgr::GetInstance()->AddObject(
			AbstractFactroy<MonsterRed>::CreateObj(400.f, 60.f, DIRECTION::LEFT)
			, OBJ_MONSTER);
	}
	//}

	//if (!IsExist && dwBossTime + dwBirthTime < GetTickCount())
	//{
	//	IsExist = true;
	
	if (KEY_DOWN('1'))
	{
		ObjectMgr::GetInstance()->AddObject(
			AbstractFactroy<Boss>::CreateObj()
			, OBJ_BOSS);
	}
	//}

	ObjectMgr::GetInstance()->Update();
}

void Stage::Render(HDC hDC)
{
	// 후면 버퍼를 얻어온다.
	Bmp* pBmp = BmpMgr::GetInstance()->FindImage(L"BackBuffer");

	if (nullptr == pBmp)
		return;

	HDC hBackBuff = pBmp->GetMemDC();

	pBmp = BmpMgr::GetInstance()->FindImage(L"BackGround");

	if (nullptr == pBmp)
		return;

	BitBlt(hBackBuff, 0, 0, WINCX, WINCY, pBmp->GetMemDC(), 0, 0, SRCCOPY);

	pBmp = BmpMgr::GetInstance()->FindImage(L"StageBack");

	if (nullptr == pBmp)
		return;


	RECT rc = { 0, 1480, 420, 2000 };

	//Rectangle(hBackBuff, 0, 0, WINCX, WINCY);
	BitBlt(hBackBuff, 30, 30, 420, 570, pBmp->GetMemDC(), 0, 2000, SRCCOPY);

	// 스테이지 배경 이미지를 움직여주는 값
	float fScrollY = ScrollMgr::GetInstance()->GetScrollY();

	GdiTransparentBlt(hBackBuff, 30, 30 , 420, 570
	, pBmp->GetMemDC(), (int)rc.left, (int)rc.top - (int)fScrollY, (int)rc.right, (int)rc.bottom, RGB(1, 1, 1));

		
	ObjectMgr::GetInstance()->Render(hBackBuff);
	
	BitBlt(hDC, 0, 0, WINCX, WINCY, hBackBuff, 0, 0, SRCCOPY);


}

void Stage::Release()
{
}
