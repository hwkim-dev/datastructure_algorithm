#include <stdio.h>
#include <stdlib.h>

#define START_INDEX 1
#define NIL -1

int *H;
int heap_Size;

int get_Parent(int index)
{
    index = index / 2;
    if(index >= 1)
    {
        return H[index];
    }else
    {
        return NIL;
    }
}
int get_Left(int index)
{
    index = index * 2;
    if(index < heap_Size)
    {
        return H[index];
    }else
    {
        return NIL;
    }
}
int get_Right(int index)
{
    index = index * 2 + 1;
    if(index < heap_Size)
    {
        return H[index];
    }else
    {
        return NIL;
    }
}

void print(int index)
{
    printf("node %d: key = %d, parent key = %d, left key = %d, right key = %d, \n"
    , index, H[index], get_Parent(index), get_Left(index), get_Right(index));
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

    for(int i = START_INDEX; i < heap_Size; ++i){
        print(i);
    }

    return 0;
}