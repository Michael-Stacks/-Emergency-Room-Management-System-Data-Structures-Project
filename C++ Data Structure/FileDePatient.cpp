#include "FileDePatient.h"
#include <stdexcept>

void FileDePatient::enqueue(const Patient& patient) {
    patients.push_back(patient);
}

Patient FileDePatient::dequeue() {
    if (patients.empty()) throw std::out_of_range("File vide");
    Patient front = patients.front();
    patients.pop_front();
    return front;
}

bool FileDePatient::isEmpty() const {
    return patients.empty();
}

size_t FileDePatient::getNbPatients() const {
    return patients.size();
}

const std::list<Patient>& FileDePatient::getPatients() const {
    return patients;
}

Patient* FileDePatient::extractFirstWithSpecialty(const std::string& specialty) {
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (it->getRequiredSpecialty() == specialty) {
            Patient extracted = *it;
            patients.erase(it);
            return new Patient(extracted);
        }
    }
    return nullptr;
}

bool FileDePatient::hasPatientWithSpecialty(const std::string& specialty) const {
    for (const auto& patient : patients) {
        if (patient.getRequiredSpecialty() == specialty) return true;
    }
    return false;
}