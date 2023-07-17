#include <stdio.h>
#include <stdlib.h>

int linear_Search(int *A, int n, int key)
{
    int i = 0;
    A[n] = key;
    while(A[i] != key) ++i;
    return i != n;
}

int main() {
    int sequence_S_Size = 0;
    printf("enter sequence_S size >> ");
    scanf("%d", &sequence_S_Size);
    int *sequence_S = malloc(sizeof(sizeof(int) * sequence_S_Size));

    for (int i = 0; i < sequence_S_Size; ++i) {
        scanf("%d", &sequence_S[i]);
    }

    int sequence_X_Size = 0;
    printf("enter sequence_X size >> ");
    scanf("%d", &sequence_X_Size);

    int key = 0;
    int sum = 0;
    for (int i = 0; i < sequence_X_Size; ++i) {
        scanf("%d", &key);
        if(linear_Search(sequence_S, sequence_S_Size, key)) ++sum;
    }

    printf("%d", sum);

}
