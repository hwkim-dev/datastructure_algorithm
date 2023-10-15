#include <stdio.h>
#include <stdlib.h>

#define NIL -1

struct Node
{
    int parent;
    int left;
    int right;
};

struct Node *node;
int *depth;

void init(int n)
{
    node = malloc(sizeof(struct Node) * n);
    depth = malloc(sizeof(int) * n);
}

void print(int n)
{
    printf("node %d: ", n);
    printf("parent = %d, ", node[n].parent);
    printf("depth = %d, ", depth[n]);

    if(node[n].parent == NIL)
    {
        printf("root, ");
    }else if(node[n].left == NIL)
    {
        printf("leaf, ");
    }else
    {
        printf("internal node, ");
    }

    int i, children;
    printf("[");
    for (i = 0, children = node[n].left; children != NIL; ++i, children = node[children].right) {
        if(i > 0)
        {
            printf(", ");
        }
        printf("%d", children);
    }
    printf("]\n");
}

void calc_Depth(int n)
{
    int cnt;
    for (int i = 0; i < n; ++i) {
        cnt = 0;
        struct Node temp = node[i];
        while(temp.parent != NIL)
        {
            temp = node[temp.parent];
            ++cnt;
        }
        depth[i] = cnt;
    }
}

int main() {
    int n = 0;
    printf("input node count >> ");
    scanf("%d", &n);
    init(n);
    for (int i = 0; i < n; ++i) {
        node[i].left = node[i].right = node[i].parent = NIL;
    }
    int id = 0;
    int degree = 0;
    int child_Node_N = 0;
    int prev_Node = 0;
    for (int i = 0; i < n; ++i) {
        printf("input id >> ");
        scanf("%d", &id);

        printf("input degree >> ");
        scanf("%d", &degree);
        for (int j = 0; j < degree; ++j) {
            printf("input child node num >> ");
            scanf("%d", &child_Node_N);
            if(j == 0)
            {
                node[id].left = child_Node_N;
            }else
            {
                node[prev_Node].right = child_Node_N;
            }
            prev_Node = child_Node_N;
            node[child_Node_N].parent = id;
        }

    }
    calc_Depth(n);
    for (int i = 0; i < n; ++i) {
        print(i);
    }
    return 0;
}