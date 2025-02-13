#pragma once



#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>

class Patient {
private:
    std::string name;
    int age;
    std::string condition;
    int turnsRemaining;
    std::string requiredSpecialty;

public:
    Patient(const std::string& name, int age, const std::string& condition, int turnsRemaining, const std::string& requiredSpecialty);
    std::string getName() const;
    std::string getCondition() const;
    int getTurnsRemaining() const;
    std::string getRequiredSpecialty() const;
    void decreaseTurnsRemaining();
    void display() const;
};

#endif // PATIENT_H