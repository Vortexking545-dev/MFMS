// budget.h
#ifndef BUDGET_H
#define BUDGET_H
#include "common.h"

typedef struct {
    char department[STR_LEN];
    double allocatedBudget;
    double expenditure;
} Budget;

void budgetMenu(Budget budgets[], int *deptCount);
void addDepartmentBudget(Budget budgets[], int *deptCount);
void recordExpenditure(Budget budgets[], int deptCount);
void displayBudgets(const Budget budgets[], int deptCount);
double calculateRemainingBudget(const Budget *b);

#endif