#include <stdio.h>

const char* tentukanStatus(int skor);

int main() {
    int skor;
    
    if (scanf("%d", &skor) == 1) {
        printf("Status Lisensi: %s\n", tentukanStatus(skor));
    }
    
    return 0;
}

const char* tentukanStatus(int skor) {
    if (skor < 60) {
        return "Gagal";      
    } else if (skor <= 79) {
        return "Cadangan";   
    } else if (skor <= 94) {
        return "Lulus";      
    } else {
        return "Istimewa";   
    }
}