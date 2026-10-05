#include <stdio.h>

int main() {
    double diameter, tinggi, jari_jari;
    double volume, luas_permukaan;
    double phi = 3.14159265358979323846;

    printf("=== Program Perhitungan Tabung===\n");

    printf("Masukkan diameter tabung (cm): ");
    scanf("%lf", &diameter);

    printf("Masukkan tinggi tabung (cm): ");
    scanf("%lf", &tinggi);

    jari_jari = diameter / 2.0;

    luas_permukaan = 2 * phi * jari_jari * (jari_jari + tinggi);
    volume = phi * (jari_jari * jari_jari) * tinggi;

    printf("\n=== Hasil Perhitungan ===\n");
    printf("Jari-jari (r)   : %.2lf cm\n", jari_jari);
    printf("Luas permukaan  : %.2lf cm^2\n", luas_permukaan);
    printf("Volume tabung   : %.2lf cm^3\n", volume);

    return 0;
}