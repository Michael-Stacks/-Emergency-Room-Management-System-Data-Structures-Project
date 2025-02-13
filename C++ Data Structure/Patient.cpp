#include "Patient.h"

Patient::Patient(const std::string& name, int age, const std::string& condition, int turnsRemaining, const std::string& requiredSpecialty)
    : name(name), age(age), condition(condition), turnsRemaining(turnsRemaining), requiredSpecialty(requiredSpecialty) {
}

std::string Patient::getName() const { return name; }
std::string Patient::getCondition() const { return condition; }
int Patient::getTurnsRemaining() const { return turnsRemaining; }
std::string Patient::getRequiredSpecialty() const { return requiredSpecialty; }

void Patient::decreaseTurnsRemaining() {
    if (turnsRemaining > 0) turnsRemaining--;
}

void Patient::display() const {
    std::cout << " - " << name << std::endl;
}