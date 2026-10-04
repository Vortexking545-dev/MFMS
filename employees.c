// employees.c
#include <stdio.h>
#include <string.h>
#include "employees.h"

double calculateGrossSalary(const Employee *emp) {
    return emp->basicSalary + emp->housingAllowance + emp->transportAllowance;
}

int searchEmployeeById(const Employee empList[], int empCount, const char *searchId) {
    for (int i = 0; i < empCount; i++) {
        if (strcmp(empList[i].id, searchId) == 0) {
            return i;
        }
    }
    return -1;
}

void addEmployee(Employee empList[], int *empCount) {
    if (*empCount >= MAX_ITEMS) {
        printf("[!] Employee roster full.\n");
        return;
    }
    Employee e;
    readString("Enter Employee ID: ", e.id, STR_LEN);
    if (searchEmployeeById(empList, *empCount, e.id) != -1) {
        printf("[!] Error: Employee ID already exists.\n");
        return;
    }
    readString("Enter Full Name: ", e.name, STR_LEN);
    readString("Enter Department: ", e.department, STR_LEN);
    e.basicSalary = readPositiveDouble("Enter Basic Salary (N$): ");
    e.housingAllowance = readPositiveDouble("Enter Housing Allowance (N$): ");
    e.transportAllowance = readPositiveDouble("Enter Transport Allowance (N$): ");

    empList[*empCount] = e;
    (*empCount)++;
    printf("[+] Employee successfully registered.\n");
}

void displayEmployees(const Employee empList[], int empCount) {
    if (empCount == 0) {
        printf("No employee records found.\n");
        return;
    }
    printf("\n%-10s %-20s %-15s %-12s %-12s\n", "ID", "Name", "Dept", "Basic (N$)", "Gross (N$)");
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < empCount; i++) {
        printf("%-10s %-20s %-15s %-12.2f %-12.2f\n",
               empList[i].id, empList[i].name, empList[i].department,
               empList[i].basicSalary, calculateGrossSalary(&empList[i]));
    }
}

void employeeMenu(Employee empList[], int *empCount) {
    int choice;
    do {
        printf("\n--- EMPLOYEE MANAGEMENT ---\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Return to Main Menu\n");
        choice = readPositiveInt("Choice: ");

        switch (choice) {
            case 1: addEmployee(empList, empCount); break;
            case 2: displayEmployees(empList, *empCount); break;
            case 3: {
                char sId[STR_LEN];
                readString("Enter Employee ID to search: ", sId, STR_LEN);
                int idx = searchEmployeeById(empList, *empCount, sId);
                if (idx != -1) {
                    printf("\nFound: %s | %s | Dept: %s | Gross: N$%.2f\n",
                           empList[idx].id, empList[idx].name, empList[idx].department,
                           calculateGrossSalary(&empList[idx]));
                } else {
                    printf("[!] Record not found.\n");
                }
                break;
            }
            case 4: break;
            default: printf("[!] Invalid option.\n");
        }
    } while (choice != 4);
}