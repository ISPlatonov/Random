//
// Created by ilush on 04.10.2020.
//

#ifndef RANDOM_RANDOM_H
#define RANDOM_RANDOM_H

#include <vector>

class Random {
public:
    Random(uint64_t X_0, uint64_t A, uint64_t C, uint64_t M);
    uint64_t rand(uint64_t n);
    uint64_t fast_rand(uint64_t n);
    //unsigned int a_n_mod_m(unsigned int n);
    //uint64_t frac_decomp(uint64_t n);

private:
    uint64_t X_0, A, C, M;
    void create_el_list();
    std::vector<uint64_t> el;
    uint64_t a_n_mod_m(uint64_t n);
    //decomposes (a^n - 1) / (a - 1) % m
    uint64_t frac_decomp(uint64_t n);
};


#endif //RANDOM_RANDOM_H
