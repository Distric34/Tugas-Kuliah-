#include <stdio.h>
#include "sorting.h"

void insertionSortAsc(int *arr, int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = *(arr + i);
        j = i - 1;
        while (j >= 0 && *(arr + j) > key) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key;
    }
}

void insertionSortDesc(int *arr, int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = *(arr + i);
        j = i - 1;
        while (j >= 0 && *(arr + j) < key) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key;
    }
}