#include <stdio.h>
#include <string.h>

#define MAX 200000
#define INFTY 200000000

int H[MAX];
int heap_Size = 0;

int get_Parent(int index)
{
    return index / 2;
}
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

void heap_Increase_Key(int element)
{
    if(element < H[heap_Size])
    {
        printf("element is too small element will not be inserted\n");
        --heap_Size;
        return ;
    }
    H[heap_Size] = element;

    int index = heap_Size;
    int parent_Index = get_Parent(index);
    while(index > 1 && H[parent_Index] < H[index])
    {
        int temp = H[index];
        H[index] = H[parent_Index];
        H[parent_Index] = temp;
        index = parent_Index;
        parent_Index = get_Parent(index);
    }
}

//insert element on H
void insert(int element)
{
    ++heap_Size;
    H[heap_Size] = -INFTY;
    heap_Increase_Key(element);
}

//delete index which has largest key in H and return keys 
int extract_Max()
{
    if(heap_Size < 1)
    {
        printf("No element exist!");
        return -1;
    }
    int largest = 0;
    largest = H[1];
    H[1] = H[heap_Size];
    --heap_Size;
    max_Heapify(1);

    return largest;
}

int main()
{
    char command[10] = {};
    int element = 0;

    while(1)
    {
        scanf("%s", &command);

        if(strcmp(command,"insert") == 0)
        {
            scanf("%d", &element);
            insert(element);
        }else if(strcmp(command,"extract") == 0)
        {
            printf("%d\n", extract_Max(element));
        }else if(strcmp(command,"end") == 0)
        {
            break;
        }else
        {
            printf("Wrong command!!\n");
        }
    }

    return 0;
}