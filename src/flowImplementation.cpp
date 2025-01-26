#include "flowImplementation.h"

using namespace std;

FlowImplementation::FlowImplementation() {
    this->idFlow = "";
    this->source = nullptr;
    this->target = nullptr;
    this->flowAmount = 0;
}

FlowImplementation::FlowImplementation(std::string idFlow, System *source, System *target, double flowAmount) {
    this->idFlow = idFlow;
    this->source = source;
    this->target = target;
    this->flowAmount = flowAmount;
}

FlowImplementation::~FlowImplementation() {
    
}

FlowImplementation::FlowImplementation(const FlowImplementation &other) {
    this->idFlow = other.idFlow;
    this->source = other.source;
    this->target = other.target;
    this->flowAmount = other.flowAmount;
}

FlowImplementation& FlowImplementation::operator=(const FlowImplementation &other) {
    this->idFlow = other.idFlow;
    this->source = other.source;
    this->target = other.target;
    this->flowAmount = other.flowAmount;
    return *this;
}

FlowImplementation::FlowImplementation(FlowImplementation &&other) noexcept {
    this->idFlow = other.idFlow;
    this->source = other.source;
    this->target = other.target;
    this->flowAmount = other.flowAmount;
    other.idFlow = "";
    other.source = nullptr;
    other.target = nullptr;
    other.flowAmount = 0;
}

System *FlowImplementation::getSource() {
    return this->source;
}

System *FlowImplementation::getTarget() {
    return this->target;
}

void FlowImplementation::setTarget(System *target) {
    this->target = target;
}

void FlowImplementation::setSource(System *source) {
    this->source = source;
}

std::string FlowImplementation::getIdFlow() {
    return this->idFlow;
}

double FlowImplementation::getFlowAmount() {
    return this->flowAmount;
}

void FlowImplementation::setFlowAmount(double flowAmount) {
    this->flowAmount = flowAmount;
}

void FlowImplementation::setIdFlow(std::string idFlow) {
    this->idFlow = idFlow;
}

// ExponentialImplementation

ExponentialImplementation::ExponentialImplementation() : FlowImplementation() {}

ExponentialImplementation::ExponentialImplementation(std::string idFlow, System *source, System *target, double flowAmount)
    : FlowImplementation(idFlow, source, target, flowAmount) {}

double ExponentialImplementation::calculate() {
    return 0.01 * this->getSource()->getAccumulator();
}

// LogisticImplementation

LogisticImplementation::LogisticImplementation() : FlowImplementation() {
    this->maxCapacity = 0;
}

LogisticImplementation::LogisticImplementation(std::string idFlow, System *source, System *target, double flowAmount, double maxCapacity)
    : FlowImplementation(idFlow, source, target, flowAmount) {
    this->maxCapacity = maxCapacity;
}

double LogisticImplementation::getMaxCapacity() {
    return this->maxCapacity;
}

void LogisticImplementation::setMaxCapacity(double maxCapacity) {
    this->maxCapacity = maxCapacity;
}

double LogisticImplementation::calculate() {
    return 0.01 * this->getTarget()->getAccumulator() * (1 - this->getTarget()->getAccumulator() / this->maxCapacity);
}

// NewFlowImplementation

NewFlowImplementation::NewFlowImplementation() : FlowImplementation() {}

NewFlowImplementation::NewFlowImplementation(std::string idFlow, System *source, System *target, double flowAmount)
    : FlowImplementation(idFlow, source, target, flowAmount) {}

double NewFlowImplementation::calculate() {
    return 0.01 * this->getSource()->getAccumulator();
}

void NewFlowImplementation::setIdFlow(std::string idFlow) {
    this->idFlow = idFlow;
}