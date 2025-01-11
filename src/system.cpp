#include "./system.hpp"

System::System() {}

System::System(const System &other) {
    this->name = other.name;
    this->accumulator = other.accumulator;
}

System::System(std::string name, double accumulator) : name(name), accumulator(accumulator) {}

System::System(std::string name) : name(name), accumulator(0) {}

System::~System() {}

std::string System::getName() { return name; }

double System::getAccumulator() { return accumulator; }

void System::setName(std::string name) { this->name = name; }

void System::setAccumulator(double accumulator) { this->accumulator = accumulator; }

System::System(System &&other) noexcept {
    this->name = other.name;
    this->accumulator = other.accumulator;
}

System &System::operator=(System &&other) noexcept {
    this->name = other.name;
    this->accumulator = other.accumulator;
    return *this;
}

