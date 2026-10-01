#include <stdio.h>
#include "employee.h"

// Simple array-based storage for demonstration (can be upgraded to file I/O later)
#define MAX_EMPLOYEES 100
static Employee employees[MAX_EMPLOYEES];
static int employeeCount = 0;

void employeeMenu() {
    int choice;
    do {
        printf("\n-----------------------------------------\n");
        printf("          EMPLOYEE MANAGEMENT\n");
        printf("-----------------------------------------\n");
        printf("1. Add New Employee\n");
        printf("2. View All Employees\n");
        printf("3. Return to Main Menu\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-3): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 3.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                viewEmployees();
                break;
            case 3:
                printf("\nReturning to Main Menu...\n");
                break;
            default:
                printf("\nInvalid choice! Please select an option from 1 to 3.\n");
        }
    } while (choice != 3);
}

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\n[Error] Employee database is full!\n");
        return;
    }

    Employee e;
    printf("\nEnter Employee ID: ");
    scanf("%d", &e.id);
    
    printf("Enter Full Name: ");
    while (getchar() != '\n'); // Clear buffer
    fgets(e.name, sizeof(e.name), stdin);
    // Remove trailing newline if present
    e.name[strcspn(e.name, "\n")] = 0;

    printf("Enter Position: ");
    fgets(e.position, sizeof(e.position), stdin);
    e.position[strcspn(e.position, "\n")] = 0;

    printf("Enter Monthly Salary: ");
    scanf("%f", &e.salary);

    employees[employeeCount++] = e;
    printf("\n[Success] Employee added successfully!\n");
}

void viewEmployees() {
    if (employeeCount == 0) {
        printf("\nNo employees found in the system.\n");
        return;
    }

    printf("\n=========================================\n");
    printf("            EMPLOYEE DIRECTORY           \n");
    printf("=========================================\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Position: %s\n", employees[i].position);
        printf("Salary: %.2f\n", employees[i].salary);
        printf("-----------------------------------------\n");
    }
}