#include "PatientManager.h"

void PatientManager::addPatient(const Patient& patient, Priority priority) {
    switch (priority) {
    case Priority::HIGH: highPriority.enqueue(patient); break;
    case Priority::MEDIUM: mediumPriority.enqueue(patient); break;
    case Priority::LOW: lowPriority.enqueue(patient); break;
    }
}

Patient* PatientManager::getNextFor(const std::string& specialty) {
    Patient* patient = highPriority.extractFirstWithSpecialty(specialty);
    if (patient) return patient;
    patient = mediumPriority.extractFirstWithSpecialty(specialty);
    if (patient) return patient;
    return lowPriority.extractFirstWithSpecialty(specialty);
}

int PatientManager::addTurn() {
    int failed = processQueue(highPriority) + processQueue(mediumPriority) + processQueue(lowPriority);
    processLowPriorityUpgrades();
    return failed;
}

int PatientManager::processQueue(FileDePatient& queue) {
    int failed = 0;
    size_t size = queue.getNbPatients();
    for (size_t i = 0; i < size; ++i) {
        Patient patient = queue.dequeue();
        patient.decreaseTurnsRemaining();
        if (patient.getTurnsRemaining() > 0) queue.enqueue(patient);
        else failed++;
    }
    return failed;
}

void PatientManager::processLowPriorityUpgrades() {
    size_t size = lowPriority.getNbPatients();
    for (size_t i = 0; i < size; ++i) {
        Patient p = lowPriority.dequeue();
        if (p.getTurnsRemaining() <= 1) {
            mediumPriority.enqueue(p);
        }
        else {
            lowPriority.enqueue(p);
        }
    }
}

void PatientManager::displayPatients() const {
    std::cout << "High priority patients:" << std::endl;
    for (const auto& p : highPriority.getPatients()) p.display();
    std::cout << "Medium priority patients:" << std::endl;
    for (const auto& p : mediumPriority.getPatients()) p.display();
    std::cout << "Low priority patients:" << std::endl;
    for (const auto& p : lowPriority.getPatients()) p.display();
}

int PatientManager::getNbPatients() const {
    return highPriority.getNbPatients() + mediumPriority.getNbPatients() + lowPriority.getNbPatients();
}

bool PatientManager::hasPatientWithPriority(const std::string& specialty, Priority p) {
    switch (p) {
    case Priority::HIGH: return highPriority.hasPatientWithSpecialty(specialty);
    case Priority::MEDIUM: return mediumPriority.hasPatientWithSpecialty(specialty);
    default: return false;
    }
}