#include <iostream>

#include "./../../src/simulatorImplementation.h"

#ifndef UNIT_SIM_H
#define UNIT_SIM_H

void unit_Sim_constructor(void);
void unit_Sim_destructor(void);
void unit_Sim_getSystems(void);
void unit_Sim_getFlows(void);
// void unit_Sim_setSystems(void);
// void unit_Sim_setFlows(void);
void unit_Sim_run(void);
void unit_sim_add(void);
void run_unit_tests_Sim(void);

#endif