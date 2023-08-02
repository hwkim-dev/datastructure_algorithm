#include <stdio.h>

#define MAX 100000
int size_Of_M = 0;
int truck_quantity = 0;
long long m[MAX];

int check(long long p)
{
    int i = 0;
    for (int j = 0; j < truck_quantity; ++j) {
        long long s = 0;
        while(s + m[i] <= p)
        {
            s += m[i];
            i++;
            if(i == size_Of_M)
            {
                return size_Of_M;
            }
        }
    }
    return i;
}

int solve()
{
    long long left = 0;
    long long right = 100000 * 10000;
    long long mid;

    while(right - left > 1)
    {
        mid = (left + right) / 2;
        int v = check(mid);
        if(v >= size_Of_M)
        {
            right = mid;
        }else
        {
            left = mid;
        }
    }
    return right;
}

int main() {
    printf("Hello, World!\n");

    printf("input m size : ");
    scanf("%d", &size_Of_M);
    printf("input k : ");
    scanf("%d", &truck_quantity);

    for (int i = 0; i < size_Of_M; ++i) {
        scanf("%d", &m[i]);
    }
    long long ans = solve();
    printf("%d", ans);

    return 0;
}
