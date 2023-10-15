#include <stdio.h>
#include <stdlib.h>
int C[2000000] = {};
int a_Len = 0;

void counting_Sort(int A[], int B[], int max)
{
    for (int i = 0; i < max + 2; ++i) {
        C[i] = 0;
    }
    for (int k = 0; k < a_Len; ++k) {
        ++C[A[k]];
    }
    for (int j = 1; j < max + 2; ++j) {
        C[j] = C[j] + C[j - 1];
    }
    for (int m = a_Len - 1; m >= 0; --m) {
        B[C[A[m]]] = A[m];
        --C[A[m]];
    }
}

int main() {
    int max = 0;
    scanf("%d", &a_Len);
    int *A = malloc(sizeof(int) * a_Len);
    int *B = malloc(sizeof(int) * (a_Len + 1));
    for (int i = 0; i < a_Len; ++i) {
        scanf("%d", &A[i]);
        if(A[i] > max)
        {
            max = A[i];
        }
    }
    counting_Sort(A, B, max);
    printf("[A______________________________]\n");
    for (int i = 0; i < a_Len; ++i) {
        printf("%d | ", A[i]);
    }
    printf("\n[B______________________________]\n");
    for (int i = 1; i < a_Len + 1; ++i) {
        printf("%d | ", B[i]);
    }
    return 0;
}
