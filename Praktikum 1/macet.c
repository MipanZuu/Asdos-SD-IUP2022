#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct stackNode_t {
    int data;
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
void stack_push(Stack *stack, int value);
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

void stack_push(Stack *stack, int value)
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
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main(int argc, char const *argv[])
{
    
    Stack myStack;
    stack_init(&myStack);
     while (1)
        {
        int a, arr[1001];
        
        scanf("%d", &a);
        
        if (a==0) {
         return 0;
     }
        for (int n = 1; n <= a; n++) {
            scanf("%d", &arr[n]);
        }
        int counter = 1;
        bool tr = true;

        for (int n = 1; n <= a; n++) {
            if (arr[n] == counter) {
                counter++;
                } //if array is equal to counter so counter increment
            else {
                while (!stack_isEmpty(&myStack) && stack_top(&myStack) == counter) {
                        stack_pop(&myStack);
                        counter++;
                    } //car top is equal to counter so car pop
                while (!stack_isEmpty(&myStack) && stack_top(&myStack) < arr[n]) {
                        tr = false;
                        break;
                }// car top is not equal to the real track (arr[n]) so "false" then break to the output
                stack_push(&myStack, arr[n]);
            } // end of else and push the arr[n]
            
        }

        if (tr) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
        }
    return 0;
}
