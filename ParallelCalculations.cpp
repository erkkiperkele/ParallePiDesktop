#include <cstdlib>
#include <cmath>
#include <string>

#include <omp.h>
#include <iostream>
#include <sstream>
#include "ParallelCalculations.h"

using namespace std;


float ParallelCalculations::CalculateParallelPi(int numberOfOperations, int numberOfThreads) {
    int circle_count = 0;

#pragma omp parallel num_threads(numberOfThreads)
    {
        int actualThreadNumber = omp_get_num_threads();
        int threadNumberOfOperations = numberOfOperations/actualThreadNumber;

        //#pragma omp for
        for (int i = 0; i < threadNumberOfOperations; i++) {
            float x = (float) rand() / (float) RAND_MAX;
            float y = (float) rand() / (float) RAND_MAX;
            bool isInCircle = ParallelCalculations::FindIsInCircle(x, y);

            if (isInCircle) {
                #pragma omp atomic
                ++circle_count;
            }
        }
    }

    float PI = 4 * (float) circle_count / (float) numberOfOperations;
    return PI;
}

bool ParallelCalculations::FindIsInCircle(float x, float y) {
    double distance = sqrt(pow(x, 2) + pow(y, 2));
    return distance < 1;
}

// For debugging purposes only
void ParallelCalculations::printNumberOfThreads(int actualThreadNumber) {
    stringstream actualNumberOfThreadsStream;
    actualNumberOfThreadsStream << "Actual # of Threads: " << actualThreadNumber << endl;
    string actualNumberOfThreadsMessage = actualNumberOfThreadsStream.str();

    cout << actualNumberOfThreadsMessage;
}