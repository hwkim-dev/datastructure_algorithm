#include <stdio.h>
#include <stdlib.h>

#define INSERT 0
#define DELETE_F 1
#define DELETE_L 2
#define DELETE_K 3
#define ERROR 4
#define PRINT 5
#define SEARCH 6


struct Node{
    int key;
    struct Node *prev;
    struct Node *next;
} node;

struct Node *nil;

struct Node* listsearch(int key)
{
    struct Node *cur = nil->next;
    while(cur != nil && cur->key != key)
    {
        cur = cur->next;
    }
    return cur;
}
void init()
{
    nil = malloc(sizeof(node));
    nil->next = nil;
    nil->prev = nil;
}

void printlist()
{
    struct Node *cur = nil->next;
    int isf = 0;
    while(1)
    {
        if(cur == nil)break;
        if(isf++ > 0) printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
    }
    printf("\n");
}


void insert(int key)
{
    struct Node *x = malloc(sizeof(node));
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}


void delete(struct Node *x)
{
    if(x == nil) return;
    x->prev->next = x->next;
    x->next->prev = x->prev;
    free(x);
}

void deleteFirst()
{
    delete(nil->next);
}

void deleteLast()
{
    delete(nil->prev);
}
void deleteKey(int key)
{
    delete(listsearch(key));
}

int command(char *cmd_Input)
{
    int index = 0;
    int cmd_correct = 0;
    char commands[6][10] = {"insert" , "deletef", "deletel", "deletek", "error","print", "search"};
    int i = 0;
    for (i = 0; i < 6; ++i) {
        index = 0;
        while(commands[i][index] != '\0')
        {
            if(cmd_Input[index] == commands[i][index]) {
                cmd_correct = 1;
            }else{
                cmd_correct = 2;
            }
            ++index;
        }
        if(cmd_correct == 1)
        {
            break;
        }
    }
    //To check if command is longer than original command
    //ex> insert + character => insesto, insertp... etc
    if(cmd_Input[index] != '\0')
    {
        return ERROR;
    }

    if(cmd_correct == 1)
    {
        return i;
    }


}
int main() {


    int x;
    char cmd_Input[10] = {};
    init();
    printf("Command [insert | delete | q 1 to exit]\n");
    scanf("%s", &cmd_Input);

    while(cmd_Input[0] != 'q')
    {
        switch (command(cmd_Input)) {
            case INSERT :
                printf("insert value >> ");
                scanf("%d", &x);
                insert(x);
                break;
            case DELETE_F :
                deleteFirst();
                break;
            case DELETE_L:
                deleteLast();
                break;
            case DELETE_K :
                printf("delete value >> ");
                scanf("%d", &x);
                deleteKey(x);
                break;
            case ERROR :
                printf("wrong command!!!\n");
                break;
            case PRINT :
                printlist();
                break;
            case SEARCH :
                printf("search value >> ");
                scanf("%d", &x);
                listsearch(x);
                break;
            default :
                printf("ERROR!!!");
                break;
        }
        for (int i = 0; i < 10; ++i) {
            cmd_Input[i] = 0;
        }
        scanf("%s", &cmd_Input);
    }

    return 0;
}
