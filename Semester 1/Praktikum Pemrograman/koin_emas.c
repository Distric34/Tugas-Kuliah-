#include <stdio.h>

int main () {
    int N;
    
    scanf("%d", &N);
    int A[N];
    
for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
}
    for (int i = 0; i < N; i++) {
        printf("Kantong ke-%d: %d koin\n", i + 1, A[i]);
    }

    return 0;
}