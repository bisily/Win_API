#pragma once
class PatternMgr
{
	DECLARE_SINGLETON(PatternMgr)
private:
	PatternMgr();
	~PatternMgr();

public:
	INFO AngleLine(Obj* Obj, float angle);

	INFO Move(Obj* obj, DIRECTION eID);
	INFO MoveRed(Obj * obj, DIRECTION eID);

	INFO Parabola(Obj* obj, float angle);
	INFO Tonador(Obj* obj, float angle);
};

