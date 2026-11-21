#include <stdio.h>

int main() {
    int tahun, bulan, hari;
    int kabisat;

    printf("Masukkan tahun: ");
    scanf("%d", &tahun);

    printf("Masukkan bulan: ");
    scanf("%d", &bulan);

    if (tahun % 400 == 0) {
        kabisat = 1;
    } else if (tahun % 100 == 0) {
        kabisat = 0;
    } else if (tahun % 4 == 0) {
        kabisat = 1;
    } else {
        kabisat = 0;
    }

    if (kabisat == 1) {
        printf("Tahun %d adalah TAHUN KABISAT\n", tahun);
    } else {
        printf("Tahun %d BUKAN TAHUN KABISAT\n", tahun);
    }

    switch (bulan) {
        case 1:
            hari = 31;
            break;
        case 2:
            if (kabisat == 1) {
                hari = 29;
            } else {
                hari = 28;
            }
            break;
        case 3:
            hari = 31;
            break;
        case 4:
            hari = 30;
            break;
        case 5:
            hari = 31;
            break;
        case 6:
            hari = 30;
            break;
        case 7:
            hari = 31;
            break;
        case 8:
            hari = 31;
            break;
        case 9:
            hari = 30;
            break;
        case 10:
            hari = 31;
            break;
        case 11:
            hari = 30;
            break;
        case 12:
            hari = 31;
            break;
        default:
            printf("Bulan tidak valid!\n");
            return 0;
    }

    printf("Jumlah hari pada bulan ");

    switch (bulan) {
        case 1: printf("JANUARI"); break;
        case 2: printf("FEBRUARI"); break;
        case 3: printf("MARET"); break;
        case 4: printf("APRIL"); break;
        case 5: printf("MEI"); break;
        case 6: printf("JUNI"); break;
        case 7: printf("JULI"); break;
        case 8: printf("AGUSTUS"); break;
        case 9: printf("SEPTEMBER"); break;
        case 10: printf("OKTOBER"); break;
        case 11: printf("NOPEMBER"); break;
        case 12: printf("DESEMBER"); break;
    }

    printf(" tahun %d adalah %d\n", tahun, hari);

    return 0;
}