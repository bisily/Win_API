#include "stdafx.h"
#include "CollisionMgr.h"
#include "Obj.h"

CollisionMgr::CollisionMgr()
{
}


CollisionMgr::~CollisionMgr()
{
}


void CollisionMgr::CollisionGround(Obj& Player)
{

	if (Player.GetInfo().fX - (Player.GetInfo().fCX / 2) < 30)
	{
		if(KEY_PRESSING(VK_SHIFT))
			Player.SetX(5);
		else
			Player.SetX(10);
	}

	if (Player.GetInfo().fX + (Player.GetInfo().fCX / 2) > 447)
	{
		if (KEY_PRESSING(VK_SHIFT))
			Player.SetX(-5);
		else
			Player.SetX(-10);
	}		

	if (Player.GetInfo().fY - (Player.GetInfo().fCY / 2) < 30)
	{
		if (KEY_PRESSING(VK_SHIFT))
			Player.SetY(5);
		else
		Player.SetY(10);
	}

	if (Player.GetInfo().fY + (Player.GetInfo().fCY / 2) > 600)
	{
		if (KEY_PRESSING(VK_SHIFT))
			Player.SetY(-5);
		else
			Player.SetY(-10);
	}
}

bool CollisionMgr::CheckRect(Obj * pDst, Obj * pSrc, float * pMoveX, float * pMoveY)
{
	float fRadSumX = pDst->GetColli().fCX / 2 + pSrc->GetColli().fCX / 2;
	float fRadSumY = pDst->GetColli().fCY / 2 + pSrc->GetColli().fCY / 2;

	// �� �簢���� X ���� ��ǥ
	float fWidth = abs(pDst->GetInfo().fX - pSrc->GetInfo().fX);

	float fHeight = abs(pDst->GetInfo().fY - pSrc->GetInfo().fY);

	if (fRadSumX >= fWidth && fRadSumY >= fHeight)
	{
		*pMoveX = fRadSumX - fWidth;
		*pMoveY = fRadSumY - fHeight;

		return true;
	}

	return false;
}


// ù��° ���ڰ� �ι�° ���ڿ��� ������� �ִ� �Լ�
void CollisionMgr::CollisionSphere(OBJLIST & Dst, OBJLIST & Src)
{
	for (auto dst : Dst)
	{
		if (dst->GetDead())
			continue;

		for (auto src : Src)
		{

			if (src->GetDead())
				continue;

			if (CheckSphere(dst, src))
			{
				src->SetDamage(dst->GetAtt());
				dst->SetDead();
			}
		}
	}

}


bool CollisionMgr::CheckSphere(Obj * pDst, Obj * pSrc)
{
	float fRad = (pDst->GetColli().fCX / 2) + (pSrc->GetColli().fCX / 2);


	float fX = pDst->GetInfo().fX - pSrc->GetInfo().fX;
	float fY = pDst->GetInfo().fY - pSrc->GetInfo().fY;
	float fDist = sqrtf( fX * fX + fY * fY );

	if (fDist <= fRad)
	{
		return true;
	}

	return false;
}

