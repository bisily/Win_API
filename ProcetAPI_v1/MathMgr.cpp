#include "stdafx.h"
#include "MathMgr.h"
#include "Obj.h"


MathMgr::MathMgr()
{
}


MathMgr::~MathMgr()
{
}

float MathMgr::CalcDistance(Obj * dst, Obj * src)
{
	float fWidth = dst->GetInfo().fX - src->GetInfo().fX;
	float fHeight = dst->GetInfo().fY - src->GetInfo().fY;

	return sqrtf(fWidth * fWidth + fHeight * fHeight);
}

float MathMgr::CalcRadian(Obj * dst, Obj * src)
{
	float fWidth = dst->GetInfo().fX - src->GetInfo().fX;
	float fHeight = dst->GetInfo().fY - src->GetInfo().fY;
	float fDist = sqrtf(fWidth * fWidth + fHeight * fHeight);

	float fAngle = acosf(fWidth / fDist);

	if (src->GetInfo().fY < dst->GetInfo().fY)
		fAngle *= -1.f;

	return fAngle;
}

float MathMgr::CalcDegree(Obj * dst, Obj * src)
{
	float fWidth = dst->GetInfo().fX - src->GetInfo().fX;
	float fHeight = dst->GetInfo().fY - src->GetInfo().fY;
	float fDist = sqrtf(fWidth* fWidth + fHeight * fHeight);

	float fAngle = acosf(fWidth / fDist);

	if (src->GetInfo().fY < dst->GetInfo().fY)
		fAngle *= -1.f;

	return fAngle * 180.f / PI;
}
