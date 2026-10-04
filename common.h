#ifndef COMMON_H
#define COMMON_H

#define MAX_ITEMS 50
#define STR_LEN 64

void clearInputBuffer(void);
void readString(const char *prompt, char *output, int maxLen);
int readPositiveInt(const char *prompt);
double readPositiveDouble(const char *prompt);

#endif