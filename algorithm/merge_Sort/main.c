#include <stdio.h>
#include <stdlib.h>
#define INFTY 200000000

int cnt = 0;

void merge(int A[], int left, int mid, int right)
{
    int l_Num = mid - left;
    int r_Num = right - mid;
    int i = 0;
    int j = 0;
    int *L = malloc(sizeof(int) * l_Num);
    int *R = malloc(sizeof(int) * r_Num);
    for (i = 0; i < l_Num; ++i) {
        L[i] = A[left + i];
    }
    for (j = 0; j < r_Num; ++j) {
        R[j] = A[mid + j];
    }
    L[l_Num] = INFTY;
    R[r_Num] = INFTY;
    i = 0;
    j = 0;
    for (int k = left; k < right; ++k) {
        ++cnt;
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            ++i;
        }else
        {
            A[k] = R[j];
            ++j;
        }
    }
}

void merge_Sort(int A[], int left, int right)
{
    if(left + 1 < right)
    {
        int mid = (left + right) / 2;
        merge_Sort(A, left, mid);
        merge_Sort(A,mid, right);
        merge(A, left, mid, right);
    }
}

int main() {

    int n = 0;
    scanf("%d", &n);
    int *S = malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &S[i]);
    }
    merge_Sort(S, 0, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", S[i]);
    }
    printf("\n%d", cnt);
    return 0;
}
