#include <stdio.h>
#include <stdlib.h>

int partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if(A[j] <= x)
        {
            ++i;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    ++i;
    int temp = A[i];
    A[i] = A[r];
    A[r] = temp;

    return i;
}

int main() {
    int a_Len = 0;
    scanf("%d*", &a_Len);
    int *A = malloc(sizeof(int) * a_Len);
    for (int k = 0; k < a_Len; ++k) {
        scanf("%d*", &A[k]);
    }
    int q = partition(A, 0, a_Len - 1);

    for (int i = 0; i < q; ++i) {
        printf("%d ", A[i]);
    }
    printf("[%d] ", A[q]);
    for (int j = q+1; j < a_Len; ++j) {
        printf("%d ", A[j]);
    }
    return 0;
}
