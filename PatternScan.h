#pragma once
#include <Windows.h>
#include <psapi.h>
LPVOID FindPattern(const BYTE* lpPattern, LPCSTR szMask);