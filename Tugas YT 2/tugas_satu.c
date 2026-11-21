#include <stdio.h>

int main (){
    float s1, s2, s3;

    printf("=== Program Menentukan Jenis Segitiga ===\n");
    printf("Masukkan sisi pertama: ");
    scanf("%f", &s1);
    printf("Masukkan sisi kedua: ");
    scanf("%f", &s2);
    printf("Masukkan sisi ketiga: ");
    scanf("%f", &s3);

    if (s1 == s2 && s2 == s3) {
        printf("Segitiga sama sisi\n");
    } else if (s1 == s2 || s2 == s3 || s1 == s3) {
        printf("Segitiga sama kaki\n");
    } else {
        printf("Segitiga sembarang\n");
    }

    return 0;
}