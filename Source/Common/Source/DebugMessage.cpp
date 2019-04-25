
#include "Common/Header/CommonPreDec.h"

#if _MSC_VER >= 1400 
#include <Windows.h>
#include <Windowsx.h>
#endif

void WarningText(std::string text)
{
    #if _MSC_VER >= 1400 
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

	/* Save current attributes */
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;

	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "WARNING: " << text << std::endl;
	//printf("This is some nice COLORFUL text, isn't it?");
	/* Restore original attributes */
	SetConsoleTextAttribute(hConsole, saved_attributes);
	//printf("Back to normal");
    #else
	std::cout << "WARNING: " << text << std::endl;
    #endif
};

void ErrorText(std::string text)
{
    #if _MSC_VER >= 1400
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

	/* Save current attributes */
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;

	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "ERROR: " << text << std::endl;
	//printf("This is some nice COLORFUL text, isn't it?");
	/* Restore original attributes */
	SetConsoleTextAttribute(hConsole, saved_attributes);
	//printf("Back to normal");
    #else
	std::cout << "ERROR: " << text << std::endl;
    #endif

    DEBUG_BREAK;
};
