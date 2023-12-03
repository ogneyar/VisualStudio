#pragma once

#include <windows.h>
#include "AsmToolsInterface.h"

//---------------------------------------------------------------------------------------------------------------
class APanel
{
public:
    APanel(unsigned short x_pos, unsigned short y_pos, unsigned short width, unsigned short height, CHAR_INFO* screen_buffer, unsigned short screen_width);
    void Draw();

    unsigned short X_Pos, Y_Pos;
    unsigned short Width, Height;
    unsigned short Screen_Width;
    CHAR_INFO* Screen_Buffer;
};
//---------------------------------------------------------------------------------------------------------------
