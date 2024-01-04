
#include "Common.h"

//---------------------------------------------------------------------------------------------------------------
// SPos
SPos::SPos(unsigned short x_pos, unsigned short y_pos, unsigned short screen_width, unsigned short len)
    : X_Pos(x_pos), Y_Pos(y_pos), Screen_Width(screen_width), Len(len)
{
}
//---------------------------------------------------------------------------------------------------------------
// SText_Pos
SText_Pos::SText_Pos(unsigned short x_pos, unsigned short y_pos, unsigned short screen_width, unsigned short attributes)
    : X_Pos(x_pos), Y_Pos(y_pos), Screen_Width(screen_width), Attributes(attributes)
{
}
//---------------------------------------------------------------------------------------------------------------
// SArea_Pos
SArea_Pos::SArea_Pos(unsigned short x_pos, unsigned short y_pos, unsigned short screen_width, unsigned char width, unsigned char height)
    : X_Pos(x_pos), Y_Pos(y_pos), Screen_Width(screen_width), Width(width), Height(height)
{
}
//---------------------------------------------------------------------------------------------------------------
// ASymbol
ASymbol::ASymbol(wchar_t main_symbol, unsigned short attributes, wchar_t start_symbol, wchar_t end_symbol)
    : Main_Symbol(main_symbol), Attributes(attributes), Start_Symbol(start_symbol), End_Symbol(end_symbol)
{
}
//---------------------------------------------------------------------------------------------------------------
