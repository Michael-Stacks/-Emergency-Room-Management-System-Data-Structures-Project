#include "HospitalSystem.h"
#include <iostream>

HospitalSystem::HospitalSystem(PatientManager* pm, const std::vector<std::string>& docs)
    : patientManager(pm), doctors(docs) {
}

void HospitalSystem::addPatient(const Patient& patient, Priority priority) {
    patientManager->addPatient(patient, priority);
}

void HospitalSystem::processNextPatient(const std::string& doctor) {
    Patient* patient = patientManager->getNextFor(doctor);
    if (patient) {
        std::cout << "Patient " << patient->getName() << " is being treated by " << doctor << "." << std::endl;
        delete patient;
    }
}

void HospitalSystem::processTurn() {
    // Traiter HIGH et MEDIUM d'abord
    for (const auto& doc : doctors) {
        if (patientManager->hasPatientWithPriority(doc, Priority::HIGH) ||
            patientManager->hasPatientWithPriority(doc, Priority::MEDIUM)) {
            processNextPatient(doc);
        }
    }

    // Mettre à jour les tours restants et les échecs
    failureCount += patientManager->addTurn();
}

void HospitalSystem::displayState() const {
    patientManager->displayPatients();
}

int HospitalSystem::getFailureCount() const {
    return failureCount;
}