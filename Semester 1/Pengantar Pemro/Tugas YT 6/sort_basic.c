#include <stdio.h>
#include "sorting.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void copyArray(const int *source, int *dest, int n) {
    int i;
    for (i = 0; i < n; i++) {
        *(dest + i) = *(source + i);
    }
}

void bubbleSortAsc(int *arr, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                swap((arr + j), (arr + j + 1));
            }
        }
    }
}

void bubbleSortDesc(int *arr, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (*(arr + j) < *(arr + j + 1)) {
                swap((arr + j), (arr + j + 1));
            }
        }
    }
}

void selectionSortAsc(int *arr, int n) {
    int i, j, minIdx;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (*(arr + j) < *(arr + minIdx)) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap((arr + i), (arr + minIdx));
        }
    }
}

void selectionSortDesc(int *arr, int n) {
    int i, j, maxIdx;
    for (i = 0; i < n - 1; i++) {
        maxIdx = i;
        for (j = i + 1; j < n; j++) {
            if (*(arr + j) > *(arr + maxIdx)) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap((arr + i), (arr + maxIdx));
        }
    }
}