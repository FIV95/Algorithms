#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
} LinkedList;

Node *createNode(int data)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Memory Allocation Failed creating struct Node\n");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

LinkedList *createList()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    if (list == NULL)
    {
        printf("Memory Allocation Failed creating struct LinkedList\n");
        return NULL;
    }
    list->head = NULL;
    return list;
}

bool isEmpty(LinkedList *list)
{
    return list->head == NULL;
}

void setHead(LinkedList *list, Node *node)
{
    if (isEmpty(list))
    {
        list->head = node;
        return;
    }
    node->next = list->head;
    list->head = node;
    return;
}

void addToList(LinkedList *list, int value)
{
    Node *newNode = createNode(value);
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed creating Node in addToList Function\n");
        return;
    }
    if (isEmpty(list))
    {
        list->head = newNode;
        return;
    }
    Node *tmpNodeP = list->head;
    while (tmpNodeP->next != NULL)
    {
        tmpNodeP = tmpNodeP->next;
    }
    tmpNodeP->next = newNode;
    return;
}

int *toArray(LinkedList *list, int *size)
{
    Node *runner = list->head;
    if (isEmpty(list))
    {
        return NULL;
    }
    else
    {
        (*size) = 1;
    }
    while (runner)
    {
        runner = runner->next;
        (*size)++;
    }
    int i = 0;
    int *arr = malloc(sizeof(int) * (*size));
    runner = list->head;
    while (runner)
    {
        arr[i] = runner->data;
        printf("%d\n", runner->data);
        runner = runner->next;
        i++;
    }
    return arr;
}

void changeHead(LinkedList *list, Node *node)
{
    if (isEmpty(list))
    {
        list->head = node;
        return;
    }
    // we simply wanna shift the nodes to the right.
    node->next = list->head;
    list->head = node;
    return;
}

void printArray(int *arr, int size)
{
    printf("[");
    for (int i = 0; i < size - 1; i++)
    {
        if (i > 0)
        {
            printf(",");
        }
        printf("%d", arr[i]);
    }
    printf("]\n");
}

LinkedList *fromArrayToList(int *arr, int arrSize)
{
    if (arrSize == 0)
    {
        return NULL;
    }
    // first need to make new list struct
    LinkedList *newList = malloc(sizeof(LinkedList));
    // set index 0 to head
    for (int i = 0; i < arrSize - 1; i++)
    {
        addToList(newList, arr[i]);
    }
    return newList;
}

int main()
{
    LinkedList *listA = createList();
    addToList(listA, 3);
    addToList(listA, 4);
    addToList(listA, 5);
    addToList(listA, 6);
    addToList(listA, 8);
    int size = 0;
    int *arr = toArray(listA, &size);
    printf("%d\n", listA->head->next->data);
    printArray(arr, size);
    free(arr);
    int test[10] = {1,2,3,4,5,6,7,8,9,10};
    LinkedList *listB = fromArrayToList(&test, 10);
    printf("%d\n", listB->head->next->data);
    return 0;
}
