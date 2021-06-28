// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Library Files:
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Winmm.lib")

// Windows Header Files:
#include <windows.h>
#include <Mmsystem.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <Psapi.h>
#include <MinHook.h>
#include <timeapi.h>
#include <time.h>

// Additional Header Files:
#include "Log.h"
#include "Memory.h"
#include "types.h"
#include "enums.h"
#include "InputHook.h"
#include "keyboard.h"
#include "CrossMapping.h"
#include "NativeInvoker.h"
#include "nativeCaller.h"
#include "natives.h"
#include "Hooking.h"
#include "natives_lower.h"


// Menu Files:
#include "karma-ui.h"
#include "json.hpp"
#include "visualkeyboard.h"
#include "menu.h"
#include "types.h"
#include <locale>
#include <codecvt>
#include <cstdio>
#include "json.hpp"
#define OFFSET_PLAYER					 0x08			//playerbase

//player (entity) offsets
#define OFFSET_PLAYER_INFO						0x10B8			//playerInfo struct
#define OFFSET_PLAYER_RAGDOLL					0x10A8			//byte; CPed.noRagdoll: 0x20 = off; 0x00/0x01 = on
#define OFFSET_PLAYER_INFO_WANTED   0x7F8            //wanted level; DWORD
#define OFFSET_ENTITY_HEALTH			0x280			//entity health (except for vehicles); float cur, float max
#define OFFSET_PLAYER_VEHICLE					0xD28			//ptr to last used vehicle

//weapon offsets
#define OFFSET_WEAPON_MANAGER			0x10C8			//from playerbase
#define OFFSET_WEAPON_BULLET_DMG		0x98			//float times 10 (so when 0, it will stay 0)
#define OFFSET_WEAPON_CURRENT			0x20			//from weapon manager
//********MATH**********//
#define PI 3.14159265
#define DEGTORAD(D)((D * PI) / 180.0) // Converts Degrees to radians
#define RADTODEG(R)((180.0 * R) / PI)//Converts Radians to Degrees 
//**********************//

#define MENUURL "cheapcheats.net"
#define ME_PLAYER PLAYER::PLAYER_ID()
#define ME_PED PLAYER::PLAYER_PED_ID()
#define ME_VEHICLE PED::GET_VEHICLE_PED_IS_IN(ME_PED, false)
#define MP_VEHICLE_GLOBAL 0x27A9A9
#define KEYBOARD_FOCUS_GLOBAL 0x42FF + 0x82

class globalHandle
{
private:
	void* _handle;

public:
	globalHandle(int index)
		: _handle(&Hooking::getGlobalPtr()[index >> 18 & 0x3F][index & 0x3FFFF])
	{
	}

	globalHandle(void* p)
		: _handle(p)
	{
	}

	globalHandle(const globalHandle& copy)
		: _handle(copy._handle)
	{
	}

	globalHandle At(int index)
	{
		return globalHandle(reinterpret_cast<void**>(this->_handle) + (index));
	}

	globalHandle At(int index, int size)
	{
		// Position 0 = Array Size
		return this->At(1 + (index * size));
	}

	template <typename T>
	T* Get()
	{
		return reinterpret_cast<T*>(this->_handle);
	}

	template <typename T>
	T& As()
	{
		return *this->Get<T>();
	}
};
