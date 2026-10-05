#include <stdio.h>

int main() {
    char nama[50];  
    char jabatan[50];
    float gaji_kotor, pajak, zakat, gaji_bersih;

    printf("Masukkan nama karyawan: ");
    scanf(" %[^\n]s", nama);

    printf("Masukkan jabatan karyawan: ");
    scanf(" %[^\n]s", jabatan);

    printf("Masukkan gaji kotor karyawan: ");
    scanf("%f", &gaji_kotor);

    pajak = gaji_kotor * 0.07;
    zakat = gaji_kotor * 0.025;
    gaji_bersih = gaji_kotor - pajak - zakat;

    printf("\n===== DATA KARYAWAN =====\n");
    printf("Nama: %s\n", nama);
    printf("Jabatan: %s\n", jabatan);
    printf("Gaji Kotor: %.2f\n", gaji_kotor);
    printf("Pajak (7%%): %.2f\n", pajak);
    printf("Zakat (2.5%%): %.2f\n", zakat);
    printf("Gaji Bersih: %.2f\n", gaji_bersih);

    return 0;
}