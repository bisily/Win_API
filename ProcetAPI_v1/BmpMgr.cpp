#include "stdafx.h"
#include "BmpMgr.h"

IMPLEMENT_SINGLETON(BmpMgr)

BmpMgr::BmpMgr()
{
}


BmpMgr::~BmpMgr()
{
}

void BmpMgr::LoadByScene(SceneMgr::SceneID eID)
{
	switch (eID)
	{
	case SceneMgr::LOGO:
		m_MapBit.insert(make_pair(L"Logo"
			, (new Bmp)->LoadBmp(L"../Image/Ground/LOGO_2.bmp")));
		m_MapBit.insert(make_pair(L"Logo_2"
			, (new Bmp)->LoadBmp(L"../Image/Ground/LOGO_2.bmp")));
		m_MapBit.insert(make_pair(L"Logo_Moon"
			, (new Bmp)->LoadBmp(L"../Image/Ground/LOGO_Moon.bmp")));
		break;
	case SceneMgr::MENU:
		m_MapBit.insert(make_pair(L"Title"
			, (new Bmp)->LoadBmp(L"../Image/Ground/Å¸ÀÌÆ².bmp")));

		m_MapBit.insert(make_pair(L"Extar_Start"
			, (new Bmp)->LoadBmp(L"../Image/Ground/Extra_Start.bmp")));

		m_MapBit.insert(make_pair(L"Music_Room"
			, (new Bmp)->LoadBmp(L"../Image/Ground/Music_Room.bmp")));

		m_MapBit.insert(make_pair(L"Option"
			, (new Bmp)->LoadBmp(L"../Image/Ground/Option.bmp")));
		
		m_MapBit.insert(make_pair(L"Practice_Start"
			, (new Bmp)->LoadBmp(L"../Image/Ground/Practice_Start.bmp")));

		m_MapBit.insert(make_pair(L"Quit"
			, (new Bmp)->LoadBmp(L"../Image/Ground/Quit.bmp")));

		m_MapBit.insert(make_pair(L"Replay"
			, (new Bmp)->LoadBmp(L"../Image/Ground/Replay.bmp")));

		m_MapBit.insert(make_pair(L"Result"
			, (new Bmp)->LoadBmp(L"../Image/Ground/Result.bmp")));

		m_MapBit.insert(make_pair(L"Spell_Practice"
			, (new Bmp)->LoadBmp(L"../Image/Ground/Spell_Practice.bmp")));

		m_MapBit.insert(make_pair(L"Start"
			, (new Bmp)->LoadBmp(L"../Image/Ground/Start.bmp")));

		break;
	case SceneMgr::EDIT:
		break;
	case SceneMgr::STAGE:
		BmpMgr::GetInstance()->GetMapBit().insert(
			make_pair(L"BackBuffer"
				, (new Bmp)->LoadBmp(L"../Image/Ground/backbuffer.bmp")));

		BmpMgr::GetInstance()->GetMapBit().insert(
			make_pair(L"BackGround"
				, (new Bmp)->LoadBmp(L"../Image/Ground/background.bmp")));

		BmpMgr::GetInstance()->GetMapBit().insert(
			make_pair(L"StageBack"
				, (new Bmp)->LoadBmp(L"../Image/Ground/½ºÅ×ÀÌÁö_¹è°æ.bmp")));

		BmpMgr::GetInstance()->GetMapBit().insert(make_pair(L"Player"
			, (new Bmp)->LoadBmp(L"../Image/Object/·¹ÀÌ¹«2.bmp")));

		BmpMgr::GetInstance()->GetMapBit().insert(make_pair(L"Bullet"
			, (new Bmp)->LoadBmp(L"../Image/Object/·¹ÀÌ¹«ÃÑ¾Ë.bmp")));

		BmpMgr::GetInstance()->GetMapBit().insert(make_pair(L"GiudeBullet"
			, (new Bmp)->LoadBmp(L"../Image/Object/À¯µµÅº.bmp")));

		BmpMgr::GetInstance()->GetMapBit().insert(make_pair(L"Monster_Blue"
			, (new Bmp)->LoadBmp(L"../Image/Object/ÆÄ¶û.bmp")));

		BmpMgr::GetInstance()->GetMapBit().insert(make_pair(L"¸ó½ºÅÍÃÑ¾Ë"
			, (new Bmp)->LoadBmp(L"../Image/Object/¸ó½ºÅÍÃÑ¾Ë.bmp")));
	
		BmpMgr::GetInstance()->GetMapBit().insert(make_pair(L"Monster_Red"
			, (new Bmp)->LoadBmp(L"../Image/Object/»¡°­.bmp")));

		BmpMgr::GetInstance()->GetMapBit().insert(make_pair(L"¸ó½ºÅÍÃÑ¾Ë2"
			, (new Bmp)->LoadBmp(L"../Image/Object/ÃÑ¾Ë2.bmp")));

		BmpMgr::GetInstance()->GetMapBit().insert(make_pair(L"Boss"
			, (new Bmp)->LoadBmp(L"../Image/Object/º¸½º.bmp")));

		BmpMgr::GetInstance()->GetMapBit().insert(make_pair(L"BossÃÑ¾Ë"
			, (new Bmp)->LoadBmp(L"../Image/Object/BossÃÑ¾Ë.bmp")));

		BmpMgr::GetInstance()->GetMapBit().insert(make_pair(L"BossÃÑ¾Ë2"
			, (new Bmp)->LoadBmp(L"../Image/Object/BossÃÑ¾Ë2.bmp")));

		break;
	

	case SceneMgr::ENDING:
		break;
	}
}

Bmp * BmpMgr::FindImage(const TCHAR * pImageKey)
{
	auto find = find_if(m_MapBit.begin()
	, m_MapBit.end()
	, [&](auto Pair)->bool
	{
		return !lstrcmp(pImageKey, Pair.first);
	});

	if(m_MapBit.end() == find)
		return nullptr;
		
	return find->second;
}
