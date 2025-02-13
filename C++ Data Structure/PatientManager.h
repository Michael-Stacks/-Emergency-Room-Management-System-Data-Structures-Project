#pragma once

#ifndef PATIENTMANAGER_H
#define PATIENTMANAGER_H

#include "FileDePatient.h"
#include "Priority.h"

class PatientManager {
private:
    FileDePatient highPriority;
    FileDePatient mediumPriority;
    FileDePatient lowPriority;

    int processQueue(FileDePatient& queue);
    void processLowPriorityUpgrades();

public:
    void addPatient(const Patient& patient, Priority priority);
    Patient* getNextFor(const std::string& specialty);
    int addTurn();
    void displayPatients() const;
    int getNbPatients() const;
    bool hasPatientWithPriority(const std::string& specialty, Priority p);
};

#endif // PATIENTMANAGER_H