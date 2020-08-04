#pragma once

class Obj;
class MathMgr
{
public:
	MathMgr();
	~MathMgr();

public:
	static float CalcDistance(Obj* dst, Obj* src);
	static float CalcRadian(Obj* dst, Obj* src);
	static float CalcDegree(Obj* dst, Obj* src);
};

