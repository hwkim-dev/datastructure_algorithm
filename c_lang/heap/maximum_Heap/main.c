#include <stdio.h>
#include <stdlib.h>

#define START_INDEX 1

int *H;
int heap_Size;

int get_Left_Index(int index)
{
    return index * 2;
}
int get_Right_Index(int index)
{
    return index * 2 + 1;
}

void max_Heapify(int index)
{
    int left = get_Left_Index(index);
    int right = get_Right_Index(index);
    int largest = 0;

    if(left < heap_Size && H[left] > H[index])
    {
        largest = left;
    }else
    {
        largest = index;
    }
    if(right < heap_Size && H[right] > H[largest])
    {
        largest = right;
    }

    if(largest != index)
    {
        int temp = H[index];
        H[index] = H[largest];
        H[largest] = temp;
        max_Heapify(largest);
    }
}

void build_Max_Heap()
{
    for(int i = heap_Size / 2; i >= 1; --i){
        max_Heapify(i);
    }
}

int main()
{
    heap_Size = 0;
    scanf("%d", &heap_Size);
    ++heap_Size;

    H = malloc(sizeof(int) * heap_Size);
    for(int i = START_INDEX; i < heap_Size; ++i){
        scanf("%d", &H[i]);
    }

    build_Max_Heap();
    
    for(int i = START_INDEX; i < heap_Size; ++i){
        printf("%d ", H[i]);
    }
    free(H);
    return 0;
}