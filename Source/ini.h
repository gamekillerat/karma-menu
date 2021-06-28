#ifndef INI_H
#define INI_H
#include "stdafx.h"

class inifile
{
public:
	inifile();

	void write(const LPCWSTR file, const LPCWSTR section, const LPCWSTR key, const int value) const
	{
		//const LPCSTR stringp = _itoa(value, buffer, 2);
		wchar_t buffer[256];
		wsprintfW(buffer, L"%d", value);

		WritePrivateProfileString(section, key, buffer, file);
	}

	int read(const LPCWSTR file, const LPCWSTR section, const LPCWSTR key)
	{
		const int returning = GetPrivateProfileInt(section, key, NULL, file);
		return returning;
	}

private:
};

inline inifile::inifile()
= default;

#endif // INI_H
