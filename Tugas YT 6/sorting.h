#ifndef SORTING_H
#define SORTING_H

#define MAX_DATA 1000

void swap(int *a, int *b);
void copyArray(const int *source, int *dest, int n);
int readDataFromFile(const char *filename, int *arr);
void printArrayHorizontal(const int *arr, int n);
void writeResultToFile(FILE *fp, const char *label, const int *arr, int n);

void bubbleSortAsc(int *arr, int n);
void bubbleSortDesc(int *arr, int n);
void selectionSortAsc(int *arr, int n);
void selectionSortDesc(int *arr, int n);

void insertionSortAsc(int *arr, int n);
void insertionSortDesc(int *arr, int n);

#endif