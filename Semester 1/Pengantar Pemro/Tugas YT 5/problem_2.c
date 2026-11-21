#include <stdio.h>
#include <ctype.h>
#include <string.h>

void enkripsi_baru(char *data, char arah, int pergeseran) {
    pergeseran = pergeseran % 26;

    while (*data != '\0') {
        if (*data == ' ') {
            data++;
            continue;
        }

        if (isupper(*data)) {
            *data = tolower(*data);
        }

        if (*data >= 'a' && *data <= 'z') {
            int pos = *data - 'a';

            if (arah == 'k' || arah == 'K') { 
                pos = (pos + pergeseran) % 26;
            } else if (arah == 'i' || arah == 'I') { 
                pos = (pos - pergeseran) % 26;
                if (pos < 0) {
                    pos += 26;
                }
            }

            *data = 'a' + pos;
        }

        data++;
    }
}

int main() {
    char str[200];
    int pergeseran;
    char arah_input[10];
    char arah;

    printf("Masukkan sebuah string: ");
    scanf(" %[^\n]", str);

    printf("Besar pergeseran karakter: ");
    scanf("%d", &pergeseran);

    printf("Arah pergeseran: ");
    scanf("%s", arah_input);

    if (arah_input[0] == 'k' && arah_input[1] == 'a') {
        arah = 'k';
    } else {
        arah = 'i';
    }

    enkripsi_baru(str, arah, pergeseran);

    printf("Hasil enkripsi: %s\n", str);

    return 0;
}