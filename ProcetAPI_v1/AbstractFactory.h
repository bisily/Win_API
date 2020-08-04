#pragma once

class Obj;
template <typename T>
class AbstractFactroy
{
public:
	static Obj* CreateObj()
	{
		Obj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	static Obj* CreateObj(float fX, float fY)
	{
		Obj* pObj = new T;
		pObj->Initialize();
		pObj->SetPos(fX, fY);

		return pObj;
	}

	static Obj* CreateObj(float fX, float fY, float fAngle)
	{
		Obj* pObj = new T;
		pObj->Initialize();
		pObj->SetPos(fX, fY);
		pObj->SetAngle(fAngle);

		return pObj;
	}

	// 몬스터가 플레이어에게 총알을 발사할때 사용할 객체생성 함수
	static Obj* CreateObj(float fX, float fY, float _fX, float _fY)
	{
		Obj* pObj = new T;
		dynamic_cast<T*>(pObj)->SetTargetPos(_fX, _fY);
		pObj->Initialize();
		pObj->SetPos(fX, fY);

		return pObj;
	}

	static Obj* CreateObj(float fX, float fY, Obj* pTarget)
	{
		Obj* pObj = new T;
		dynamic_cast<T*>(pObj)->SetTargetPos(pTarget);
		pObj->Initialize();
		pObj->SetPos(fX, fY);

		return pObj;
	}

	static Obj* CreateObj(float fX, float fY, DIRECTION eID)
	{
		Obj* pObj = new T;
		dynamic_cast<T*>(pObj)->SetDir(eID);
		pObj->Initialize();
		pObj->SetPos(fX, fY);

		return pObj;
	}
};