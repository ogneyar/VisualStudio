#pragma once

#include <windows.h>

//---------------------------------------------------------------------------------------------------------------
struct SPos
{
    SPos(unsigned short x_pos, unsigned short y_pos, unsigned short screen_width, unsigned short len)
        : X_Pos(x_pos), Y_Pos(y_pos), Screen_Width(screen_width), Len(len) {}
    unsigned short X_Pos;
    unsigned short Y_Pos;
    unsigned short Screen_Width;
    unsigned short Len;
};
//---------------------------------------------------------------------------------------------------------------
class ASymbol
{
public:
    ASymbol(wchar_t main_symbol, unsigned short attributes, wchar_t start_symbol, wchar_t end_symbol);

    wchar_t Main_Symbol;
    unsigned short Attributes;
    wchar_t Start_Symbol;
    wchar_t End_Symbol;
};
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
extern "C" void Draw_Line_Horizontal(CHAR_INFO * screen_buffer, SPos pos, ASymbol symbol);
extern "C" void Draw_Line_Vertical(CHAR_INFO * screen_buffer, SPos pos, ASymbol symbol);
extern "C" void Show_Colors(CHAR_INFO * screen_buffer, SPos pos, CHAR_INFO symbol);
//---------------------------------------------------------------------------------------------------------------
