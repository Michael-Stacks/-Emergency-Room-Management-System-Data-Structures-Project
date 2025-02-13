#pragma once

#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H

#include "PatientManager.h"
#include <vector>
#include <string>

class HospitalSystem {
private:
    PatientManager* patientManager;
    std::vector<std::string> doctors;
    int failureCount = 0;

public:
    HospitalSystem(PatientManager* pm, const std::vector<std::string>& docs);
    void addPatient(const Patient& patient, Priority priority);
    void processNextPatient(const std::string& doctor);
    void processTurn();
    void displayState() const;
    int getFailureCount() const;
};

#endif // HOSPITALSYSTEM_H