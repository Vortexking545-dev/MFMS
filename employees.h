// employees.h
#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include "common.h"

typedef struct {
    char id[STR_LEN];
    char name[STR_LEN];
    char department[STR_LEN];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
} Employee;

void employeeMenu(Employee empList[], int *empCount);
void addEmployee(Employee empList[], int *empCount);
void displayEmployees(const Employee empList[], int empCount);
int searchEmployeeById(const Employee empList[], int empCount, const char *searchId);
double calculateGrossSalary(const Employee *emp);

#endif