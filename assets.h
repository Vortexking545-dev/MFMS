// assets.h
#ifndef ASSETS_H
#define ASSETS_H
#include "common.h"

typedef struct {
    char id[STR_LEN];
    char name[STR_LEN];
    char type[STR_LEN];
    double purchaseValue;
    char department[STR_LEN];
    char condition[STR_LEN]; // e.g., Good, Needs Repair, Critical
} Asset;

void assetMenu(Asset assets[], int *count);
void addAsset(Asset assets[], int *count);
void displayAssets(const Asset assets[], int count);
void searchAsset(const Asset assets[], int count);

#endif