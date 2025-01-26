#include <iostream>

#include "simulatorImplementation.h"

using namespace std;


simulatorImplementation::simulatorImplementation() {}


simulatorImplementation::~simulatorImplementation() {

}


simulatorImplementation::simulatorImplementation(const simulatorImplementation &other) {
    this->systems = other.systems;
    this->flows = other.flows;
}


simulatorImplementation& simulatorImplementation::operator=(const simulatorImplementation &other) {
    if (this == &other) {
        return *this;
    }

    this->systems = other.systems;
    this->flows = other.flows;

    return *this;
}


simulatorImplementation::simulatorImplementation(simulatorImplementation &&other) noexcept {
    this->systems = other.systems;
    this->flows = other.flows;
    other.systems.clear();
    other.flows.clear();
}


void simulatorImplementation::add(System *system) {
    systems.push_back(system);
}


void simulatorImplementation::add(Flow *flow) {
    flows.push_back(flow);
}


std::vector<System *> simulatorImplementation::getSystems() const {
    return systems;
}


std::vector<Flow *> simulatorImplementation::getFlows() const {
    return flows;
}


void simulatorImplementation::setSystems(std::vector<System *> systems) {
    this->systems = systems;
}


void simulatorImplementation::setFlows(std::vector<Flow *> flows) {
    this->flows = flows;
}


void simulatorImplementation::run(int initialTime, int finalTime) {
    for (int time = initialTime; time <= finalTime; ++time) {
        // std::cout << "Time: " << time << std::endl;
        for (Flow *flow : flows) {
            double amount = flow->calculate();
            System *source = flow->getSource();
            System *target = flow->getTarget();
            if (source) {
                source->setAccumulator(source->getAccumulator() - amount);
            }
            if (target) {
                target->setAccumulator(target->getAccumulator() + amount);
            }
        }
        // for (System *system : systems) {
        //     std::cout << system->getName() << ": " << system->getAccumulator() << std::endl;
        // }
    }

    // instanciar 
}