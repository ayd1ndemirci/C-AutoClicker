#include "AutoClicker.h"
#include <stdio.h>
#include <windows.h>

void displayMenu(struct AutoClicker *autoClicker) {
    printf("Enter the key to toggle AutoClicker: ");
}

void startAutoClicker(struct AutoClicker *autoClicker) {
     POINT p;
    while (1) {
        if (!autoClicker->clickEnabled && GetAsyncKeyState((int)autoClicker->toggleKey) & 0x8000) {
            autoClicker->clickEnabled = 1;
            Sleep(200);
        }

        if (autoClicker->clickEnabled && GetAsyncKeyState((int)autoClicker->toggleKey) & 0x8000) {
            autoClicker->clickEnabled = 0;
            Sleep(200);
        }

        GetCursorPos(&p);
        if (autoClicker->clickEnabled && p.x < 20 && p.y < 20) {
            autoClicker->clickEnabled = 0;
        }

        if (autoClicker->clickEnabled) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(autoClicker->clickDelay);
        }
    }
}