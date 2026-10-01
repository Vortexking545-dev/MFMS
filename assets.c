// assets.c
#include <stdio.h>
#include <string.h>
#include "assets.h"

void addAsset(Asset assets[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("[!] Asset registry full.\n");
        return;
    }
    Asset a;
    readString("Asset ID: ", a.id, STR_LEN);
    readString("Asset Name: ", a.name, STR_LEN);
    readString("Asset Type (Vehicle/Computer/Building/etc.): ", a.type, STR_LEN);
    a.purchaseValue = readPositiveDouble("Purchase Value (N$): ");
    readString("Allocated Department: ", a.department, STR_LEN);
    readString("Condition (Good/Fair/Poor): ", a.condition, STR_LEN);

    assets[*count] = a;
    (*count)++;
    printf("[+] Asset saved to register.\n");
}

void displayAssets(const Asset assets[], int count) {
    if (count == 0) {
        printf("No assets registered.\n");
        return;
    }
    printf("\n%-10s %-18s %-14s %-12s %-14s %-10s\n", "ID", "Name", "Type", "Value (N$)", "Dept", "Condition");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10s %-18s %-14s %-12.2f %-14s %-10s\n",
               assets[i].id, assets[i].name, assets[i].type, assets[i].purchaseValue,
               assets[i].department, assets[i].condition);
    }
}

void searchAsset(const Asset assets[], int count) {
    char id[STR_LEN];
    readString("Enter Asset ID: ", id, STR_LEN);
    for (int i = 0; i < count; i++) {
        if (strcmp(assets[i].id, id) == 0) {
            printf("\nFound: %s (%s) | %s | Value: N$%.2f | Dept: %s | Condition: %s\n",
                   assets[i].name, assets[i].id, assets[i].type,
                   assets[i].purchaseValue, assets[i].department, assets[i].condition);
            return;
        }
    }
    printf("[!] Asset ID not found.\n");
}

void assetMenu(Asset assets[], int *count) {
    int choice;
    do {
        printf("\n--- ASSET MANAGEMENT ---\n");
        printf("1. Register Asset\n");
        printf("2. Display Asset Register\n");
        printf("3. Search Asset by ID\n");
        printf("4. Return to Main Menu\n");
        choice = readPositiveInt("Choice: ");

        switch (choice) {
            case 1: addAsset(assets, count); break;
            case 2: displayAssets(assets, *count); break;
            case 3: searchAsset(assets, *count); break;
            case 4: break;
            default: printf("[!] Invalid choice.\n");
        }
    } while (choice != 4);
}