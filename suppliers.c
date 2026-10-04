// suppliers.c
#include <stdio.h>
#include <string.h>
#include "suppliers.h"

void addSupplier(Supplier suppliers[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("[!] Supplier registry full.\n");
        return;
    }
    Supplier s;
    readString("Supplier ID: ", s.id, STR_LEN);
    readString("Company Name: ", s.name, STR_LEN);
    readString("Email Address: ", s.email, STR_LEN);
    readString("Phone Number: ", s.phone, STR_LEN);
    readString("Town/Location: ", s.location, STR_LEN);

    suppliers[*count] = s;
    (*count)++;
    printf("[+] Supplier registered successfully.\n");
}

void displaySuppliers(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("No registered suppliers.\n");
        return;
    }
    printf("\n%-10s %-20s %-20s %-15s %-15s\n", "ID", "Name", "Email", "Phone", "Location");
    printf("------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10s %-20s %-20s %-15s %-15s\n",
               suppliers[i].id, suppliers[i].name, suppliers[i].email, suppliers[i].phone, suppliers[i].location);
    }
}

void searchSupplier(const Supplier suppliers[], int count) {
    char term[STR_LEN];
    readString("Enter search term (Supplier Name or Town): ", term, STR_LEN);
    int matches = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(suppliers[i].name, term) != NULL || strstr(suppliers[i].location, term) != NULL) {
            printf("[Found] %s | %s | %s | %s\n",
                   suppliers[i].id, suppliers[i].name, suppliers[i].location, suppliers[i].phone);
            matches++;
        }
    }
    if (matches == 0) printf("[!] No matching suppliers found.\n");
}

void supplierMenu(Supplier suppliers[], int *count) {
    int choice;
    do {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Register Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier (by Name/Town)\n");
        printf("4. Return to Main Menu\n");
        choice = readPositiveInt("Choice: ");

        switch (choice) {
            case 1: addSupplier(suppliers, count); break;
            case 2: displaySuppliers(suppliers, *count); break;
            case 3: searchSupplier(suppliers, *count); break;
            case 4: break;
            default: printf("[!] Invalid choice.\n");
        }
    } while (choice != 4);
}