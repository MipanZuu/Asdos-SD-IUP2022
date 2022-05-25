#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queueNode_t {
    char cookie[101];
    struct queueNode_t *next;
} QueueNode;

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

void init(Queue *queue) {
    queue->_front = NULL;
    queue->_rear = NULL;
    queue->_size = 0;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, char cookie[101]) {
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        strcpy(newNode->cookie, cookie);
        newNode->next = NULL;
      
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue) {
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;

        if (strcmp(temp->cookie, "Cookies") == 0)
            printf("I'm Sorry Kid\n");
        
        queue->_front = queue->_front->next;
        free(temp);
      
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
} 

void check(Queue *queue) {
    int z = queue->_size, y = 0;
    QueueNode *temp = queue->_front;
    for (int i = 0; i < z; i++) {
        if (strcmp(temp->cookie, "Cookies") == 0) {
            y++;
            temp = temp->next;
        } else {
            temp = temp->next;
        }
    }
    
    if (y >= 5) {
        printf("This is the way\n");
    } else {
        printf("I can bring you in warm, or I can bring you in cold\n");
    }
    
}

int main() {
    Queue list;
    init(&list);

    int n;
    scanf("%d", &n);
    getchar();
    
    for (int i = 0; i < n; i++) {
        char word[101];
        scanf("%[^\n]s", word);
        getchar();
        queue_push(&list, word);
    }

    int m;
    scanf("%d", &m);
    getchar();

    for (int i = 0; i < m; i++) {
        char command[101];
        scanf("%[^\n]s", command);
        getchar();

        if (strcmp(command, "Out") == 0) {
            queue_pop(&list);
        } else {
            check(&list);
        }
    }
}