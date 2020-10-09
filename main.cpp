#include <iostream>
#include <fstream>
#include "Random.h"

#include <math.h>
#include <chrono>

#define X_0 (uint64_t)1337133701
#define A (uint64_t)911911927
#define C (uint64_t)666666667
#define M (uint64_t)2282282323
#define DELTA (uint64_t)1

#define N (uint64_t)pow(2, 63)

int main() {
    Random seed(X_0, A, C, M);
    //std::chrono::time_point<std::chrono::steady_clock> start_time, stop_time;

    //std::ofstream file("worktime.txt");

    /*for (unsigned int i = 0; i < (N * DELTA); i += DELTA) {
        start_time = std::chrono::steady_clock::now();

        for (size_t j = 0; j < 100000; ++j)
            seed.fast_rand(i);
        stop_time = std::chrono::steady_clock::now();

        file << std::chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time).count() << std::endl;
        std::cout << i << std::endl;
    }*/

    /*for (uint64_t i = 0; i < (N * DELTA); i += DELTA) {
        std::cout << seed.fast_rand(i) << std::endl;
        std::cout << seed.rand(i) << std::endl;
    }*/

    std::cout << seed.fast_rand(N) << std::endl;
    //std::cout << seed.rand(N) << std::endl;

    return 0;
}
