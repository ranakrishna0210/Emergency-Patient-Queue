# Emergency Patient Queue Management System

A C++ console application designed to manage a basic patient queue in a hospital emergency room. The system uses **Priority Queue Logic** implemented via arrays to ensure critical patients are prioritized and called for treatment before less urgent cases.

---

## 👥 Authors
* **Patel Krishita** (Enrollment No: 125021020601058)
* **Rana Krishna** (Enrollment No: 125021020601060)

---

## 🚀 Main Features
1. **Add Patient:** Record basic patient details including Patient ID, Name, Age, and Emergency Priority Level.
2. **Treat Patient:** Automatically selects and calls the patient with the highest priority (Lowest level number = Highest priority).
3. **Display Waiting Patients:** View a complete list of all currently registered patients waiting in the queue.
4. **Display Total Patients:** View real-time statistics of waiting patients, total treated patients, and total registered patients.
5. **Safe Exit:** Safely terminates the program.

---

## 🏥 Priority Levels
The system categorizes patient urgency into three tiers:
* **Level 1 (Critical):** Selected first among all waiting patients.
* **Level 2 (Moderate):** Handled before normal/routine cases.
* **Level 3 (Normal):** Handled after more urgent cases are addressed.

---

## 🛠️ Concepts & Technologies Used
* **Language:** C++
* **Data Structures:** Fixed-size Arrays (for managing independent patient attributes).
* **Control Flow:** Do-While Loops, Conditional If-Else statements.
* **Sorting/Priority Logic:** Basic linear comparison to extract the maximum priority element from the array list.

---

## 💻 Sample Program Interaction
```text
===== EMERGENCY PATIENT QUEUE =====
1. Add Patient
2. Treat Patient
3. Display Waiting Patients
4. Display Total Patients
5. Exit
Enter choice: 1

Enter Patient ID: 101
Enter Patient Name (one word): Krishna
Enter Age: 20
Emergency Level (1=Critical, 2=Moderate, 3=Normal): 1
Patient added successfully!
```

---

## ⚠️ Limitations & Future Scope
* **Current Limitations:** Data is kept strictly in-memory (wipes out on exit) and supports a maximum capacity of 50 patients.
* **Future Improvements:** Adding persistent File/Database storage, implementing advanced Dynamic Linked Lists, and creating a Graphical User Interface (GUI).

