#include <iostream>

#include "systemImplementation.h"

using namespace std;

systemImplementation::systemImplementation() {
    name = "";
    accumulator = 0.0;
}

systemImplementation::systemImplementation(string name) : name(name) {}

systemImplementation::systemImplementation(string name, double accumulator) : name(name), accumulator(accumulator) {}

systemImplementation::~systemImplementation() {}

systemImplementation::systemImplementation(const systemImplementation &other) {
    this->name = other.name;
    this->accumulator = other.accumulator;
}

systemImplementation& systemImplementation::operator=(const systemImplementation &other) {
    if (this == &other) {
        return *this;
    }

    this->name = other.name;
    this->accumulator = other.accumulator;

    return *this;
}


systemImplementation::systemImplementation(systemImplementation &&other) noexcept {
    this->name = other.name;
    this->accumulator = other.accumulator;
    other.name.clear();
    other.accumulator = 0;
}


string systemImplementation::getName() {
    return name;
}

double systemImplementation::getAccumulator() {
    return accumulator;
}

void systemImplementation::setName(string name) {
    this->name = name;
}


void systemImplementation::setAccumulator(double accumulator) {
    this->accumulator = accumulator;
}


