#include <stdio.h>
#include <stdlib.h>
#define NOT_FOUND -1
#define EXIST 1

int size_S = 0;
int size_T = 0;

int binarySearch(int *array, int key)
{
    int left = 0;
    int right = size_S;
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(array[mid] == key)
        {
            return EXIST;
        }else if(array[mid] > key)
        {
            right = mid;
        }else //array[mid] < key
        {
            left = mid + 1;
        }
    }
    return NOT_FOUND;
}

int main() {
    //init array_S
    printf("enter S size_S >> ");
    scanf("%d", &size_S);
    int *array_S = malloc(sizeof(sizeof(int) * size_S));
    for (int i = 0; i < size_S; ++i) {
        scanf("%d", &array_S[i]);
    }

    //init array_T
    printf("enter T size_T >> ");
    scanf("%d", &size_T);
    int *array_T = malloc(sizeof(sizeof(int) * size_T));
    for (int i = 0; i < size_T; ++i) {
        scanf("%d", &array_T[i]);
    }

    int sum = 0;
    for (int i = 0; i < size_T; ++i) {
        if(binarySearch(array_S, array_T[i])) ++ sum;
    }
    printf("%d", sum);
    return 0;
}
