#pragma once


#ifdef NIRVANA_PLATFORM_WINDOWS
	#ifdef NIRVANA_BUILD_DLL
		#define NIRVANA_API __declspec(dllexport)
	#else
		#define NIRVANA_API __declspec(dllimport)
	#endif
#else
	#error Nirvana only supports Windows!

#endif