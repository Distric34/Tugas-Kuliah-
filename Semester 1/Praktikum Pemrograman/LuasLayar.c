#include <stdio.h>

float hitungLuasRadar(float A, float T) {
    return 0.5f * A * T;
}

int main() {
    float A, T;

    if (scanf("%f %f", &A, &T) == 2) {
        float L = hitungLuasRadar(A, T);

        printf("Luas Radar: %.2f\n", L);
    }

    return 0;
}