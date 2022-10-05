#include <iostream>
#include "isPrime.h"

void main() {
    int64_t n;
    while(std::cin.peek() != '\n'){
	std::cin >> n;
        if(isPrime(n)){
            std::cout << n << " is a prime: True\n";
        }
        else{
            std::cout << n << " is a prime: False\n";
        }
    }
    return;
}
