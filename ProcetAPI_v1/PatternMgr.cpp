#include "stdafx.h"
#include "PatternMgr.h"
#include "Obj.h"

IMPLEMENT_SINGLETON(PatternMgr)

PatternMgr::PatternMgr()
{
}


PatternMgr::~PatternMgr()
{
}

INFO PatternMgr::AngleLine(Obj * Obj, float angle)
{
	float rad = DegreeToRadian(angle);
	float radR = DegreeToRadian(90 - angle);

	float X, Y, CX, CY;
	X = Obj->GetInfo().fX;
	Y = Obj->GetInfo().fY;
	CX = Obj->GetInfo().fCX;
	CY = Obj->GetInfo().fCY;

	X += cosf(rad)*Obj->GetSpeed();
	Y += -cosf(radR)*Obj->GetSpeed();

	INFO info = { X, Y, CX, CY };

	return info;
}

INFO PatternMgr::Move(Obj * obj, DIRECTION eID)
{
	float fX = obj->GetInfo().fX;
	float fY = obj->GetInfo().fY;
	float fCX = obj->GetInfo().fCX;
	float fCY = obj->GetInfo().fCY;

	if (fX < 220 && DIRECTION::RIGHT == eID)
	{
		fX += obj->GetSpeed();
		fY += obj->GetSpeed();
	}
	else if (fX > 235 && DIRECTION::LEFT == eID)
	{
		fX -= obj->GetSpeed();
		fY += obj->GetSpeed();
	}
	else
	{
		fY -= obj->GetSpeed();
	}

	INFO info = { fX, fY, fCX, fCY };

	return info;
}

INFO PatternMgr::MoveRed(Obj * obj, DIRECTION eID)
{
	float fX = obj->GetInfo().fX;
	float fY = obj->GetInfo().fY;
	float fCX = obj->GetInfo().fCX;
	float fCY = obj->GetInfo().fCY;

/*	if (fY < 300)
		fY += obj->GetSpeed();
	else */if(DIRECTION::LEFT == eID)
		fX -= obj->GetSpeed();
	else if(DIRECTION::RIGHT == eID)
		fX += obj->GetSpeed();

	INFO info = { fX, fY, fCX, fCY };

	return info;
}

INFO PatternMgr::Parabola(Obj * obj, float angle)
{
	float fX = obj->GetInfo().fX;
	float fY = obj->GetInfo().fY;
	float fCX = obj->GetInfo().fCX;
	float fCY = obj->GetInfo().fCY;

	fX += cosf(angle * PI / 180.f);
	fY += obj->GetSpeed();

	INFO info = { fX, fY, fCX, fCY };

	return info;
}


INFO PatternMgr::Tonador(Obj * obj, float angle)
{
	float fX = obj->GetInfo().fX;
	float fY = obj->GetInfo().fY;
	float fCX = obj->GetInfo().fCX;
	float fCY = obj->GetInfo().fCY;

	fX += cosf(angle * PI / 180.f);
	fY += sinf(angle * PI / 180.f);

	INFO info = { fX, fY, fCX, fCY };

	return info;
}