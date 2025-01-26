#include <iostream>

#include "unit_flow.h"
#include <cassert>
#include <cmath>
#include "./../../src/systemImplementation.h"

void unit_default_flow_constructor(void){
    Flow *flow = new NewFlowImplementation();
    assert(flow->getIdFlow() == "");
    assert(flow->getSource() == nullptr);
    assert(flow->getTarget() == nullptr);
    assert(flow->getFlowAmount() == 0);
}


void unit_Flow_constructor(void) {

    System *source = new systemImplementation();
    System *target = new systemImplementation();
    Flow *flow = new NewFlowImplementation("flow", source, target, 10);

    assert(flow->getIdFlow() == "flow");
    assert(flow->getSource() == source);
    assert(flow->getTarget() == target);
    assert(flow->getFlowAmount() == 10);

}

void unit_Flow_destructor(void) {
    
}

void unit_flow_getFlowAmount(void){
    Flow *flow = new NewFlowImplementation();
    assert(flow->getFlowAmount() == 0);
}

void unit_flow_setFlowAmount(void){
    Flow *flow = new NewFlowImplementation();
    flow->setFlowAmount(10);
    assert(flow->getFlowAmount() == 10);
}

void unit_Flow_getSource(void) {
    System *source = new systemImplementation();
    
    Flow *flow = new NewFlowImplementation("flow", source, nullptr, 10);

    assert(flow->getSource() == source);
}

void unit_Flow_getTarget(void) {
    System *target = new systemImplementation();
    
    Flow *flow = new NewFlowImplementation("flow", nullptr, target, 10);

    assert(flow->getTarget() == target);
}

void unit_Flow_setSource(void) {
    System *source = new systemImplementation();
    Flow *flow = new NewFlowImplementation();

    flow->setSource(source);

    assert(flow->getSource() == source);
}

void unit_Flow_setTarget(void) {
    System *target = new systemImplementation();
    Flow *flow = new NewFlowImplementation();

    flow->setTarget(target);

    assert(flow->getTarget() == target);
}

void unit_Flow_calculate(void) {
    System *source = new systemImplementation();
    System *target = new systemImplementation();
    Flow *flow = new NewFlowImplementation("flow", source, target, 10);

    assert(flow->calculate() == 0.01 * source->getAccumulator());
}

void unit_flow_getIdFlow(void){
    Flow *flow = new NewFlowImplementation("flow", nullptr, nullptr, 0);
    assert(flow->getIdFlow() == "flow");
}

void unit_flow_setIdFlow(void){
    Flow *flow = new NewFlowImplementation();
    flow->setIdFlow("flow");
    assert(flow->getIdFlow() == "flow");
}

void run_unit_tests_Flow(void) {
    unit_default_flow_constructor();
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_getSource();
    unit_Flow_getTarget();
    unit_Flow_setSource();
    unit_Flow_setTarget();
    unit_Flow_calculate();
    unit_flow_getIdFlow();
    unit_flow_setIdFlow();
    unit_flow_getFlowAmount();
    unit_flow_setFlowAmount();
    cout << "All Flow tests passed" << endl;
}