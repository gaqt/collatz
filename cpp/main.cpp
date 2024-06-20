#include <iostream>

uint64_t collatz(uint64_t seed) {
    uint64_t cnt = 0;
    while (seed > 1) {
        cnt++;
        if (seed % 2 == 0) {
            seed /= 2;
        } else {
            seed = (seed * 3) + 1;
        }
    }

    return cnt;
}

int main() {
    auto start = std::chrono::steady_clock::now();
    for (uint64_t seed = 1; seed <= 100000000; seed++) {
        auto res = collatz(seed);
        if (seed % 1000000 == 0) {
            printf("Seed: %lld Steps: %lld\n", seed, res);
        }
    }

    auto end = std::chrono::steady_clock::now();
    printf("C++ Took %.4f s\n", ((end - start).count() / 1000000000.0));

    return 0;
}

