#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

int readDataFromFile(const char *filename, int *arr) {
    FILE *fp = fopen(filename, "r");
    int count = 0;

    if (fp == NULL) {
        printf("Error: File '%s' tidak dapat dibuka.\n", filename);
        return -1;
    }

    while (count < MAX_DATA && fscanf(fp, "%d", (arr + count)) == 1) {
        count++;
    }

    fclose(fp);
    return count;
}

void printArrayHorizontal(const int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", *(arr + i));
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void writeResultToFile(FILE *fp, const char *label, const int *arr, int n) {
    int i;
    fprintf(fp, "%s\n", label);
    for (i = 0; i < n; i++) {
        fprintf(fp, "%d", *(arr + i));
        if (i < n - 1) {
            fprintf(fp, " ");
        }
    }
    fprintf(fp, "\n");
}

int main(void) {
    int originalData[MAX_DATA];
    int tempData[MAX_DATA];
    int n;
    FILE *outFp;

    n = readDataFromFile("data.txt", originalData);
    if (n <= 0) {
        printf("Gagal membaca data atau file kosong.\n");
        return 1;
    }

    outFp = fopen("luaran.txt", "w");
    if (outFp == NULL) {
        printf("Error: Gagal membuat file 'luaran.txt'.\n");
        return 1;
    }

    copyArray(originalData, tempData, n);
    bubbleSortAsc(tempData, n);
    printf("Bubble Sort (asc)\n");
    printArrayHorizontal(tempData, n);
    writeResultToFile(outFp, "Bubble Sort (asc)", tempData, n);

    copyArray(originalData, tempData, n);
    bubbleSortDesc(tempData, n);
    printf("Bubble Sort (desc)\n");
    printArrayHorizontal(tempData, n);
    writeResultToFile(outFp, "Bubble Sort (desc)", tempData, n);

    copyArray(originalData, tempData, n);
    selectionSortAsc(tempData, n);
    printf("Selection Sort (asc)\n");
    printArrayHorizontal(tempData, n);
    writeResultToFile(outFp, "Selection Sort (asc)", tempData, n);

    copyArray(originalData, tempData, n);
    selectionSortDesc(tempData, n);
    printf("Selection Sort (desc)\n");
    printArrayHorizontal(tempData, n);
    writeResultToFile(outFp, "Selection Sort (desc)", tempData, n);

    copyArray(originalData, tempData, n);
    insertionSortAsc(tempData, n);
    printf("Insertion Sort (asc)\n");
    printArrayHorizontal(tempData, n);
    writeResultToFile(outFp, "Insertion Sort (asc)", tempData, n);

    copyArray(originalData, tempData, n);
    insertionSortDesc(tempData, n);
    printf("Insertion Sort (desc)\n");
    printArrayHorizontal(tempData, n);
    writeResultToFile(outFp, "Insertion Sort (desc)", tempData, n);

    fclose(outFp);
    printf("\nHasil pengurutan berhasil disimpan ke dalam 'luaran.txt'.\n");

    return 0;
}