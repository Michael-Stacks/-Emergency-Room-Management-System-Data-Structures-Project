#pragma once


#ifndef FILEDEPATIENT_H
#define FILEDEPATIENT_H

#include "Patient.h"
#include <list>

class FileDePatient {
private:
    std::list<Patient> patients;

public:
    void enqueue(const Patient& patient);
    Patient dequeue();
    bool isEmpty() const;
    size_t getNbPatients() const;
    const std::list<Patient>& getPatients() const;
    Patient* extractFirstWithSpecialty(const std::string& specialty);
    bool hasPatientWithSpecialty(const std::string& specialty) const;
};

#endif // FILEDEPATIENT_H