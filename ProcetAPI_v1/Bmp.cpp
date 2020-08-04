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
	// �ӽ÷� ��� DC�� ���´�.
	HDC hDC = GetDC(g_hWnd);

	// ���� ��� DC�� ���� �޸� DC�� �Ҵ����ش�.
	m_hMemDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWnd, hDC);

	// ��Ʈ���� �о�;��Ѵ�.
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
	// �ӽ÷� ��� DC�� ���´�.
	HDC hDC = GetDC(g_hWnd);

	// ���� ��� DC�� ���� �޸� DC�� �Ҵ����ش�.
	m_hMemDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWnd, hDC);

	// ��Ʈ���� �о�;��Ѵ�.
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
