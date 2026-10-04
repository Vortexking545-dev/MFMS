#include <stdio.h>
#include <string.h>
#include "common.h"

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void readString(const char *prompt, char *output, int maxLen) {
    do {
        printf("%s", prompt);
        if (fgets(output, maxLen, stdin) != NULL) {
            output[strcspn(output, "\r\n")] = '\0';
        }
        if (strlen(output) == 0) {
            printf("[!] Input cannot be empty. Please re-enter.\n");
        }
    } while (strlen(output) == 0);
}

int readPositiveInt(const char *prompt) {
    int val;
    int itemsRead;
    do {
        printf("%s", prompt);
        itemsRead = scanf("%d", &val);
        clearInputBuffer();
        if (itemsRead != 1 || val < 0) {
            printf("[!] Invalid input. Must be a non-negative integer.\n");
        }
    } while (itemsRead != 1 || val < 0);
    return val;
}

double readPositiveDouble(const char *prompt) {
    double val;
    int itemsRead;
    do {
        printf("%s", prompt);
        itemsRead = scanf("%lf", &val);
        clearInputBuffer();
        if (itemsRead != 1 || val < 0.0) {
            printf("[!] Invalid input. Must be a non-negative number.\n");
        }
    } while (itemsRead != 1 || val < 0.0);
    return val;
}