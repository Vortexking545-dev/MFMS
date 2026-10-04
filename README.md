# Municipal Financial Management System (MFMS) - Project A

**Group Number:** 20  
**Course:** Programming in Practice  

---

## 1. Group Members & Responsibilities

| **Mathias Indongo** | 22406284 | tvjacks | • **Employee Management** (`employees.c`, `employees.h`)<br>• **Budget Management** (`budget.c`, `budget.h`)<br>• **Common Utilities & Validation** (`common.c`, `common.h`) |
| **Mikael Imbili** | 224039113 | Vortexking545-dev | • **Supplier Management** (`suppliers.c`, `suppliers.h`)<br>• **Asset Register** (`assets.c`, `assets.h`)<br>• **Reports Engine** (`reports.c`, `reports.h`)<br>• **Main Menu Integration** (`main.c`) |

---

## 2. Project Description

The **Municipal Financial Management System (MFMS)** is a foundational, modular console-based application written in C (C99 standard). Designed as the functional baseline (Project A) for a municipal resource management suite, the system enables local government administrators to maintain staff records, regulate departmental budget expenditure, monitor vendor supply chains, and audit municipal assets.

The application adheres strictly to standard structured programming principles: modular decomposition across distinct source/header files, robust input sanitization, pass-by-reference logic, and standard string/array manipulation techniques.

---

## 3. System Features

### Module 1: Employee Management
* Register employees with complete salary structures (Basic, Housing, and Transport allowances).
* Automatic gross salary computation (Basic + Housing + Transport).
* Search records by unique Employee ID (`strcmp`).
* Display complete personnel listings in formatted tables.
* Duplicate ID rejection and non-negative numeric input constraints.

### Module 2: Budget Management
* Allocate departmental operational budgets in Namibian Dollars (N$).
* Log department expenditures and calculate real-time remaining balances.
* Automatically detect budget deficits and flag status as `WITHIN BUDGET` or `OVER BUDGET`.
* Display municipal-wide departmental expenditure registers.

### Module 3: Supplier Management
* Maintain municipal vendor registries (ID, Name, Email, Telephone, and Town/Location).
* Substring search via `strstr()` (searchable by supplier name or town).
* Formatted supplier directory listing.

### Module 4: Asset Management
* Log municipal property across multiple categories (Vehicles, IT Equipment, Real Estate, Office Furniture).
* Track purchase valuation and operational conditions (`Good`, `Fair`, `Poor`).
* Search assets by unique Asset ID.

### Module 5: Aggregated Reporting
* **Employee Summary Report**: Calculates total municipal headcount, cumulative payroll cost, average salary, highest gross earner, and lowest gross earner.
* **Budget Status Report**: Aggregates total municipal allocation versus actual expenditure, overall net surplus/deficit, and explicitly lists departments operating in a deficit.
* **Master Summaries**: Quick audit views of the entire supplier and asset registers.

### Module 6: Data Handling & Validation
* Buffer-safe string input using `fgets()` with newline character sanitization (`strcspn`).
* Strict validation preventing empty string submissions.
* Standardized buffer clearing (`clearInputBuffer()`) preventing numeric-to-string input skipping.
* Validation guards blocking negative salaries, negative budgets, and out-of-range menu selections.

---

## 4. Project Structure

```text
MFMS/
│
├── main.c           # Main execution loop and primary menu controller
├── common.h         # Shared definitions, limits, and helper prototypes
├── common.c         # Central input-validation and stream-flushing functions
├── employees.h      # Employee structure definitions and prototypes
├── employees.c      # Employee registration, searching, and payroll logic
├── budget.h         # Budget structure definitions and prototypes
├── budget.c         # Allocation, expense logging, and deficit checks
├── suppliers.h      # Supplier structure definitions and prototypes
├── suppliers.c      # Vendor management and partial-text search logic
├── assets.h         # Municipal asset register structure and prototypes
├── assets.c         # Asset logging, condition tracking, and search
├── reports.h        # Reporting engine prototypes
├── reports.c        # Statistical aggregations and audit generators
├── .gitignore       # Excludes binaries (*.exe, *.o) and editor settings
└── README.md        # System documentation and build manual
