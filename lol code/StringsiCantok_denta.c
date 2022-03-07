/*
    StringSiCantok.c
    2022-02-15
    Denta Bramasta
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct stackNode_t {
    char data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, char value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, char value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return '\0';
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}



int main(int argc, char const *argv[])
{
    Stack myStack;
    stack_init(&myStack);
    int i = 0;
    char str[100];
    gets(str);
    stack_push(&myStack, str[strlen(str)-1]);

    while(i < strlen(str))
    {
        char c = str[i];

        if (stack_isEmpty(&myStack) || c != stack_top(&myStack))
        {
            stack_push(&myStack, c);
            stack_pop(&myStack);
        }
        else {
            stack_pop(&myStack);
        }
        
    }

    if (stack_isEmpty(&myStack))
    {
        printf("Yah habis :(\n");
    }
    else {
        while (!stack_isEmpty(&myStack))
        {
            printf("%c", stack_top(&myStack));
            stack_pop(&myStack);
        }
    }
    
    
    // stack_push(&myStack, 'a');
    // stack_push(&myStack, 'b');
    // stack_push(&myStack, 'c');

    // while (!stack_isEmpty(&myStack)) {
    //     printf("%c ", stack_top(&myStack));
    //     stack_pop(&myStack);
    // }
    puts("");
    return 0;
}