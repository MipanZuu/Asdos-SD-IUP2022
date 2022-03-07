#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, int value);
void queue_pop(Queue *queue);
int  queue_front(Queue *queue);

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
    //printf ("a");
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

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
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        newNode->data = value;
        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
	//printf("a");
    if (!stack_isEmpty(stack)) {
    	
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
    //printf("a");
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

void printq (Queue *queue)
{
	QueueNode *temp = queue->_front;
    while (temp->next!=NULL)
    {
    	printf("%d ",temp->data);
    	temp=temp->next;
	}
	if (temp->next==NULL)
	{
		printf("%d ",temp->data);
	}
}

void prints (Stack *stack)
{
	if(!stack_isEmpty(stack))
	{
		StackNode *temp = stack->_top;
	    while (temp->next!=NULL)
	    {
	    	printf("%d ",temp->data);
	    	temp=temp->next;
		}
		if (temp->next==NULL)
		{
			printf("%d ",temp->data);
		}
	}
}

void find (Stack *stack,Queue *queue,int *k)
{
	//printf("FIND\n");
	if (stack_isEmpty(stack))
	{
	//	printf("CUK\n");
		return;
	}
	//printf("K = %d stack top = %d \n",*k,stack->_top->data);
    if (stack->_top!=NULL && stack->_top->data == *k)
    {
    	while (stack->_top!=NULL && stack->_top->data == *k)
    	{
//    		printf ("A");
    		if (stack_isEmpty(stack))
			{
				printf("CUK\n");
				return;
			}
    		queue_push(queue,*k);
//    		printf ("A");
   			stack_pop(stack);	
   			//prints (stack);
//   			printf ("A");
   			*k=*k+1;
//   			printf ("A");	
		}
	}
}

void leak (Queue *queue)
{
	while (!queue_isEmpty(queue))
	{
		queue_pop(queue);
	}	
}

void sleak (Stack *stack)
{
	while (!stack_isEmpty(stack))
	{
		stack_pop(stack);
	}	
}

int main ()
{
    Queue street;
    Stack side;
    queue_init (&street);
    stack_init (&side);
	int cars,order;
    while (1)
	{
		scanf("%d",&cars);
		if (cars==0)
		{
			return 0;
		}
		int k=1;
	    for (int i=0;i<cars;i++)
	    {
	        scanf("%d",&order);
	      //  printf ("a");
	        if (order==k)
	        {
	          // printf ("a");
	           queue_push(&street,order);
	           k++; 
	           //printf("\n");
	           //printq (&street);
	           //printf ("\nK RIGHT NOW = %d\n",k);
	        }
	        else
	        {
	            stack_push(&side,order);
	            //printf("\n");
	            //prints (&side);
	        }
	        find(&side,&street,&k);
	    }
	    //printf ("b");
	    //printq (&street);
	    //printf ("B");
	   	if (stack_isEmpty(&side))
	    {
	        printf("yes\n");
	    }
	    else 
	    {
	        printf("no\n");
		}
		leak(&street);
		sleak(&side);
	}
}