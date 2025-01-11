#include "flow.hpp"

// Implementação da classe Flow
Flow::Flow(std::string idFlow, System *source, System *target, double flowAmount)
    : idFlow(idFlow), source(source), target(target), flowAmount(flowAmount) {}

Flow::~Flow() {}

std::string Flow::getIdFlow() { return idFlow; }
System *Flow::getSource() { return source; }
System *Flow::getTarget() { return target; }
double Flow::getFlowAmount() { return flowAmount; }

void Flow::setIdFlow(std::string idFlow) { this->idFlow = idFlow; }
void Flow::setSource(System *source) { this->source = source; }
void Flow::setTarget(System *target) { this->target = target; }
void Flow::setFlowAmount(double flowAmount) { this->flowAmount = flowAmount; }

Flow::Flow() {}

Flow::Flow(const Flow &other) { // serve para copiar o objeto
    this->idFlow = other.idFlow;
    this->source = other.source;
    this->target = other.target;
    this->flowAmount = other.flowAmount;
}

Flow &Flow::operator=(const Flow &other) { // serve para copiar o objeto de forma mais eficiente
    this->idFlow = other.idFlow;
    this->source = other.source;
    this->target = other.target;
    this->flowAmount = other.flowAmount;
    return *this;
}

Flow::Flow(Flow &&other) noexcept { // serve para mover o objeto de um lugar para o outro
    this->idFlow = other.idFlow;
    this->source = other.source;
    this->target = other.target;
    this->flowAmount = other.flowAmount;
}

Flow &Flow::operator=(Flow &&other) noexcept {
    this->idFlow = other.idFlow;
    this->source = other.source;
    this->target = other.target;
    this->flowAmount = other.flowAmount;
    return *this;
}


// Implementação da classe Exponential
Exponential::Exponential(std::string idFlow, System *source, System *target, double flowAmount)
    : Flow(idFlow, source, target, flowAmount) {}

Exponential::Exponential() {}

double Exponential::calculate() {
    return 0.01 * this->getSource()->getAccumulator();
}

// Implementação da classe Logistic
Logistic::Logistic(std::string idFlow, System *source, System *target, double flowAmount, double maxCapacity)
    : Flow(idFlow, source, target, flowAmount), maxCapacity(maxCapacity) {}

Logistic::Logistic() {}

double Logistic::getMaxCapacity() { return maxCapacity; }
void Logistic::setMaxCapacity(double maxCapacity) { this->maxCapacity = maxCapacity; }

double Logistic::calculate() {
    return 0.01 * this->getTarget()->getAccumulator() * (1 - this->getTarget()->getAccumulator() / this->maxCapacity);
}

// Implementação da classe NewFlow
NewFlow::NewFlow(std::string idFlow, System *source, System *target, double flowAmount)
    : Flow(idFlow, source, target, flowAmount) {}

NewFlow::NewFlow() {}

double NewFlow::calculate() {
    return 0.01 * this->getSource()->getAccumulator();
}
