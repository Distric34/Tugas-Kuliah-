#include <stdio.h>

int main() {
    long uang;
    long jumlah;
    int i;

    long pecahan[] = {
        500000, 100000, 50000, 20000,
        10000, 5000, 2000, 1000,
        500, 100, 50, 10, 5, 1
    };

    printf("Jumlah uang: ");
    scanf("%ld", &uang);

    if (uang <= 0) {
        printf("Jumlah uang harus positif!\n");
        return 0;
    }

    printf("\nPecahan  Jumlah\n");

    for (i = 0; i < 14; i++) {
        jumlah = uang / pecahan[i];
        uang = uang % pecahan[i];

        if (pecahan[i] >= 1000) {
            printf("%7ld %7ld\n", pecahan[i], jumlah);
        } else {
            printf("%7ld %7ld\n", pecahan[i], jumlah);
        }
    }

    return 0;
}