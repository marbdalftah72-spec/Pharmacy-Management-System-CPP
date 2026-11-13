# 💊 Modern Pharmacy Management & Dispensing System in C++

[![C++](https://img.shields.io/badge/C%2B%2B-17%2F20-blue.svg?logo=c%2B%2B)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Safety](https://img.shields.io/badge/Safety-Prescription%20Validation-red.svg)](#)

A dedicated healthcare software solution and pharmacy information system designed in modern **C++**. Authored by **Ammar Abdelfattah** for the **Object-Oriented Programming and Software Engineering** curriculum at **Faculty of Engineering – New Ismailia National University (NINU)**.

---

## 📌 Domain Overview & Architecture

Operating a pharmaceutical dispensary demands strict inventory controls, active-substance indexing, patient prescription recordkeeping, and regulated medicine dispensation. This project provides an architecture with:

1. **Pharmaceutical Data Hierarchy**:
   - `Medicine` (Base class): SKU, Commercial Name, Scientific Active Ingredient (Generic Name), Dosage Form (Tablets, Syrup, Injection, Ointment), Concentration, Manufacturer, Batch Number.
   - `PrescriptionMedicine`: Subclass introducing Schedule/Controlled Drug classifications, prescribing physician registration, and dispensing restrictions.
   - `OTC_Medicine` (Over-the-Counter): Consumer products eligible for direct dispensation.
2. **Customer & Patient Registry**:
   - Patient profiling tracking known allergies, chronic conditions, and previous purchase histories to alert against negative drug-drug interactions.
3. **Inventory & Expiration Ledger**:
   - First-In, First-Out (**FIFO**) batch inventory management ensuring older batches are dispensed before newer shipments.
   - Automated expiration notification alerts for batches expiring within 30, 60, or 90 days.
4. **Billing & Prescription Audit Logs**:
   - Itemized invoicing with healthcare insurance discount percentages.
   - Complete audit trail written to disk for state regulatory compliance.

---

## 🏗️ System Workflow

```mermaid
sequenceDiagram
    autonumber
    actor Pharmacist
    participant System as Pharmacy Core
    participant DB as File Storage (FIFO Ledger)
    participant Patient as Patient Allergy Engine

    Pharmacist->>System: Authenticate Login Credentials
    System-->>Pharmacist: Access Granted (Dispenser Mode)
    Pharmacist->>System: Input Prescription (Patient ID + Drug SKU)
    System->>Patient: Check Drug-Drug & Patient Allergy Contraindications
    alt Contraindication Found!
        Patient-->>System: WARNING: Patient allergic to active substance!
        System-->>Pharmacist: Halt Dispensation with Alert
    else Validation Passed
        Patient-->>System: Validation Clear
        System->>DB: Query Batch FIFO Ledger
        DB-->>System: Select oldest valid batch
        System->>DB: Deduct inventory quantity & log transaction
        System-->>Pharmacist: Dispense drug & print medical receipt
    end
```

---

## 🛠️ Build & Installation

```bash
# Clone the repository
git clone https://github.com/marbdalftah72-spec/Pharmacy-Management-System-CPP.git
cd Pharmacy-Management-System-CPP

# Build using g++
g++ -std=c++17 -Wall -Wextra src/*.cpp -I include -o PharmacyApp

# Launch application
./PharmacyApp
```

---

## 👨‍💻 Author

- **Ammar Abdelfattah**
- Faculty of Engineering, **New Ismailia National University (NINU)**
