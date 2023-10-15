#include <stdio.h>
#include <stdlib.h>

#define NIL -1

struct Node
{
    int parent, left, right;
};

int *height, *depth;
struct Node *node;

void init(int node_N)
{
    int id = 0;
    int left = 0;
    int right = 0;

    //input id, left, right
    for (int i = 0; i < node_N; ++i) {
        printf("input id >> ");
        scanf("%d", &id);

        printf("input left >> ");
        scanf("%d", &left);
        if(left != NIL)
        {
            node[left].parent = id;
            node[id].left = left;
        }
        //else node[id].left = NIL

        printf("input right >> ");
        scanf("%d", &right);
        if(right != NIL)
        {
            node[right].parent = id;
            node[id].right = right;
        }
        //else node[id].right = NIL
    }
}

int get_Degree(int node_N)
{
    int degree_Cnt = 0;
    if(node[node_N].left != NIL)
    {
        ++degree_Cnt;
    }
    if(node[node_N].right != NIL)
    {
        ++degree_Cnt;
    }
    return degree_Cnt;
}

void calc_Depth(int node_N, int depth_Cnt)
{
    if(node_N == NIL)
    {
        return ;
    }

    depth[node_N] = depth_Cnt;

    calc_Depth(node[node_N].left, depth_Cnt + 1);
    calc_Depth(node[node_N].right, depth_Cnt + 1);
}

int get_Sibling(int node_N)
{
    if(node[node_N].parent == NIL)
    {
        return NIL;
    }

    if(node[node[node_N].parent].left != node_N && node[node[node_N].parent].left != NIL)
    {
        return node[node[node_N].parent].left;
    }

    if(node[node[node_N].parent].right != node_N && node[node[node_N].parent].right != NIL)
    {
        return node[node[node_N].parent].right;
    }
}
int calc_Height(int node_N)
{
    int h1 = 0, h2 = 0;
    if(node[node_N].right != NIL)
    {
        h1 = calc_Height(node[node_N].right) + 1;
    }
    if(node[node_N].left != NIL)
    {
        h2 = calc_Height(node[node_N].left) + 1;
    }

    return height[node_N] = (h1 >= h2 ? h1 : h2);
}
/*
 * ex) node x: parent = x, sibling = x, degree = x, depth = x, height = x, (root, internal, leaf)
 */
void print(int node_N)
{
    printf("node %d: ", node_N);
    printf("parent = %d, ", node[node_N].parent);
    printf("sibling = %d, ", get_Sibling(node_N));
    printf("degree = %d, ", get_Degree(node_N));
    printf("depth = %d, ", depth[node_N]);
    printf("hieght = %d, ", height[node_N]);
    if(node[node_N].parent == NIL)
    {
        printf("root\n");
    }else if(node[node_N].left == NIL && node[node_N].right == NIL)
    {
        printf("leaf\n");
    }else
    {
        printf("internal\n");
    }
}

int main() {
    int node_Num = 0;
    int root = 0;
    printf("input node Number >> ");
    scanf("%d", &node_Num);
    node = malloc(sizeof(struct Node) * node_Num);
    height = malloc(sizeof(int) * node_Num);
    depth = malloc(sizeof(int) * node_Num);
    for (int i = 0; i < node_Num; ++i) {
        node[i].parent = node[i].left = node[i].right = NIL;
    }

    init(node_Num);

    calc_Depth(root, 0);

    calc_Height(root);

    for (int i = 0; i < node_Num; ++i) {
        print(i);
    }

    free(node);

    return 0;
}