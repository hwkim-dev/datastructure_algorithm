#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODENOTFOUND 2
#define YES 1
#define NO -1
struct Node
{
    int key;
    struct Node *parent, *left, *right;
};

struct Node *root, *NIL;

void insert(int key)
{
    struct Node *prev_Node;
    struct Node *find = root;
    struct Node *new_Node = malloc(sizeof(struct Node));
    new_Node->key = key;
    new_Node->left = new_Node->right = NIL;
    while(find != NIL)
    {
        prev_Node = find;
        if(find->key > key)
        {
            find = find->left;
        }else //if(find.key < key)
        {   
            find = find->right;
        }
    }
    new_Node->parent = prev_Node;
    if(prev_Node == NIL)
    {
        root = new_Node;
        root.parent = NIL;
    }else if(new_Node->key < prev_Node->key)
    {
        prev_Node->left = new_Node;
    }else 
    {
        prev_Node->right = new_Node;
    }
}

void pre_Order(struct Node *n)
{
    if(n == NIL) return ;
    printf("%d ", n->key);
    pre_Order(n->left);
    pre_Order(n->right);
}

void in_Order(struct Node *n)
{
    if(n == NIL) return ;
    in_Order(n->left);
    printf("%d ", n->key);
    in_Order(n->right);
}

Node* find(int search_Key)
{
    struct Node *pointer = root;
    while(pointer != NIL)
    {
        if(pointer->key < search_Key)
        {
            pointer = pointer->right;
        }else if(pointer->key > search_Key)
        {
            pointer = pointer->left;
        }else //pointer->key == search_Key
        {
            break;
        }
    }
    return pointer;
}
Node * tree_Successor(Node )
{

}

int delete(Node *eliminate_Node)
{
    struct Node *prev_Node = eliminate_Node.parent;
    //자식이 한명
    if(eliminate_Node.left == NIL ^ eliminate_Node.right == NIL)
    {
        
    //자식이없음
    }else if(eliminate_Node.left == NIL && eliminate_Node.right == NIL)
    {

    //자식이 두명
    }else
    {

    }
    struct Node *current_Node = eliminate_Node;
    //struct Node *left = NIL;
    //struct Node *right = NIL;
    if(current_Node == root)
    {
        current_Node
    }else
    {
        prev_Node = current_Node.parent;
        prev_Node.
    }
}

//print in-order and print pre-order
void print()
{
    in_Order(root);
    putchar('\n');
    pre_Order(root);
    putchar('\n');
}

int main() {
    int command_Lines = 0;
    char command[10] = {};
    int insert_Value = 0;
    int key = 0;

    scanf("%d", &command_Lines);
    
    for(int i = 0; i < command_Lines; ++i){
        
        scanf("%s", &command);    

        
        if(strcmp(command, "insert") == 0)
        {
            scanf("%d", &insert_Value);
            insert(insert_Value);
        }else if(strcmp(command, "print") == 0)
        {
            print();
        }else if(strcmp(command, "find") == 0)
        {
            scanf("%d", &key);
            if(find(key) == NIL)
            {
                printf("NO\n");
            }else
            {
                printf("YES\n");
            }
        }else if(strcmp(command, "delete") == 0)
        {
            scanf("%d", &key);
            struct Node *eliminate_Node = find(key);
            if(eliminate_Node != NIL)
            {
                delete(eliminate_Node);
                printf("deleted");
            }else
            {
                printf("node not found");
            }
        }else
        {
                printf("wrong command!!!\n");
                --i;
        }
    }
    free(root);

    return 0;
}
