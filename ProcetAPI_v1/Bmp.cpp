#include "stdafx.h"
#include "Bmp.h"


Bmp::Bmp()
{
}


Bmp::~Bmp()
{
	Release();
}

Bmp * Bmp::LoadBmpStage(const TCHAR * pFullPath)
{
	// 임시로 출력 DC를 얻어온다.
	HDC hDC = GetDC(g_hWnd);

	// 실제 출력 DC와 같은 메모리 DC를 할당해준다.
	m_hMemDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWnd, hDC);

	// 비트맵을 읽어와야한다.
	m_hBitmap = (HBITMAP)LoadImage(0, pFullPath
		, IMAGE_BITMAP
		, 450
		, 3500
		, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	if (0 == m_hBitmap)
	{
		MessageBox(g_hWnd, pFullPath, L"Bmp Load Failed!!", MB_OK);
		return nullptr;
	}

	m_hBitold = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);

	return this;
}

Bmp * Bmp::LoadBmp(const TCHAR * pFullPath)
{
	// 임시로 출력 DC를 얻어온다.
	HDC hDC = GetDC(g_hWnd);

	// 실제 출력 DC와 같은 메모리 DC를 할당해준다.
	m_hMemDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWnd, hDC);

	// 비트맵을 읽어와야한다.
	m_hBitmap = (HBITMAP)LoadImage(0, pFullPath
		, IMAGE_BITMAP
		, 0
		, 0
		, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	if (0 == m_hBitmap)
	{
		MessageBox(g_hWnd, pFullPath, L"Bmp Load Failed!!", MB_OK);
		return nullptr;
	}

	m_hBitold = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);

	return this;
}

void Bmp::Release()
{
	SelectObject(m_hMemDC, m_hBitold);
	DeleteObject(m_hBitmap);
	DeleteDC(m_hMemDC);
}
