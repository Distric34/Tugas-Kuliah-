#include <stdio.h>

int main() {
    char kalimat[256];
    int length = 0;
    int i;

    printf("Masukkan kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);

    while (kalimat[length] != '\0' && kalimat[length] != '\n') {
        length++;
    }

    for (i = 0; i < length; i++) {
        if (kalimat[i] >= 'A' && kalimat[i] <= 'Z') {
            kalimat[i] = kalimat[i] + 32;
        }
    }

    printf("Hasil terbalik: ");
    for (i = length - 1; i >= 0; i--) {
        putchar(kalimat[i]);
    }
    printf("\n");

    return 0;
}