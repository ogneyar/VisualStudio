#pragma once

#include "Common.h"

//---------------------------------------------------------------------------------------------------------------
extern "C" void Draw_Line_Horizontal(CHAR_INFO * screen_buffer, SPos pos, ASymbol symbol);
extern "C" void Draw_Line_Vertical(CHAR_INFO * screen_buffer, SPos pos, ASymbol symbol);
extern "C" void Show_Colors(CHAR_INFO * screen_buffer, SPos pos, CHAR_INFO symbol);
extern "C" void Clear_Area(CHAR_INFO * screen_buffer, SArea_Pos area_pos, ASymbol symbol);
//---------------------------------------------------------------------------------------------------------------