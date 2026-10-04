// budget.c
#include <stdio.h>
#include <string.h>
#include "budget.h"

double calculateRemainingBudget(const Budget *b) {
    return b->allocatedBudget - b->expenditure;
}

void addDepartmentBudget(Budget budgets[], int *deptCount) {
    if (*deptCount >= MAX_ITEMS) {
        printf("[!] Department limit reached.\n");
        return;
    }
    Budget b;
    readString("Department Name: ", b.department, STR_LEN);
    b.allocatedBudget = readPositiveDouble("Allocated Budget (N$): ");
    b.expenditure = 0.0;

    budgets[*deptCount] = b;
    (*deptCount)++;
    printf("[+] Department budget allocated.\n");
}

void recordExpenditure(Budget budgets[], int deptCount) {
    char dept[STR_LEN];
    readString("Enter Department Name: ", dept, STR_LEN);
    for (int i = 0; i < deptCount; i++) {
        if (strcmp(budgets[i].department, dept) == 0) {
            double amount = readPositiveDouble("Expenditure to add (N$): ");
            budgets[i].expenditure += amount;
            printf("[+] Expenditure logged. New remaining: N$%.2f\n", calculateRemainingBudget(&budgets[i]));
            return;
        }
    }
    printf("[!] Department not found.\n");
}

void displayBudgets(const Budget budgets[], int deptCount) {
    if (deptCount == 0) {
        printf("No budgets registered.\n");
        return;
    }
    printf("\n%-18s %-15s %-15s %-15s %-15s\n", "Department", "Allocated (N$)", "Spent (N$)", "Remaining (N$)", "Status");
    printf("----------------------------------------------------------------------------------\n");
    for (int i = 0; i < deptCount; i++) {
        double rem = calculateRemainingBudget(&budgets[i]);
        const char *status = (rem >= 0) ? "WITHIN BUDGET" : "OVER BUDGET";
        printf("%-18s %-15.2f %-15.2f %-15.2f %-15s\n",
               budgets[i].department, budgets[i].allocatedBudget, budgets[i].expenditure, rem, status);
    }
}

void budgetMenu(Budget budgets[], int *deptCount) {
    int choice;
    do {
        printf("\n--- BUDGET MANAGEMENT ---\n");
        printf("1. Set Department Budget\n");
        printf("2. Log Expenditure\n");
        printf("3. Display Budgets\n");
        printf("4. Return to Main Menu\n");
        choice = readPositiveInt("Choice: ");

        switch (choice) {
            case 1: addDepartmentBudget(budgets, deptCount); break;
            case 2: recordExpenditure(budgets, *deptCount); break;
            case 3: displayBudgets(budgets, *deptCount); break;
            case 4: break;
            default: printf("[!] Invalid selection.\n");
        }
    } while (choice != 4);
}