#include <stdio.h>
#include <stdlib.h>

#define NIL -1

struct Node
{
    int parent, left, right;
};

struct Node *node;

void pre_Order(int node_N)
{
    if(node_N == NIL)
    {
        return ;
    }
    printf("%d ", node_N);
    pre_Order(node[node_N].left);
    pre_Order(node[node_N].right);
}

void in_Order(int node_N)
{
    if(node_N == NIL)
    {
        return ;
    }
    in_Order(node[node_N].left);
    printf("%d ", node_N);
    in_Order(node[node_N].right);
}

void post_Order(int node_N)
{
    if(node_N == NIL)
    {
        return ;
    }
    post_Order(node[node_N].left);
    post_Order(node[node_N].right);
    printf("%d ", node_N);
}

int main() {
    int node_Num = 0, id = 0, left = 0, right = 0, root = 0;
    printf("node num >> ");
    scanf("%d", &node_Num);
    node = malloc(sizeof(struct Node) * node_Num);
    for (int i = 0; i < node_Num; ++i) {
        node[i].parent = NIL;
    }

    for (int i = 0; i < node_Num; ++i) {
        printf("id left right > ");
        scanf("%d %d %d", &id, &left, &right);

        node[id].left = left;
        node[id].right = right;
        if(left != NIL)
        {
            node[left].parent = id;
        }

        if(right != NIL)
        {
            node[right].parent = id;
        }
    }
    for (int i = 0; i < node_Num; ++i) {
        if(node[i].parent == NIL)
            root = i;
    }
    printf("Preorder\n");
    pre_Order(root);
    printf("\n");
    printf("Inorder\n");
    in_Order(root);
    printf("\n");
    printf("Postorder\n");
    post_Order(root);
    printf("\n");

    free(node);
    return 0;
}
