#ifndef AUTOCLICKER_H
#define AUTOCLICKER_H

struct AutoClicker {
    int clickEnabled;
    int clickDelay;
    char toggleKey;
};

void displayMenu(struct AutoClicker *autoClicker);
void startAutoClicker(struct AutoClicker *autoClicker);

#endif