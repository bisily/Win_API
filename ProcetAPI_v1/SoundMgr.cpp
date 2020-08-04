#include "stdafx.h"
#include "SoundMgr.h"

IMPLEMENT_SINGLETON(SoundMgr)

SoundMgr::SoundMgr()
{
	Initialize();
}


SoundMgr::~SoundMgr()
{
	Release();
}

void SoundMgr::Initialize()
{
	FMOD_System_Create(&m_pSystem);
	FMOD_System_Init(m_pSystem, CHANNEL_END, FMOD_INIT_NORMAL, nullptr);

	LoadSoundFile();
}

void SoundMgr::Update()
{
	FMOD_System_Update(m_pSystem);
}

void SoundMgr::Release()
{
	for (auto iter : m_MapSound)
	{
		delete iter.first;
		FMOD_Sound_Release(iter.second);
	}

	m_MapSound.clear();

	FMOD_System_Close(m_pSystem);
	FMOD_System_Release(m_pSystem);
}

void SoundMgr::LoadSoundFile()
{
	// io.h에서 제공하는 구조체
	_finddata_t _fd = {};

	long handle = 0;

	handle = _findfirst("../Sound/*.*", &_fd);

	if (-1 == handle)
	{
		MessageBox(g_hWnd, L"Not found File!!", L"failed!!", MB_OK);
		return;
	}

	int iRes = 0;

	while (-1 != iRes)
	{
		char szFullPath[128] = "../Sound/";
		strcat_s(szFullPath, _fd.name);

		FMOD_SOUND* pSound = nullptr;
		FMOD_RESULT FRes = FMOD_System_CreateSound(m_pSystem, szFullPath, FMOD_HARDWARE, nullptr, &pSound);

		if (FMOD_OK == FRes)
		{
			TCHAR* pSoundKey = new TCHAR[strlen(_fd.name) + 1];

			MultiByteToWideChar(CP_ACP, 0, _fd.name, strlen(_fd.name) + 1, pSoundKey, strlen(_fd.name) + 1);

			m_MapSound.insert(make_pair(pSoundKey, pSound));
		}

		iRes = _findnext(handle, &_fd);
	}

}

void SoundMgr::PlaySound(const TCHAR * pSoundKey, CHANNEL_ID eID)
{
	auto iter_find = find_if(m_MapSound.begin(), m_MapSound.end(),
	[&pSoundKey](auto Pair)->bool
	{
		return !lstrcmp(pSoundKey, Pair.first);
	});

	if (m_MapSound.end() == iter_find)
	{
		MessageBox(g_hWnd, pSoundKey, L"Play Failed!!", MB_OK);
		return;
	}

	FMOD_System_PlaySound(m_pSystem, FMOD_CHANNEL_FREE, iter_find->second,
		FALSE, &(m_pChannelArr[eID]));
}

void SoundMgr::PlayBGM(const TCHAR * pSoundKey)
{
	auto iter_find = find_if(m_MapSound.begin(), m_MapSound.end(),
	[&pSoundKey](auto Pair)->bool
	{
		return !lstrcmp(pSoundKey, Pair.first);
	});

	if (m_MapSound.end() == iter_find)
	{
		MessageBox(g_hWnd, pSoundKey, L"Play Failed!!", MB_OK);
		return;
	}

	FMOD_System_PlaySound(m_pSystem, FMOD_CHANNEL_FREE, iter_find->second, FALSE, &(m_pChannelArr[CHANNEL_BGM]));

	FMOD_Channel_SetMode(m_pChannelArr[CHANNEL_BGM], FMOD_LOOP_NORMAL);
}

