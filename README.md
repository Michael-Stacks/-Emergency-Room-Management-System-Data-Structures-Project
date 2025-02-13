🏥 Emergency Room Management System – Data Structures Project
Welcome to the Emergency Room Management System! 🚑 This project is part of a Data Structures course and focuses on implementing a priority-based patient management system using custom queues and dynamic memory allocation in C++.

📖 Project Overview
This program simulates a hospital emergency room where patients are treated based on priority levels (HIGH, MEDIUM, LOW) and their required medical specialty. The goal is to ensure patients are treated efficiently while managing limited hospital resources (doctors).

🎯 Key Features
✅ Custom Queue Implementation (not using std::queue)
✅ Patient Prioritization (HIGH > MEDIUM > LOW)
✅ FIFO Treatment Order (First-In-First-Out within each priority)
✅ Dynamic Memory Management (Patients stored as pointers)
✅ Turn-based Simulation (Patients lose turns if not treated)
✅ Failure Handling (Patients who exceed their turns are counted as untreated)

🛠 Data Structures Used
🔹 Custom Queue (FileDePatient) – Implements enqueue/dequeue operations with dynamic storage
🔹 Linked List (std::list internally) – Used for priority queues
🔹 Enumeration (Priority) – Defines patient urgency levels
🔹 Object-Oriented Design – Classes: Patient, PatientManager, HospitalSystem

🚀 How It Works
1️⃣ Patients are added to the system with a defined priority and specialty
2️⃣ Doctors treat patients based on their specialty and availability
3️⃣ Each turn:

Doctors pick the highest-priority patient available
Patients not treated lose a turn
If a patient's turns reach zero, they are marked as untreated
4️⃣ Simulation continues until all patients are either treated or failed

🎓 Learning Outcomes
✅ Understand priority queues and how they apply in real-world scenarios
✅ Implement custom queue structures without using STL queue
✅ Manage memory dynamically with pointers in C++
✅ Develop an efficient simulation system using OOP principles

![Console de débogage Microsoft Visual Studio 2025-02-12 22_41_47](https://github.com/user-attachments/assets/1ad42106-b4d8-4992-8669-06aa43a813e9)

![TP1_KOMI_MICHAEL_IVAN - Microsoft Visual Studio 2025-02-12 22_42_03](https://github.com/user-attachments/assets/c80d8c8f-8c6d-429a-b9e9-3cfc399c752e)

![TP1_KOMI_MICHAEL_IVAN - Microsoft Visual Studio 2025-02-12 22_42_24](https://github.com/user-attachments/assets/edb93408-f9b4-44a0-9451-7f14a57b1916)

![TP1_KOMI_MICHAEL_IVAN - Microsoft Visual Studio 2025-02-12 22_42_39](https://github.com/user-attachments/assets/5ef63c16-eeb2-4718-a148-6edaa0439647)

