// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <io.h>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>

#ifdef _DEBUG 
#include <iostream>
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")

#endif 

using namespace std;



#include "fmod.h"
#include "fmod.hpp"
#pragma comment(lib, "fmodex_vc.lib")


#include "Include.h"

#include "KeyMgr.h"
#include "ScrollMgr.h"
#include "MathMgr.h"
#include "ObjectMgr.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "BmpMgr.h"
#include "PatternMgr.h"


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
