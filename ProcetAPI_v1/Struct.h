#pragma once

typedef struct tagInfo
{
	float	fX;
	float	fY;
	float	fCX;
	float	fCY;
}INFO;

typedef struct tagColli
{
	float fCX;
	float fCY;
}COLLI;

typedef struct tagFrame
{
	int iFrameStart;
	int iFrameEnd;
	int iScene;

	DWORD dwFrameSpd;
	DWORD dwFrameOld;
	DWORD dwFrameCur;
}FRAME;
