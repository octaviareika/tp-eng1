#include <iostream>
#include "./../../src/flowImplementation.h"
#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

void mainFlow();

void unit_Flow_constructor(void);
void unit_Flow_destructor(void);
void unit_Flow_getSource(void);
void unit_Flow_getTarget(void);
void unit_Flow_setSource(void);
void unit_Flow_setTarget(void);
void unit_Flow_calculate(void);
void unit_flow_getIdFlow(void);
void unit_flow_setIdFlow(void);
void unit_flow_getFlowAmount(void);
void unit_flow_setFlowAmount(void);
void unit_default_flow_constructor(void);
void run_unit_tests_Flow(void);

#endif // UNIT_FLOW_H

