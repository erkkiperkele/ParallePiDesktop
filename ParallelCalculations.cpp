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
        int threadNumberOfOperations = numberOfOperations / omp_get_num_threads();
        int innerCircleCount = 0;

        for (int i = 0; i < threadNumberOfOperations; i++) {
            float x = (float) rand() / (float) RAND_MAX;
            float y = (float) rand() / (float) RAND_MAX;
            bool isInCircle = ParallelCalculations::FindIsInCircle(x, y);

            if (isInCircle) {
                ++innerCircleCount;
            }
        }

#pragma omp atomic
        circle_count += innerCircleCount;

    }

    Print("Circle Count: ", circle_count);
    float PI = 4 * (float) circle_count / (float) numberOfOperations;
    return PI;
}

bool ParallelCalculations::FindIsInCircle(float x, float y) {
    double distance = sqrt(pow(x, 2) + pow(y, 2));
    return distance < 1;
}

// For debugging purposes only
void ParallelCalculations::Print(string message, int number) {
    stringstream actualNumberOfThreadsStream;
    actualNumberOfThreadsStream << "DEBUG -  " << message << number << endl;
    string actualNumberOfThreadsMessage = actualNumberOfThreadsStream.str();

    cout << actualNumberOfThreadsMessage;
}