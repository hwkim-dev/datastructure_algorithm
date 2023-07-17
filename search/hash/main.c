#include <stdio.h>
#include <string.h>

#define M 1046527
#define NIL -1
#define L 14

char H[M][L] = {};

int getChar(char ch)
{
    switch(ch)
    {
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
        default:
            return 0;
    }
}

long long getKey(char str[])
{
    long long sum = 0, p = 1;
    for (int i = 0; i < strlen(str); ++i) {
        sum += p * (getChar(str[i]));
        p *= 5;
    }
    return sum;
}

int h1(int key)
{
    return key % M;
}

int h2(int key)
{
    return 1 + (key % (M-1));
}

int h(int key, int i)
{
    return (h1(key) + i * h2(key)) & M;
}

int insert(char *T, int key)
{
    int i = 0;
    while(1)
    {
        int j = h(key, i);
        if(T[j] == NIL)
        {
            T[j] = key;
            return j;
        }else
        {
            i = i + 1;
        }
    }
}

int search(char *T, int key)
{
    int i = 0;
    while(1)
    {
        int j = h(key, i);
        if(T[j] == key)
        {
            return j;
        }else if(T[j] == NIL || i >= M)
        {
            return NIL;
        }else
        {
            i = i+1;
        }
    }
}

void init()
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < L; ++j) {
                H[i][j] = NIL;
        }
    }
}
int main() {
    init();
    char command[10] = {};
    char value[10] = {};

    int count  = 0;
    while(1)
    {
        scanf("%s %s", command, value);
        switch(command[0])
        {
            case 'i':
                printf("insert >> %d\n", insert(H[0], getKey(value)));
                break;
            case 'f':
                printf("search >> %d\n", search(H[0], getKey(value)));
                break;
        }
        //++count;
    }

    return 0;
}
