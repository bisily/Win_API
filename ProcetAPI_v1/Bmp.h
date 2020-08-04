#pragma once
class Bmp
{
public:
	Bmp();
	~Bmp();

public:
	HDC GetMemDC() { return m_hMemDC; }

public:
	Bmp* LoadBmpStage(const TCHAR* pFullPath);
	Bmp* LoadBmp(const TCHAR* pFullPath);
	void Release();

private:
	HBITMAP		m_hBitmap;
	HBITMAP		m_hBitold;

	HDC			m_hMemDC;
};

