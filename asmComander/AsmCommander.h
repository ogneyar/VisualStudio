#pragma once

#include <stdio.h>
#include "Panel.h"

//---------------------------------------------------------------------------------------------------------------
class AsmCommander
{
public:
	~AsmCommander();

	bool Init();
	bool Draw();
private:
	HANDLE Std_Handle = 0;
	HANDLE Screen_Buffer_Handle = 0;
	CHAR_INFO* Screen_Buffer;
	CONSOLE_SCREEN_BUFFER_INFO Screen_Buffer_Info{};

	APanel* Left_Panel = 0;
	APanel* Right_Panel = 0;
};
//---------------------------------------------------------------------------------------------------------------
