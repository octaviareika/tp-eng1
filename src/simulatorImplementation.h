#include <iostream>

#include "mySim.h"

#ifndef MYVENSIM_SIMULATORIMPLEMENTATION_H
#define MYVENSIM_SIMULATORIMPLEMENTATION_H

using namespace std;

class simulatorImplementation : public Simulator {
    private:
        std::vector<System *> systems; ///< Systems
        std::vector<Flow *> flows; ///< Flows

    public:
        simulatorImplementation();
        ~simulatorImplementation();
        simulatorImplementation(const simulatorImplementation &other);
        simulatorImplementation& operator=(const simulatorImplementation &other);
        simulatorImplementation(simulatorImplementation &&other) noexcept;

        void add(System *system) override;
        void add(Flow *flow) override;
        std::vector<System *> getSystems() const override;
        std::vector<Flow *> getFlows() const override;
        void setSystems(std::vector<System *> systems) override;
        void setFlows(std::vector<Flow *> flows) override;
        void run(int initialTime, int finalTime) override;
};

#endif