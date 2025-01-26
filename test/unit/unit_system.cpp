#include "../../src/flowImplementation.h"
#include "unit_system.h"
#include <cassert>

void unit_System_constructor(void){
    System *s1 = new systemImplementation();

    assert(s1->getName() == "");
    assert(s1->getAccumulator() == 0.0);

    systemImplementation *s2 = new systemImplementation("System 2", 10.0);
    assert(s2->getName() == "System 2");
    assert(s2->getAccumulator() == 10.0);

   
}

void unit_System_destructor(void){
   
}

void unit_System_getName(void){
    System *s1 = new systemImplementation("sys1");
    assert(s1->getName() == "sys1");

    
}

void unit_System_setName(void){
    System *s1 = new systemImplementation();
    s1->setName("System 1");
    assert(s1->getName() == "System 1");

    
}

void unit_System_getAccumulator(void){
    System *s1 = new systemImplementation();
    assert(s1->getAccumulator() == 0.0);


}

void unit_System_setAccumulator(void){
    System *s1 = new systemImplementation();
    s1->setAccumulator(10.0);
    assert(s1->getAccumulator() == 10.0);

}

void unit_System_tests(void){
    unit_System_constructor();
    unit_System_destructor();
    unit_System_getName();
    unit_System_setName();
    unit_System_getAccumulator();
    unit_System_setAccumulator();
    cout << "All System tests passed" << endl;
}


