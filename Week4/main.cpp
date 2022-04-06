#include <iostream>
#include "ns_test.h"
#include <cstdlib>

void test_namespaces();
void filter(int[], int, bool(*)(int));
bool is_even(int);
bool is_odd(int);
int* map(int[], int, int(*)(int));
int square(int);
void print_array(int[], int);

int main() {
    test_namespaces();
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr)/sizeof(int);
    std::cout << "Even numbers are: ";
    filter(arr, size, is_even);
    std::cout << "Odd numbers are: ";
    filter(arr, size, is_odd);
    int* newArr = map(arr, size, square);
    std::cout << "Squared numbers are: ";
    print_array(newArr, size);
    return 0;
}

void print_array(int arr[], int size){
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int square(int nr) {
    return nr*nr;
}

bool is_even(int nr) {
    return nr%2 == 0;
}

bool is_odd(int nr) {
    return !is_even(nr);
}

void test_namespaces() {
    std::cout << "Hello, World!" << std::endl;
    A::foo();
    A::bar();
    B::foo();
    B::bar();
    C::cout(2);
    C::bar();
}

void filter(int arr[], int size, bool (*filter_func)(int)) {
    int i = 0;
    while (i < size) {
        if (filter_func(arr[i]))
            std::cout << arr[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

int* map(int arr[], int size, int(*map_func)(int)) {
    int* newArr = (int*)calloc(size, sizeof(int ));
    int i = 0;
    while (i<size){
        newArr[i] = map_func(arr[i]);
        i++;
    }
    return newArr;
}