#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100


int top = 1;
char stack[STACK_SIZE] = {};

void initialize()
{
    top = 0;
}

int isEmpty(){
    return top == 0;
}
void increase_Top()
{
    if(top + 1 >= STACK_SIZE)
    {
        printf("overflow!!");
        exit(1);
    }else{
        ++top;
    }
}
int decrease_Top()
{
    if(top -1 <= 0)
    {
        printf("underflow!!");
        exit(1);
    }else{
        --top;
    }
}
int isFull()
{
    return top >= STACK_SIZE - 1;
}

int push(char c)
{
    //overflow or no elements
    if(isFull())
    {
        printf("!!!!!stack is full");
        exit(1);
    }else{
        stack[top] = c;
        increase_Top();
    }
}

int pop()
{
    //underflow or no elements
    if(isEmpty())
    {
        printf("!!!!!stack is empty");
        exit(1);
    }else{
        decrease_Top();
        return stack[top + 1];
    }
}
int main() {

    printf("___calculate!___<press q to quit>\n");
    printf("ex>>>>>>>>>>>>>> 1 2 + -> 1 + 2\n");

    int pop_1 = 0;
    int pop_2 = 0;
    int  i = 1;
    char input = 0;
    while((input = getchar()) != 'q')
    {
//    number must be larger or equal than 2 & smaller or equal than 100
        if(input > 100 || input < 2)
        {
            printf("[error!] number must be larger or equal than 2 & smaller or equal than 100!!!");
        }else {

            push(input);

            switch (input) {
                case '+' :
                    printf("+");
                    pop_1 = pop();
                    pop_2 = pop();
                    push(pop_1 + pop_2);
                    printf("add : %d\n", pop_1 + pop_2);
                    break;
                case '-' :
                    pop_1 = pop();
                    pop_2 = pop();
                    push(pop_1 - pop_2);
                    printf("sub : %d\n", pop_1 - pop_2);
                    break;
                case '*' :
                    pop_1 = pop();
                    pop_2 = pop();
                    push(pop_1 * pop_2);
                    printf("multi : %d\n", pop_1 * pop_2);
                    break;
                default :
                    push(input);
                    break;
            }
        }
    }

    printf("%d\n", pop);
    return 0;
}
