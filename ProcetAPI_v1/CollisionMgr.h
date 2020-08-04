#pragma once

class Obj;
class CollisionMgr
{
public:
	CollisionMgr();
	~CollisionMgr();

public:
	static void CollisionGround(Obj& Player);
	static void CollisionSphere(OBJLIST& Dst, OBJLIST& Src);
private:
	static bool CheckRect(Obj* pDst, Obj* pSrc, float* pMoveX, float* pMoveY);
	static bool CheckSphere(Obj* pDst, Obj* pSrc);
};

