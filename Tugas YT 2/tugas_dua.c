#include <stdio.h>

int main(){
    double total_belanja, diskon = 0, tambahan_potongan = 0, total_pembayaran;

    printf("\n=== Program Hitung Total Pembayaran ===\n");
    printf("Masukkan total belanja: Rp ");
    scanf("%lf", &total_belanja);

    if (total_belanja >= 2000000) {
        diskon = 0.25 * total_belanja;
        tambahan_potongan = 100000;
    } else if (total_belanja >= 1000000) {
        diskon = 0.25 * total_belanja;
    } else if (total_belanja >= 500000) {
        diskon = 0.20 * total_belanja;
    } else if (total_belanja >= 100000) {
        diskon = 0.10 * total_belanja;
    }

    total_pembayaran = total_belanja - diskon - tambahan_potongan;

    printf("----------------------------------------\n");
    printf("Total belanja sebelum didiskon : Rp %.2f\n", total_belanja);
    if (diskon > 0) {
        printf("Diskon yang didapat           : Rp %.2f\n", diskon);
    }
    if (tambahan_potongan > 0) {
        printf("Tambahan potongan             : Rp %.2f\n", tambahan_potongan);
    }
    printf("Total pembayaran setelah diskon: Rp %.2f\n", total_pembayaran);

    return 0;
}