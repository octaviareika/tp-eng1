#ifndef FLOWIMPLEMENTATION_H
#define FLOWIMPLEMENTATION_H

#include <iostream>
#include "flow.hpp"

using namespace std;

class FlowImplementation : public Flow {
protected: // Change from private to protected
    std::string idFlow; ///< Flow identifier
    System *source; ///< Source system
    System *target; ///< Target system
    double flowAmount; ///< Flow amount

public:
    FlowImplementation();
    FlowImplementation(std::string idFlow, System *source, System *target, double flowAmount);
    ~FlowImplementation();
    FlowImplementation(const FlowImplementation &other);
    FlowImplementation& operator=(const FlowImplementation &other);
    FlowImplementation(FlowImplementation &&other) noexcept;

    virtual double calculate() = 0;

    System *getSource() override;
    System *getTarget() override;
    void setTarget(System *target) override;
    void setSource(System *source) override;
    std::string getIdFlow() override;
    double getFlowAmount() override;
    void setFlowAmount(double flowAmount) override;
    void setIdFlow(std::string idFlow) override;
};

class ExponentialImplementation : public FlowImplementation {
public:
    ExponentialImplementation();
    ExponentialImplementation(std::string idFlow, System *source, System *target, double flowAmount);
    double calculate() override;
};

class LogisticImplementation : public FlowImplementation {
private:
    double maxCapacity; ///< Maximum capacity

public:
    LogisticImplementation();
    LogisticImplementation(std::string idFlow, System *source, System *target, double flowAmount, double maxCapacity);
    double getMaxCapacity();
    void setMaxCapacity(double maxCapacity);
    double calculate() override;
};

class NewFlowImplementation : public FlowImplementation {
public:
    NewFlowImplementation();
    NewFlowImplementation(std::string idFlow, System *source, System *target, double flowAmount);
    double calculate() override;
    void setIdFlow(std::string idFlow) override;
};

#endif // FLOWIMPLEMENTATION_H