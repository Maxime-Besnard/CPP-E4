#include <iostream>
#include "isPrime.h"
#include <cmath>

int n = 1;
bool isPrime(int64_t n) {
    if (n == 2) {
        return true;
    }
    if (n == 1 || n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}
