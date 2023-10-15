#include <stdio.h>

#define ARRAY_SIZE_MAX 100

int cnt = 0;
void print_A(int m, int A[], int size_A, int g);

void insertionSort(int A[],int n, int g)
{
    int tmp = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        tmp = A[i];
        j = i - g;
        while(j >= 0 && A[j] > tmp)
        {
            A[j + g] = A[j];
            j = j -g;
            ++cnt;
        }
        A[j+g] = tmp;
    }
}

void shellSort(int A[], int n)
{
    int m = 1;
    int G[ARRAY_SIZE_MAX] = {};

    for (int h = 1; h < n ; ++h) {
        G[h] = m;
        m = m*3 + 1;

    }

    for (int i = n- 1; i > 0; --i) {
        insertionSort(A, n, G[i]);
        print_A(m, A, n, G[i]);
    }

}

void print_A(int m, int A[], int size_AG, int g)
{
    printf("------------------\n");
    printf("count : %d\n", cnt);
    printf("sorted using G: %d\n", g);
    printf("[index sorted]\n");
    for (int i = 0; i < size_AG; ++i) {
        printf("%d ", A[i]);
    }
    putchar('\n');
}

int main() {
    int n = 0;
    int array[ARRAY_SIZE_MAX] = {};
    printf("input N : ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        printf("input index >> ");
        scanf("%d", &array[i]);
    }

    shellSort(array, n);

    return 0;
}
