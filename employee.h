#ifndef EMPLOYEE_H
#define EMPLOYEE_H

// Define the Employee structure
typedef struct {
    int id;
    char name[50];
    char position[50];
    float salary;
} Employee;

// Function prototypes for Employee Management
void employeeMenu();
void addEmployee();
void viewEmployees();

#endif