// reports.h
#ifndef REPORTS_H
#define REPORTS_H

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void generateEmployeeReport(const Employee empList[], int count);
void generateBudgetReport(const Budget budgets[], int count);
void reportsMenu(const Employee empList[], int empCount,
                 const Budget budgets[], int budgetCount,
                 const Supplier suppliers[], int supCount,
                 const Asset assets[], int assetCount);

#endif