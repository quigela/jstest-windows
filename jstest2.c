#include <windows.h>
#include <stdio.h>

int main()
{
    int i;
    JOYINFOEX pji;
    DWORD axes[6] = {0};
    UINT buttons[13] = {0};
    UINT hat[5] = {0};
    ZeroMemory(&pji, sizeof(pji));
    pji.dwSize = sizeof(pji);
    pji.dwFlags = JOY_RETURNBUTTONS | JOY_RETURNX | JOY_RETURNY
        | JOY_RETURNZ | JOY_RETURNR | JOY_RETURNU | JOY_RETURNV | JOY_RETURNPOV;
    while(JOYERR_NOERROR == joyGetPosEx(0, &pji))
    {
        for(i = 0; i < 6; i++)
        {
            DWORD axis = ((DWORD*) &(pji.dwXpos))[i];
            if(axis != axes[i])
            {
                axes[i] = axis;
            }
        }
        for(i = 0; i < 13; i++)
        {
            int button = (pji.dwButtons & (1 << i)) != 0;
            if(button != buttons[i])
            {
                buttons[i] = button;
            }
        }
        //if(update)
        //{
            fprintf(stdout, "Axes:", pji.dwButtons);
            for(i = 0; i < 6; i++)
            {
                fprintf(stdout, "  %d: %5d", i, axes[i] + 32767);
            }
            fprintf(stdout, "  Buttons:  ", pji.dwButtonNumber);
            for(i = 0; i < 13; i++)
            {
                fprintf(stdout, "%d:%s  ", i, buttons[i] ? "on ":"off");
            }
            printf("  Hat: %d", (pji.dwPOV/100));
            fprintf(stdout, "\r");
            fflush(stdout);
        //}
    }
}