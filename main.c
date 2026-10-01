#include <stdio.h>
#include "employee.h"

void displayMenu() {
    printf("\n=========================================\n");
    printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("=========================================\n");
    printf("1. Employee Management (Partner A)\n");
    printf("2. Budget Tracking (Partner A)\n");
    printf("3. Supplier Management (Partner B)\n");
    printf("4. Asset Management (Partner B)\n");
    printf("5. Financial Reports (Partner B)\n");
    printf("6. Exit\n");
    printf("-----------------------------------------\n");
    printf("Enter your choice (1-6): ");
}

int main() {
    int choice;

    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

switch (choice) {
        case 1:
            employeeMenu();
            break;
        case 2:
            printf("\n[->] Loading Budget Tracking module...\n");
            break;
        case 3:
            printf("\n[->] Loading Supplier Management module...\n");
            break;
        case 4:
            printf("\n[->] Loading Asset Management module...\n");
            break;
        case 5:
            printf("\n[->] Loading Financial Reports module...\n");
            break;
        case 6:
            printf("\nExiting system. Goodbye!\n");
            break;
        default:
            printf("\nInvalid choice! Please select an option from 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}