#include <iostream>

#include "system.hpp"

#ifndef MYVENSIM_SYSTEMIMPLEMENTATION_H
#define MYVENSIM_SYSTEMIMPLEMENTATION_H

using namespace std;

class systemImplementation : public System {
    private:
        string name; ///< System name
        double accumulator; ///< System accumulator

    public:
        systemImplementation();
        systemImplementation(string name, double accumulator);
        ~systemImplementation();
        systemImplementation(const systemImplementation &other);
        systemImplementation& operator=(const systemImplementation &other);
        systemImplementation(systemImplementation &&other) noexcept;
        systemImplementation(string name);

        string getName() override;
        double getAccumulator() override;
        void setName(string name) override;
        void setAccumulator(double accumulator) override;
};



#endif