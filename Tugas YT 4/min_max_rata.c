#include <stdio.h>

int main() {
    int n, i;

    do {
        printf("Jumlah data (n): ");
        scanf("%d", &n);

        if (n <= 0 || n > 80) {
            printf("Nilai n keliru! Harap masukkan nilai n pada interval 0 < n <= 80.\n\n");
        }
    } while (n <= 0 || n > 80);

    float data[80];
    float total = 0.0;
    float min, max, rata_rata;

    for (i = 0; i < n; i++) {
        printf("Data ke %d: ", i + 1);
        scanf("%f", &data[i]);
    }

    min = data[0];
    max = data[0];
    total = data[0];

    for (i = 1; i < n; i++) {
        if (data[i] < min) {
            min = data[i];
        }
        if (data[i] > max) {
            max = data[i];
        }
        total += data[i];
    }

    rata_rata = total / n;

    printf("\nContoh output:\n");
    if (min == (int)min) {
        printf("Nilai minimum: %.0f\n", min);
    } else {
        printf("Nilai minimum: %.2f\n", min);
    }

    if (max == (int)max) {
        printf("Nilai maksimum: %.0f\n", max);
    } else {
        printf("Nilai maksimum: %.2f\n", max);
    }

    printf("Nilai rata-rata: %.2f\n", rata_rata);

    return 0;
}