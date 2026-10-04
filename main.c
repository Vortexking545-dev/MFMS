#include <stdio.h>
#include "common.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

int main(void) {
    Employee employees[MAX_ITEMS];
    int empCount = 0;

    Budget budgets[MAX_ITEMS];
    int budgetCount = 0;

    Supplier suppliers[MAX_ITEMS];
    int supplierCount = 0;

    Asset assets[MAX_ITEMS];
    int assetCount = 0;

    int choice;
    do {
        printf("\n========================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        choice = readPositiveInt("Enter your choice: ");

        switch (choice) {
            case 1: employeeMenu(employees, &empCount); break;
            case 2: budgetMenu(budgets, &budgetCount); break;
            case 3: supplierMenu(suppliers, &supplierCount); break;
            case 4: assetMenu(assets, &assetCount); break;
            case 5: reportsMenu(employees, empCount, budgets, budgetCount, suppliers, supplierCount, assets, assetCount); break;
            case 6: printf("Shutting down MFMS. Goodbye.\n"); break;
            default: printf("[!] Invalid choice. Select 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}