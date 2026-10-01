// suppliers.h
#ifndef SUPPLIERS_H
#define SUPPLIERS_H
#include "common.h"

typedef struct {
    char id[STR_LEN];
    char name[STR_LEN];
    char email[STR_LEN];
    char phone[STR_LEN];
    char location[STR_LEN];
} Supplier;

void supplierMenu(Supplier suppliers[], int *count);
void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(const Supplier suppliers[], int count);
void searchSupplier(const Supplier suppliers[], int count);

#endif