#include "funcional_tests.h"
#include "../../src/mySim.h"
#include "../../src/systemImplementation.h" // Inclua a implementação concreta do System
#include "../../src/flow.hpp"
#include "../../src/simulatorImplementation.h"
#include "../../src/flowImplementation.h"
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

void exponentialFuncionalTest() {
    cout << "Exponential Funcional Test" << endl;
    System *Q1 = new systemImplementation("Q1", 100);
    System *Q2 = new systemImplementation("Q2", 0);

    Flow *flowExpo = new ExponentialImplementation("Exponential Flow", Q1, Q2, 0.3);

    simulatorImplementation simulator;
    simulator.add(flowExpo);
    simulator.add(Q1);
    simulator.add(Q2);
    simulator.run(0, 100);

    assert(abs((Q1->getAccumulator() - 36.2372) * 10000) <= 1);
    assert(abs((Q2->getAccumulator() - 63.7628) * 10000) <= 1);

    cout << "Exponential Funcional Test Passed" << endl;

    // delete flowExpo;
    // delete Q1;
    // delete Q2;
}

void logisticalFuncionalTest() {
    cout << "Logistical Funcional Test" << endl;
    System *Q1 = new systemImplementation("Q1", 100);
    System *Q2 = new systemImplementation("Q2", 10);

    Flow *flowLog = new LogisticImplementation("Logistic Flow", Q1, Q2, 0.3, 70);

    simulatorImplementation simulator;
    simulator.add(flowLog);
    simulator.add(Q1);
    simulator.add(Q2);
    simulator.run(0, 100);


    // (Q1->getAccumulator() - 88.0666) calcula a diferença entre o valor acumulado de Q1 e o valor esperado 88.0666.
    // (Q2->getAccumulator() - 21.9334) calcula a diferença entre o valor acumulado de Q2 e o valor esperado 21.9334.
    // A verificação é feita usando a função assert para garantir que a diferença entre o valor obtido e o valor esperado seja muito pequena, indicando que o cálculo foi realizado corretamente.*/

    // Substituir os valores abaixo pelos valores reais obtidos
    assert(abs((Q1->getAccumulator() - 88.0666) * 10000) <= 1);
    assert(abs((Q2->getAccumulator() - 21.9334) * 10000) <= 1);

    cout << "Logistical Funcional Test Passed" << endl;
}

void complexFuncionalTest() {
    cout << "Complex Funcional Test" << endl;
    System *Q1 = new systemImplementation("Q1", 100);
    System *Q2 = new systemImplementation("Q2", 0);
    System *Q3 = new systemImplementation("Q3", 100);
    System *Q4 = new systemImplementation("Q4", 0);
    System *Q5 = new systemImplementation("Q5", 0);

    Flow *v = new NewFlowImplementation("V", Q4, Q1, 0.3); // origem destino 
    Flow *g = new NewFlowImplementation("G", Q1, Q3, 0.3);
    Flow *f = new NewFlowImplementation("F", Q1, Q2, 0.3);
    Flow *r = new NewFlowImplementation("R", Q2, Q5, 0.3);
    Flow *t = new NewFlowImplementation("T", Q2, Q3, 0.3);
    Flow *u = new NewFlowImplementation("U", Q3, Q4, 0.3);

    simulatorImplementation simulator;
    simulator.add(v);
    simulator.add(g);
    simulator.add(f);
    simulator.add(r);
    simulator.add(t);
    simulator.add(u);
    simulator.add(Q1);
    simulator.add(Q2);
    simulator.add(Q3);
    simulator.add(Q4);
    simulator.add(Q5);
    simulator.run(0, 100);

    // cout << "Q1 Accumulator: " << Q1->getAccumulator() << endl;
    // cout << "Q2 Accumulator: " << Q2->getAccumulator() << endl;
    // cout << "Q3 Accumulator: " << Q3->getAccumulator() << endl;
    // cout << "Q4 Accumulator: " << Q4->getAccumulator() << endl;
    // cout << "Q5 Accumulator: " << Q5->getAccumulator() << endl;

    // Check the values
    assert(abs((Q1->getAccumulator() - 31.7090) * 10000) <= 1);
    assert(abs((Q2->getAccumulator() - 18.0822) * 10000) <= 1);
    assert(abs((Q3->getAccumulator() - 76.6828) * 10000) <= 1);
    assert(abs((Q4->getAccumulator() - 56.7136) * 10000) <= 1);
    assert(abs((Q5->getAccumulator() - 16.8124) * 10000) <= 1);

    cout << "Complex Funcional Test Passed" << endl;
}