#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STR_SIZE 1024

char* stristr( const char* str1, const char* str2 )
{
    const char* p1 = str1 ;
    const char* p2 = str2 ;
    const char* r = *p2 == 0 ? str1 : 0 ;

    while( *p1 != 0 && *p2 != 0 )
    {
        if( tolower( (unsigned char)*p1 ) == tolower( (unsigned char)*p2 ) )
        {
            if( r == 0 )
            {
                r = p1 ;
            }

            p2++ ;
        }
        else
        {
            p2 = str2 ;
            if( r != 0 )
            {
                p1 = r + 1 ;
            }

            if( tolower( (unsigned char)*p1 ) == tolower( (unsigned char)*p2 ) )
            {
                r = p1 ;
                p2++ ;
            }
            else
            {
                r = 0 ;
            }
        }

        p1++ ;
    }

    return *p2 == 0 ? (char*)r : 0 ;
}

typedef struct book_t
{
    char title[STR_SIZE];
    double price;
} Book;

Book *book_create(char *title, double price)
{
    Book *newBook = (Book *)malloc(sizeof(Book));

    if (newBook)
    {
        newBook->price = price;
        strcpy(newBook->title, title);
        return newBook;
    }
    return NULL;
}

void book_read(Book *book)
{
    printf("Title\t\t: %s\n", book->title);
    printf("Rent Price\t: $%.2lf/day\n", book->price);
}

/* Struktur Node */
typedef struct snode_t
{
    Book *book;
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */
typedef struct slist_t
{
    unsigned _size;
    SListNode *_head;
} SinglyList;

void slist_init(SinglyList *list)
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list)
{
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, Book *book)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        list->_size++;
        newNode->book = book;

        if (slist_isEmpty(list))
            newNode->next = NULL;
        else
            newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp->book);
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, Book *book)
{
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        list->_size++;
        newNode->book = book;
        newNode->next = NULL;

        if (slist_isEmpty(list))
            list->_head = newNode;
        else
        {
            SListNode *temp = list->_head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void slist_popBack(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL)
        {
            free(currNode->book);
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL)
        {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode->book);
        free(nextNode);
        list->_size--;
    }
}

void slist_insertAt(SinglyList *list, int index, Book *book)
{
    /* Kasus apabila posisinya melebihi batas */
    if (slist_isEmpty(list) || index >= list->_size)
    {
        slist_pushBack(list, book);
        return;
    }
    else if (index == 0 || index < 0)
    {
        slist_pushFront(list, book);
        return;
    }

    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode)
    {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index - 1)
        {
            temp = temp->next;
            _i++;
        }
        newNode->book = book;
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

Book* slist_findByTitle(SinglyList *list, char *title)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (stristr(temp->book->title, title)) {
            return temp->book;
        }
        while (temp != NULL && !stristr(temp->book->title, title)) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return NULL;
        return temp->book;
    }
}

Book* slist_front(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        return list->_head->book;
    }
    return NULL;
}

Book* slist_back(SinglyList *list)
{
    if (!slist_isEmpty(list))
    {
        SListNode *temp = list->_head;
        while (temp->next != NULL)
            temp = temp->next;
        return temp->book;
    }
    return NULL;
}

Book* slist_getAt(SinglyList *list, int index)
{
    if (!slist_isEmpty(list))
    {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index)
        {
            temp = temp->next;
            _i++;
        }
        return temp->book;
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    SinglyList myList;
    slist_init(&myList);

    char command[STR_SIZE] = "";
    const char separator[2] = ",";

    while (scanf ("%[^\n]%*c", command)!=EOF)
    {
        char *cmd, *title, *price;

        cmd = strtok(command, separator);
        title = strtok(NULL, separator);
        price = strtok(NULL, separator);

        int index = atoi(cmd);

        if (cmd == NULL && title == NULL && price == NULL) {
            slist_popFront(&myList);
        } else if (command[0] == ',') {
            Book *book = slist_findByTitle(&myList, cmd);
            if (book) {
                book_read(book);
                continue;
            }
            printf("No book with that title was found.\n");
        } else if (index == -1) {
            slist_popBack(&myList);
        } else if (title == NULL && price == NULL) {
            Book *book = slist_getAt(&myList, index);
            if (book) {
                book_read(book);
                continue;
            }
            printf("Failed to retrieve book.\n");
        } else {
            Book *book = book_create(title, atof(price));
            slist_insertAt(&myList, index, book);
        }
    }

    printf("Bepi has %d book(s).\n", myList._size);

    return 0;
}