#include <stdio.h>
#include <stdlib.h>

#define MAX 200000
#define SENTINEL 200000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];


long long merge(int A[], int  n, int left, int mid, int right)
{
    int i, j, k;
    long long cnt = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    for (i = 0; i < n1; ++i) {
        L[i] = A[left + i];
    }
    for (i = 0; i < n2; ++i) {
        R[i] = A[mid + i];
    }
    L[n1] = R[n2] = SENTINEL;
    i = j = 0;
    for (k = left; k < right; k++) {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            ++i;
        }else
        {
            A[k] = R[j];
            ++j;
            cnt += n1 - i;
        }
    }
    return cnt;
}

long long mergeSort(int A[], int n, int left, int right)
{
    int mid;
    long long v1, v2, v3;

    if(left + 1 < right)
    {
        mid = (left + right) / 2;
        v1 = mergeSort(A, n, left, mid);
        v2 = mergeSort(A, n, mid, right);
        v3 = merge(A, n, left, mid, right);
        return v1 + v2 + v3;
    }else
    {
        return 0;
    }
}

int main() {
    int A[MAX];
    int a_Len = 0;
    scanf("%d", &a_Len);

    for (int i = 0; i < a_Len; ++i) {
        scanf("%d", &A[i]);
    }

    long long ans = mergeSort(A, a_Len, 0, a_Len);
    printf("[ans = %u]", ans);

    return 0;
}
