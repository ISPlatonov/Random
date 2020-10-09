//
// Created by ilush on 04.10.2020.
//

#include <iostream>
#include "Random.h"

Random::Random(uint64_t X_0, uint64_t A, uint64_t C, uint64_t M) {
    if (M < 2)
    {
        return;
    }
    this->X_0 = X_0;
    this->A = A;
    this->C = C;
    this->M = M;

    create_el_list();
}

uint64_t Random::rand(uint64_t n) {
    return this->el[n % this->el.size()];
}

void Random::create_el_list() {
    this->el.clear();
    this->el.push_back(this->X_0);
    uint64_t x = this->X_0;
    for (uint64_t i = 0; i < this->M; ++i)
    {
        x = ((this->A * x) % M + this->C) % M;
        if (x == this->X_0)
            return;
        this->el.push_back((uint64_t)x);
    }
}

uint64_t Random::fast_rand(uint64_t n) {
    //(X_0 * (unsigned long long)(pow(A, N)) + ((unsigned long long)(pow(A, N)) / (A - 1)) * C) % M
    //unsigned long long a_n = 1;
    auto a_n_mod_m = this->a_n_mod_m(n);
    //std::cout << "a^n % m = " << a_n_mod_m << std::endl;
    //std::cout << "(((frac_decomp(n))) * C) % m = " << (((frac_decomp(n))) * C) % M << std::endl;

    //return ((a_n_mod_m * X_0) % M + ((((a_n_mod_m - 1) / (A - 1)) * C) % M)) % M;
    return ((a_n_mod_m * X_0) % M + (frac_decomp(n) % M) * C) % M;+
}

uint64_t Random::a_n_mod_m(uint64_t n) {
    if (!n)
        return 1;
    auto An = A;
    uint64_t result = 1;
    auto nn = n;
    while (n > 1)
    {
        if (n % 2) {
            result *= An;
            result %= M;
        }
        An = An * An % M;
        n /= 2;
    }
    result *= An;
    result %= M;
    return result;
}

uint64_t Random::frac_decomp(uint64_t n) {
    if (n == 1 || !n)
        return n;
    //return (a_n_mod_m(n - n / 2) * (frac_decomp(n / 2) % M) + (frac_decomp(n - n / 2) % M));
    return (((a_n_mod_m(n - n / 2) + 1) % M) * (frac_decomp(n / 2) % M) + (n % 2) * a_n_mod_m(n / 2));
}