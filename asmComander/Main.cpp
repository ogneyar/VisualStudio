
#include "Main.h"

//---------------------------------------------------------------------------------------------------------------
int main(void)
{
    HANDLE std_handle, screen_buffer_handle;
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info{};
    CHAR_INFO * screen_buffer;
    COORD screen_buffer_pos{};
    int screen_buffer_size;

    // Get a handle to the STDOUT screen buffer to copy from and // create a new screen buffer to copy to.
    std_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    screen_buffer_handle = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    if (std_handle == INVALID_HANDLE_VALUE || screen_buffer_handle == INVALID_HANDLE_VALUE)
    {
        printf("CreateConsoleScreenBuffer failed - (%d)\n", GetLastError());
        return 1;
    }

    // Make the new screen buffer the active screen buffer.
    if ( ! SetConsoleActiveScreenBuffer(screen_buffer_handle) )
    {
        printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());
        return 1;
    }

    if ( ! GetConsoleScreenBufferInfo(screen_buffer_handle, &screen_buffer_info) )
    {
        printf("GetConsoleScreenBufferInfo failed - (%d)\n", GetLastError());
        return 1;
    }

    screen_buffer_size = (int)screen_buffer_info.dwSize.X * (int)screen_buffer_info.dwSize.Y;
    screen_buffer = new CHAR_INFO[screen_buffer_size];
    memset(screen_buffer, 0, screen_buffer_size * sizeof(CHAR_INFO));

    int panel_width = screen_buffer_info.dwSize.X / 2;
    int panel_height = screen_buffer_info.dwSize.Y - 2;

    APanel left_panel(0, 0, panel_width, panel_height, screen_buffer, screen_buffer_info.dwSize.X);
    //APanel right_panel(panel_width, 0, panel_height, screen_buffer, screen_buffer_info.dwSize.X);

    left_panel.Draw();
    //right_panel.Draw();

    // Copy from the temporary buffer to the new screen buffer.
    if ( ! WriteConsoleOutput(screen_buffer_handle, screen_buffer, screen_buffer_info.dwSize, screen_buffer_pos, &screen_buffer_info.srWindow) )
    {
        printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
        return 1;
    }

    Sleep(20 * 1000);

    // Restore the original active screen buffer.
    if ( ! SetConsoleActiveScreenBuffer(std_handle) )
    {
        printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());
        return 1;
    }

    return 0;
}
//---------------------------------------------------------------------------------------------------------------
