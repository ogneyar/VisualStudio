
#include "Panel.h"

//---------------------------------------------------------------------------------------------------------------
// APanel
APanel::APanel(unsigned short x_pos, unsigned short y_pos, unsigned short width, unsigned short height, CHAR_INFO* screen_buffer, unsigned short screen_width)
    : X_Pos(x_pos), Y_Pos(y_pos), Width(width), Height(height), Screen_Buffer(screen_buffer), Screen_Width(screen_width)
{
}
//---------------------------------------------------------------------------------------------------------------
void APanel::Draw()
{
    {
        ASymbol symbol(L' ', 0x1b, L' ', L' ');
        SArea_Pos area_pos(X_Pos + 1, Y_Pos + 1, Screen_Width, Width - 2, Height - 2);
        Clear_Area(Screen_Buffer, area_pos, symbol);
    }

    // 1. Горизонтальная верхняя линия
    {
        ASymbol symbol(L'═', 0x1b, L'╔', L'╗');
        SPos pos(X_Pos, Y_Pos, Screen_Width, Width - 2);
        Draw_Line_Horizontal(Screen_Buffer, pos, symbol);
    }
    // 2. Горизонтальная нижняя линия
    {
        ASymbol symbol(L'═', 0x1b, L'╚', L'╝');
        SPos pos(X_Pos, Y_Pos + Height - 1, Screen_Width, Width - 2);
        Draw_Line_Horizontal(Screen_Buffer, pos, symbol);
    }
    // 3. Вертикальная левая линия
    {
        ASymbol symbol(L'║', 0x1b, L'╔', L'╚');
        SPos pos(X_Pos, Y_Pos, Screen_Width, Height - 2);
        Draw_Line_Vertical(Screen_Buffer, pos, symbol);
    }
    // 4. Вертикальная правая линия
    {
        ASymbol symbol(L'║', 0x1b, L'╗', L'╝');
        SPos pos(X_Pos + Width - 1, Y_Pos, Screen_Width, Height - 2);
        Draw_Line_Vertical(Screen_Buffer, pos, symbol);
    }
    // 5. Горизонтальная средняя линия
    {
        ASymbol symbol(L'─', 0x1b, L'╟', L'╢');
        SPos pos(X_Pos, Y_Pos + Height - 3, Screen_Width, Width - 2);
        Draw_Line_Horizontal(Screen_Buffer, pos, symbol);
    }

    // 6. Вертикальная средняя линия
    {
        ASymbol symbol(L'║', 0x1b, L'╦', L'╨');
        SPos pos(X_Pos + Width / 2, Y_Pos, Screen_Width, Height - 4);
        Draw_Line_Vertical(Screen_Buffer, pos, symbol);
    }

    //Show_Colors(Screen_Buffer, pos, symbol);
}
//---------------------------------------------------------------------------------------------------------------
