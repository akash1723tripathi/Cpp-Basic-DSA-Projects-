#include <iostream>
using namespace std;

int* printDivisors(int n, int &size) {
    int* temp = new int[n]; // temporary array to hold divisors
    size = 0;

    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            temp[size++] = i; // store divisor and increment size
        }
    }

    // Create exact-sized array to return
    int* result = new int[size];
    for(int i = 0; i < size; i++) {
        result[i] = temp[i];
    }

    delete[] temp; // free temporary memory
    return result;
}
