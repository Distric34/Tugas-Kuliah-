#include <stdio.h>

int pangkatDua(int x) {
    return x * x;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int daya[100];
    int totalDaya = 0;
    int intiTerkalibrasi = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &daya[i]);
        
        if (daya[i] % 2 == 0) {
            daya[i] = pangkatDua(daya[i]); 
            intiTerkalibrasi++;            
        }
        
        totalDaya += daya[i];
    }

    printf("Total Daya Reaktor: %d\n", totalDaya);
    printf("Inti Terkalibrasi: %d\n", intiTerkalibrasi);

    return 0;
}