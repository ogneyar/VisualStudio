#pragma once

//---------------------------------------------------------------------------------------------------------------
struct SPos
{
    SPos(unsigned short x_pos, unsigned short y_pos, unsigned short screen_width, unsigned short len);

    unsigned short X_Pos;
    unsigned short Y_Pos;
    unsigned short Screen_Width;
    unsigned short Len;
};
//---------------------------------------------------------------------------------------------------------------
struct SText_Pos
{
    SText_Pos(unsigned short x_pos, unsigned short y_pos, unsigned short screen_width, unsigned short attributes);

    unsigned short X_Pos;
    unsigned short Y_Pos;
    unsigned short Screen_Width;
    unsigned short Attributes;
};
//---------------------------------------------------------------------------------------------------------------
struct SArea_Pos
{
    SArea_Pos(unsigned short x_pos, unsigned short y_pos, unsigned short screen_width, unsigned char width, unsigned char height);

    unsigned short X_Pos;
    unsigned short Y_Pos;
    unsigned short Screen_Width;
    unsigned char Width, Height;
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
