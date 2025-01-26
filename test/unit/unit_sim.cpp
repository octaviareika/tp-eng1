#include <iostream>
#include "unit_sim.h"
#include "../../src/systemImplementation.h"
#include "../../src/flowImplementation.h"
#include <cassert>


void unit_Sim_constructor(void) {
    Simulator *sim = new simulatorImplementation();
    assert(sim->getSystems().size() == 0);
}


void unit_Sim_destructor(void) {
}


void unit_Sim_getSystems(void) {
    Simulator *sim = new simulatorImplementation();
    System *sys = new systemImplementation("sys1");

    sim->add(sys);

    // Verify that the system was added correctly
    assert(sim->getSystems().size() == 1);
    assert(sim->getSystems().back() == sys);

}


void unit_Sim_getFlows(void) {
    Simulator *sim = new simulatorImplementation();
    Flow *flow = new NewFlowImplementation();

    sim->add(flow);

    // Verify that the flow was added correctly
    assert(sim->getFlows().size() == 1);
    assert(sim->getFlows().back() == flow);
}

/*assert(abs((Q1->getAccumulator() - 36.2372) * 10000) <= 1);
    assert(abs((Q2->getAccumulator() - 63.7628) * 10000) <= 1);*/


void unit_Sim_run(void) {
    System *sys1 = new systemImplementation("sys1", 100);
    System *sys2 = new systemImplementation("sys2", 0);

    Flow *flow = new ExponentialImplementation("flow", sys1, sys2, 0.3);

    Simulator *sim = new simulatorImplementation();
    sim->add(sys1);
    sim->add(sys2);
    sim->add(flow);

    sim->run(0, 100);

    assert(abs((sys1->getAccumulator() - 36.2372) * 10000) <= 1);
    assert(abs((sys2->getAccumulator() - 63.7628) * 10000) <= 1);

    // delete sim;
    // delete sys1;
    // delete sys2;
    // delete flow;
}


void unit_sim_add(void) {
    Simulator *sim = new simulatorImplementation();
    System *sys = new systemImplementation("sys1");

    sim->add(sys);

    // Verify that the system was added correctly
    assert(sim->getSystems().size() == 1);
    assert(sim->getSystems().back() == sys);

    Flow *flow = new NewFlowImplementation();

    sim->add(flow);

    // Verify that the flow was added correctly
    assert(sim->getFlows().size() == 1);
    assert(sim->getFlows().back() == flow);

    sim->getFlows().clear();
    sim->getSystems().clear();
}

void run_unit_tests_Sim(void) {
    unit_Sim_constructor();
    unit_Sim_destructor();
    unit_Sim_getSystems();
    unit_Sim_getFlows();
    unit_Sim_run();
    unit_sim_add();
    std::cout << "Simulator passed!" << std::endl;
}