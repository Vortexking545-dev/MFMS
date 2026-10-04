// reports.c
#include <stdio.h>
#include "reports.h"

void generateEmployeeReport(const Employee empList[], int count) {
    printf("\n================ EMPLOYEE SALARY REPORT ================\n");
    if (count == 0) {
        printf("No employee records to analyze.\n");
        return;
    }
    double totalSalary = 0.0;
    double highest = calculateGrossSalary(&empList[0]);
    double lowest = highest;

    for (int i = 0; i < count; i++) {
        double gross = calculateGrossSalary(&empList[i]);
        totalSalary += gross;
        if (gross > highest) highest = gross;
        if (gross < lowest) lowest = gross;
    }

    printf("Total Headcount   : %d\n", count);
    printf("Total Payroll     : N$%.2f\n", totalSalary);
    printf("Average Salary    : N$%.2f\n", totalSalary / count);
    printf("Highest Gross Pay : N$%.2f\n", highest);
    printf("Lowest Gross Pay  : N$%.2f\n", lowest);
    printf("========================================================\n");
}

void generateBudgetReport(const Budget budgets[], int count) {
    printf("\n================ MUNICIPAL BUDGET REPORT ================\n");
    if (count == 0) {
        printf("No departmental budgets to aggregate.\n");
        return;
    }
    double totalAllocated = 0.0;
    double totalSpent = 0.0;
    int deficitDepts = 0;

    for (int i = 0; i < count; i++) {
        totalAllocated += budgets[i].allocatedBudget;
        totalSpent += budgets[i].expenditure;
        if (calculateRemainingBudget(&budgets[i]) < 0) {
            deficitDepts++;
        }
    }

    printf("Total Allocated Budget : N$%.2f\n", totalAllocated);
    printf("Total Expenditure      : N$%.2f\n", totalSpent);
    printf("Net Remaining Balance  : N$%.2f\n", totalAllocated - totalSpent);
    printf("Departments in Deficit : %d\n", deficitDepts);
    if (deficitDepts > 0) {
        printf("\nDepartments Exceeding Allocation:\n");
        for (int i = 0; i < count; i++) {
            double rem = calculateRemainingBudget(&budgets[i]);
            if (rem < 0) {
                printf(" - %-18s (Deficit: N$%.2f)\n", budgets[i].department, -rem);
            }
        }
    }
    printf("========================================================\n");
}

void reportsMenu(const Employee empList[], int empCount,
                 const Budget budgets[], int budgetCount,
                 const Supplier suppliers[], int supCount,
                 const Asset assets[], int assetCount) {
    int choice;
    do {
        printf("\n--- MUNICIPAL REPORTING CONSOLE ---\n");
        printf("1. Employee Salary Summary\n");
        printf("2. Consolidated Budget Status\n");
        printf("3. Supplier Register Summary\n");
        printf("4. Asset Inventory Summary\n");
        printf("5. Return to Main Menu\n");
        choice = readPositiveInt("Choice: ");

        switch (choice) {
            case 1: generateEmployeeReport(empList, empCount); break;
            case 2: generateBudgetReport(budgets, budgetCount); break;
            case 3: displaySuppliers(suppliers, supCount); break;
            case 4: displayAssets(assets, assetCount); break;
            case 5: break;
            default: printf("[!] Invalid choice.\n");
        }
    } while (choice != 5);
}