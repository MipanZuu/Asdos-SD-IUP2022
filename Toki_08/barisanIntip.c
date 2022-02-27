#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

#define LL long long

/* Struktur Node */

typedef struct stackNode_t {
    LL first;
    LL second;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, LL first, LL second) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->first = first;
        newNode->second = second;

        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    StackNode *temp = stack->_top;
    stack->_top = stack->_top->next;
    free(temp);
    stack->_size--;
}

LL stack_topFirst(Stack *stack) 
{
    return stack->_top->first;
}

LL stack_topSecond(Stack *stack)
{
    return stack->_top->second;
}


unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main(int argc, char const *argv[])
{
    // Buat objek Stack
    Stack myStack;
    stack_init(&myStack);

    stack_push(&myStack, LLONG_MAX, 0);

    LL sum = 0;
    LL n, a;

    scanf("%lld", &n);
    for (LL i = 1; i <= n; i++) {
        scanf("%lld", &a);

        while (!stack_isEmpty(&myStack)) {
            if (a >= stack_topFirst(&myStack)) {
                stack_pop(&myStack);
            } else {
                break;
            }
        }

        sum += i - stack_topSecond(&myStack);
        stack_push(&myStack, a, i);
    }

    printf("%lld\n", sum);

    return 0;
}