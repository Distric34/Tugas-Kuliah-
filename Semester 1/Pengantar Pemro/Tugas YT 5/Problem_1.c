#include <stdio.h>

char ganti_karakter(char *data, char find, char replace) {
    char count = 0;
    
    while (*data != '\0') {
        if (*data == find) {
            *data = replace;
            count++;
        }
        data++;
    }
    
    return count;
}

int main() {
    char str[100];
    char find_char, replace_char;

    printf("Masukkan sebuah string: ");
    scanf("%99s", str);

    printf("Karakter yang dicari: ");
    scanf(" %c", &find_char);

    printf("Karakter pengganti: ");
    scanf(" %c", &replace_char);

    ganti_karakter(str, find_char, replace_char);

    printf("String hasil subsitutisi: %s\n", str);

    return 0;
}