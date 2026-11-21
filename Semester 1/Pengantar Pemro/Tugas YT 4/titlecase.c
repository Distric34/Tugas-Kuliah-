#include <stdio.h>

int main() {
    char kalimat[256];
    int i = 0;
    int awal_kata = 1; // Flag untuk menandai awal kata (1 = true, 0 = false)

    printf("Masukkan sebuah string: ");
    fgets(kalimat, sizeof(kalimat), stdin);

    while (kalimat[i] != '\0' && kalimat[i] != '\n') {
        char c = kalimat[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            if (awal_kata) {
                if (c >= 'a' && c <= 'z') {
                    kalimat[i] = c - 32;
                }
                awal_kata = 0; 
            } else {
                if (c >= 'A' && c <= 'Z') {
                    kalimat[i] = c + 32;
                }
            }
        } else {
            awal_kata = 1;
        }
        i++;
    }

    printf("Hasil title case: %s", kalimat);

    return 0;
}