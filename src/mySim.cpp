#include "mySim.h"
#include <iostream>

Simulator::Simulator() {}

Simulator::~Simulator() {
    for (System *system : systems) {
        delete system;
    }
    for (Flow *flow : flows) {
        delete flow;
    }
}

void Simulator::add(System *system) {
    systems.push_back(system);
}

void Simulator::add(Flow *flow) {
    flows.push_back(flow);
}

std::vector<System *> Simulator::getSystems() const { return systems; }
std::vector<Flow *> Simulator::getFlows() const { return flows; }
void Simulator::setSystems(std::vector<System *> systems) { this->systems = systems; }
void Simulator::setFlows(std::vector<Flow *> flows) { this->flows = flows; }

void Simulator::run(int initialTime, int finalTime) {
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