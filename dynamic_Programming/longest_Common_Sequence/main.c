#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_LEN 1000

char *X;
char *Y;
int data_Len;

int get_Len(char *arr)
{
    int index = 0;
    while(index < INPUT_LEN)
    {
        printf("%c", X[index]);
        ++index;
    }
    /*
    while(arr[index] != '\0')
    {
        ++index;
    }*/
    ++index;
    return index;
}

int get_Max(int left, int right)
{
    return (left > right) ? left : right;
}

void make_Space_Front_XY(int x_Size, int y_Size)
{
    for(int i = x_Size; i > 0; --i){
        X[i] = X[i-1];
    }

    for(int i = y_Size; i > 0; --i){
        Y[i] = Y[i-1];
    }
}

int lcs(int x_Size, int y_Size)
{
    int max_Len = 0;
    printf("1");
    int C[INPUT_LEN + 1][INPUT_LEN + 1];
    printf("2");
    ++x_Size; ++y_Size;
    printf("3");
    make_Space_Front_XY(x_Size, y_Size);
    printf("4");
    X[0] = ' '; 
    Y[0] = ' ';

    for(int i = 0; i < x_Size; ++i){
        C[i][0] =0;
    }
    for(int i = 0; i < y_Size; ++i){
        C[0][i] = 0;
    }

    for(int i = 1; i < x_Size; ++i){
        for(int j = 1; j < y_Size; ++j){
            if(X[i] == Y[j])
            {
                C[i][j] = C[i-1][j-1] + 1;
            }else
            {
                C[i][j]= get_Max(C[i-1][j], C[i][j-1]);
            }
            max_Len = get_Max(max_Len, C[i][j]);
        }
    }
    return max_Len;
}

int main()
{
    data_Len = 0;
    scanf("%d", &data_Len);
    X = malloc(sizeof(char) * INPUT_LEN);
    Y = malloc(sizeof(char) * INPUT_LEN);

    for(int i = 0; i < data_Len; ++i){
        scanf("%s", &X);
        scanf("%s", &Y);
        printf("%d_%d", get_Len(X), get_Len(Y));
        printf("%d\n", lcs(get_Len(X), get_Len(Y)));
    }

    free(X);
    free(Y);
    return 0;
}