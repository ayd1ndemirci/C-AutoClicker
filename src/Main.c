#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include "AutoClicker.h"

int main() {
    struct AutoClicker autoClicker;
    char toggleKey;
    int maxCPS;

    printf("Enter the key to toggle AutoClicker: ");
    scanf(" %c", &toggleKey);
    printf("Enter maximum CPS (click per second): ");
    scanf("%d", &maxCPS);

    autoClicker.toggleKey = (char) toupper(toggleKey);
    autoClicker.clickEnabled = 0;
    autoClicker.clickDelay = 1000 / maxCPS;

    printf("AutoClicker started with maximum CPS: %d\n", maxCPS);
    startAutoClicker(&autoClicker);

    return 0;
}