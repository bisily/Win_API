#pragma once
class SoundMgr
{
	DECLARE_SINGLETON(SoundMgr)

public:
	enum CHANNEL_ID { CHANNEL_BGM, CHANNEL_PLAYER, CHANNEL_END };

private:
	SoundMgr();
	~SoundMgr();

public:
	void Initialize();
	void Update();
	void Release();

public:
	void LoadSoundFile();
	void PlaySound(const TCHAR* pSoundKey, CHANNEL_ID eID);
	void PlayBGM(const TCHAR* pSoundKey);

private:
	FMOD_SYSTEM*		m_pSystem; // ���� �ý��� �Ѱ� ������
	FMOD_CHANNEL*		m_pChannelArr[CHANNEL_END]; // ���带 ����ϱ� ���� ä�� �迭

	map<const TCHAR*, FMOD_SOUND*>	m_MapSound;
};

