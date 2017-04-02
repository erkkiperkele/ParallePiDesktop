#include <iostream>
#include <chrono>
#include "ParallelCalculations.h"

typedef std::chrono::high_resolution_clock Clock;
using namespace std;

int main(int argc, char *argv[]) {

    int numberOfOperations= 50000000;
    int numberOfThreads = 8;

    auto t1 = Clock::now();
    float PIMulti = ParallelCalculations::CalculateParallelPi(numberOfOperations, numberOfThreads);

    auto t2 = Clock::now();
    float PISingle = ParallelCalculations::CalculateParallelPi(numberOfOperations, 1);

    auto t3 = Clock::now();

    cout << endl;
    cout << numberOfThreads << " Threads pi: " << PIMulti << endl;
    cout << numberOfThreads << " threads took: "
         << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count()
         << " milliseconds" << endl;

    cout << endl;

    cout << "1 Thread pi: " << PISingle << endl;
    cout << "1 thread took: "
         << chrono::duration_cast<chrono::milliseconds>(t3 - t2).count()
         << " milliseconds" << endl;
}