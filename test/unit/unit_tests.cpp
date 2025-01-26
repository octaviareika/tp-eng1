#include "unit_tests.h"

void run_unit_tests_globals(){
    unit_System_tests();
    run_unit_tests_Flow();
    run_unit_tests_Sim();
    cout << "All tests passed!" << endl;
}