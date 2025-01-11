#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"
#include "../../src/mySim.h"
#include "../../src/system.hpp"
#include "../../src/flow.hpp"
#include <iostream>

using namespace std;
int main() {
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();

    return 0;
}

#endif // MAIN_FUNCIONAL_TESTS