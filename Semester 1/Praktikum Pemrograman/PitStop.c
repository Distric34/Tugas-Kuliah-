#include <stdio.h>

void cetakPitStop(int nomorMobil, int lap) {
    printf("Pit Stop Mobil: %d\n", nomorMobil);
    printf("Masuk pada Lap: %d\n", lap);
}

int main() {
    int nomorMobil, lap;

    if (scanf("%d %d", &nomorMobil, &lap) == 2) {
        cetakPitStop(nomorMobil, lap);
    }

    return 0;
}