#pragma once

#define WINCX 800
#define WINCY 700

#define PI 3.1415f

#define STAGELIMITE 60000

#define RadianToDegree(X) (X * 180.f / PI)
#define DegreeToRadian(X) (X * PI / 180.f)

#define DECLARE_SINGLETON(ClassName)		\
public:										\
	static ClassName* GetInstance()			\
	{										\
		if (nullptr == m_pInstance)			\
			m_pInstance = new ClassName;	\
		return m_pInstance;					\
	}										\
	void DestroyInstance()					\
	{										\
		if (m_pInstance)					\
		{									\
			delete m_pInstance;				\
			m_pInstance = nullptr;			\
		}									\
	}										\
private:									\
	static ClassName* m_pInstance;

#define IMPLEMENT_SINGLETON(ClassName)		\
ClassName* ClassName::m_pInstance = nullptr;