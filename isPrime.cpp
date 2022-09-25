#include <iostream>

bool isPrime(int n);

void main(){
    int n;
    int i = 0;
    bool b;

    while(i < 3){

        while (std::cin >> n) {

            b = isPrime(n);

            if (b == 0) {
                std::cout << n << " is a prime: False\n";
            }
            else {
                std::cout << n << " is a prime: True\n";
            }
            i++;
        }
    }

    return;
}

bool isPrime(int n) {
    if (n == 1) {
        return false;
    }
    if (n%2 == 0) {
        return false;
    }

    for (int i = 3; i < n; i += 2) {

        if (n % i == 0) {
            return false;
        }
    }

    return true;
}