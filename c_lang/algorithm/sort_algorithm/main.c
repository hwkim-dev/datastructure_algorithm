#include<stdio.h>

void trace(int A[], int N)
{
    int i;
    for (i = 0; i < N; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int N){

    int v, j;
    for (int i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v)
        {
            A[i] = A[j];
            --j;
        }
        A[j+1] = v;
    }
}
void bubbleSort(int A[], int N) {
    int i, j, v, cnt;
    for (cnt = 0; cnt < N - 1; ++cnt) {
        for (j = N - 1; j > cnt; --j) {
            i = j - 1;
            if (A[i] > A[j]) {
                v = A[i];
                A[i] = A[j];
                A[j] = v;
            }
        }
    }
}
void selectionSort(int array[], int N)
{
    int min, tmp;
    for (int k = 0; k < N; ++k)
    {
        min = k;
        for (int l = k + 1; l < N; ++l)
        {
            if(array[min] > array[l])
            {
                min = l;
            }
        }
        tmp = array[k];
        array[k] = array[min];
        array[min] = tmp;
    }
}

int main()
{
    int N, i;

    int array[100];

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    trace(array, N);
    //insertionSort(array, N);
    //bubbleSort(array, N);
    //selectionSort(array, N);
    trace(array, N);
}