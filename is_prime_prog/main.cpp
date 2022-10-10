#include <iostream>
#include "isPrime.h"

int main() {
    int64_t n;
    while(std::cin >> n;){
        if(isPrime(n)){
            std::cout << n << " is a prime: True\n";
        }
        else{
            std::cout << n << " is a prime: False\n";
        }
    }
    return 0;
}
