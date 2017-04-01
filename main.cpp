#include <iostream>
#include <chrono>
#include "ParallelCalculations.h"

typedef std::chrono::high_resolution_clock Clock;
using namespace std;

int main(int argc, char *argv[]) {

    int numberOfOperations= 25000000;

    auto t1 = Clock::now();
    float PI = ParallelCalculations::CalculateParallelPi(numberOfOperations, 4);

    auto t2 = Clock::now();
    float PI1 = ParallelCalculations::CalculateParallelPi(numberOfOperations, 1);

    auto t3 = Clock::now();

    cout << endl;
    cout << "4 Threads pi: " << PI << endl;
    cout << "4 threads took: "
         << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count()
         << " milliseconds" << endl;

    cout << endl;

    cout << "1 Thread pi: " << PI1 << endl;
    cout << "1 thread took: "
         << chrono::duration_cast<chrono::milliseconds>(t3 - t2).count()
         << " milliseconds" << endl;
}