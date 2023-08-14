#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO -1
#define YES 1
#define NODENOTFOUND 2
#define ERROR 3

struct Node
{
    int key;
    struct Node *parent, *left, *right;
};

struct Node *root, *NIL;

void insert(int key)
{
    struct Node *prev_Node = NIL;
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
        }else //if(find->key < key)
        {   
            find = find->right;
        }
    }
    new_Node->parent = prev_Node;
    if(prev_Node == NIL)
    {
        root = new_Node;
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

struct Node * find(int search_Key)
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
struct Node * get_Minimum(struct Node * current)
{
    while(current->left != NIL)
    {
        current = current->left;
    }
    return current;
}

void delete(struct Node *eliminate_Node)
{
    struct Node *prev_Node = eliminate_Node->parent;
    struct Node *left_Child_Node = eliminate_Node->left;
    struct Node *right_Child_Node = eliminate_Node->right;

    //eliminate_Node has one child
    if(left_Child_Node == NIL ^ right_Child_Node == NIL)
    {
        if(prev_Node->left == eliminate_Node)
        {
            prev_Node->left = (left_Child_Node == NIL) ? right_Child_Node : left_Child_Node;
            prev_Node->left->parent = prev_Node;
        }else //prev_Node->right == eliminate_Node
        {
            prev_Node->right = (left_Child_Node == NIL) ? right_Child_Node : left_Child_Node;
            prev_Node->right->parent = prev_Node;
        }
        free(eliminate_Node);

    //eliminate_Node has no child
    }else if(eliminate_Node->left == NIL && eliminate_Node->right == NIL)
    {
        if(prev_Node->left == eliminate_Node)
        {
            prev_Node->left = NIL;
        }else //prev_Node->right == eliminate_Node
        {
            prev_Node->right = NIL;
        }
        free(eliminate_Node);
    //eliminate_Node has two child
    }else
    {
        struct Node *minimum = get_Minimum(eliminate_Node->right);
        eliminate_Node->key = minimum->key;
        if(minimum->parent == root && minimum->right == NIL)
        {
            root->right = NIL;
        }else if(minimum->parent == root && minimum->right != NIL)
        {   
            root->right = minimum->right;
            minimum->right->parent = root;
        }else if(minimum->right != NIL)
        {
            minimum->parent->left = minimum->right;
            minimum->right->parent = minimum->parent;
        }else
        {
            print("Error!");
        }
        free(minimum);
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
                printf("deleted\n");
            }else
            {
                printf("node not found\n");
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