
#include "AsmCommander.h"

// AsmCommander
//---------------------------------------------------------------------------------------------------------------
AsmCommander::~AsmCommander()
{
    delete Left_Panel;
    delete Right_Panel;
    delete Screen_Buffer;
}
//---------------------------------------------------------------------------------------------------------------
bool AsmCommander::Init()
{
    int screen_buffer_size;

    // Get a handle to the STDOUT screen buffer to copy from and // create a new screen buffer to copy to.
    Std_Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    Screen_Buffer_Handle = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    if (Std_Handle == INVALID_HANDLE_VALUE || Screen_Buffer_Handle == INVALID_HANDLE_VALUE)
    {
        printf("CreateConsoleScreenBuffer failed - (%d)\n", GetLastError());
        return false;
    }

    // Make the new screen buffer the active screen buffer.
    if (!SetConsoleActiveScreenBuffer(Screen_Buffer_Handle))
    {
        printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());
        return false;
    }

    if (!GetConsoleScreenBufferInfo(Screen_Buffer_Handle, &Screen_Buffer_Info))
    {
        printf("GetConsoleScreenBufferInfo failed - (%d)\n", GetLastError());
        return false;
    }

    screen_buffer_size = (int)Screen_Buffer_Info.dwSize.X * (int)Screen_Buffer_Info.dwSize.Y;
    Screen_Buffer = new CHAR_INFO[screen_buffer_size];
    memset(Screen_Buffer, 0, screen_buffer_size * sizeof(CHAR_INFO));

    return true;
}
//---------------------------------------------------------------------------------------------------------------
bool AsmCommander::Draw()
{
    COORD screen_buffer_pos{};

    int panel_width = Screen_Buffer_Info.dwSize.X / 2;
    int panel_height = Screen_Buffer_Info.dwSize.Y - 2;

    Left_Panel = new APanel(0, 0, panel_width, panel_height, Screen_Buffer, Screen_Buffer_Info.dwSize.X);
    Right_Panel = new APanel(panel_width, 0, panel_width, panel_height, Screen_Buffer, Screen_Buffer_Info.dwSize.X);

    Left_Panel->Draw();
    Right_Panel->Draw();

    // Copy from the temporary buffer to the new screen buffer.
    if (!WriteConsoleOutput(Screen_Buffer_Handle, Screen_Buffer, Screen_Buffer_Info.dwSize, screen_buffer_pos, &Screen_Buffer_Info.srWindow))
    {
        printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
        return false;
    }

    Sleep(40 * 1000);

    // Restore the original active screen buffer.
    if (!SetConsoleActiveScreenBuffer(Std_Handle))
    {
        printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());
        return false;
    }

    return true;
}
//---------------------------------------------------------------------------------------------------------------
