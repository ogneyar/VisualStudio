
#include "Panel.h"

//---------------------------------------------------------------------------------------------------------------
// ASymbol
ASymbol::ASymbol(wchar_t main_symbol, unsigned short attributes, wchar_t start_symbol, wchar_t end_symbol)
    : Main_Symbol(main_symbol), Attributes(attributes), Start_Symbol(start_symbol), End_Symbol(end_symbol) 
{
}
//---------------------------------------------------------------------------------------------------------------
// APanel
APanel::APanel(unsigned short x_pos, unsigned short y_pos, unsigned short width, unsigned short height, CHAR_INFO* screen_buffer, unsigned short screen_width)
    : X_Pos(x_pos), Y_Pos(y_pos), Width(width), Height(height), Screen_Buffer(screen_buffer), Screen_Width(screen_width)
{
}
//---------------------------------------------------------------------------------------------------------------
void APanel::Draw()
{
    // 1. Горизонтальная верхняя линия
    {
        ASymbol symbol(L'═', 0x1b, L'╔', L'╗');
        SPos pos(0, 0, Screen_Width, Width - 1);
        Draw_Line_Horizontal(Screen_Buffer, pos, symbol);
    }
    // 2. Горизонтальная нижняя линия
    {
        ASymbol symbol(L'═', 0x1b, L'╚', L'╝');
        SPos pos(0, Height - 1, Screen_Width, Width - 1);
        Draw_Line_Horizontal(Screen_Buffer, pos, symbol);
    }
    // 3. Вертикальная левая линия
    {
        ASymbol symbol(L'║', 0x1b, L'╔', L'╚');
        SPos pos(0, 0, Screen_Width, Height - 2);
        Draw_Line_Vertical(Screen_Buffer, pos, symbol);
    }
    // 4. Вертикальная правая линия
    {
        ASymbol symbol(L'║', 0x1b, L'╗', L'╝');
        SPos pos(Width, 0, Screen_Width, Height - 2);
        Draw_Line_Vertical(Screen_Buffer, pos, symbol);
    }
    // 5. Горизонтальная средняя линия
    {
        ASymbol symbol(L'─', 0x1b, L'╟', L'╢');
        SPos pos(0, Height - 3, Screen_Width, Width - 1);
        Draw_Line_Horizontal(Screen_Buffer, pos, symbol);
    }

    // 6. Вертикальная средняя линия
    {
        ASymbol symbol(L'║', 0x1b, L'╦', L'╨');
        SPos pos(Width / 2, 0, Screen_Width, Height - 4);
        Draw_Line_Vertical(Screen_Buffer, pos, symbol);
    }

    //Show_Colors(Screen_Buffer, pos, symbol);
}
//---------------------------------------------------------------------------------------------------------------
