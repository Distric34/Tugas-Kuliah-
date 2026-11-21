#include <stdio.h>

void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sinkronisasiEnergi(int *arr, int n, int x) {
    for (int i = 0; i < n / 2; i++) {
        tukar(&arr[i], &arr[n - 1 - i]);
    }
    
    for (int i = 0; i < n; i++) {
        *(arr + i) += x;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    sinkronisasiEnergi(arr, n, x);

    for (int i = 0; i < n; i++) {
        printf("[%d]", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}