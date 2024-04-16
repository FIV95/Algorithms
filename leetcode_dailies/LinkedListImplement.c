#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// STRUCTS
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
} LinkedList;

// FUNCTIONS
Node *createNode(int data);
LinkedList *createList();
bool isEmpty(LinkedList *list);
void addToListAtFront(LinkedList *list, int value);
void addToListAtBack(LinkedList *list, int value);
void deleteValue(LinkedList *list, int valueToBeDeleted);
bool containsValue(LinkedList *list, int value);
int *toArray(LinkedList *list, int *size);
void printArray(int *arr, int size);
LinkedList *fromArrayToList(int *arr, int arrSize);

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

void addToListAtFront(LinkedList *list, int value)
{
    Node *newNode = createNode(value);
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed creating Node in addtoListAtFront function\n");
        return;
    }
    if (isEmpty(list))
    {
        list->head = newNode;
        return;
    }
    newNode->next = list->head;
    list->head = newNode;
    return;
}

void addToListAtBack(LinkedList *list, int value)
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
    *size = 0;
    if (isEmpty(list))
    {
        return NULL;
    }
    while (runner)
    {
        runner = runner->next;
        (*size)++;
    }
    int *arr = malloc(sizeof(int) * (*size));
    runner = list->head;
    for (int i = 0; i < *size; i++)
    {
        arr[i] = runner->data;
        runner = runner->next;
    }
    return arr;
}

void printArray(int *arr, int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
            printf(",");
        }
        printf("%d", arr[i]);
    }
    printf("]\n");
}

void deleteValue(LinkedList *list, int valueToBeDeleted)
{
    Node *runner = malloc(sizeof(Node *));
    runner = list->head;

    if (runner->data == valueToBeDeleted)
    {
        list->head = list->head->next;
        free(runner);
        return;
    }
    // 0-0-0-0

    while (runner->next != NULL)
    {
        if (runner->next->data == valueToBeDeleted)
        {
            Node *previous = runner->next;
            runner->next = runner->next->next;
            free(previous);
            return;
        }
        runner = runner->next;
    }
    printf("Requested Value not found!\n");
    return;
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
    for (int i = 0; i < arrSize; i++)
    {
        addToListAtBack(newList, arr[i]);
    }
    return newList;
}

bool containsValue(LinkedList *list, int value)
{
    Node *runner = malloc(sizeof(Node));

    runner = list->head;

    while (runner)
    {
        if (runner->data == value)
        {
            return true;
        }
        runner = runner->next;
    }
    return false;
}

int main()
{
    LinkedList *listA = createList();
    addToListAtBack(listA, 3);
    addToListAtBack(listA, 4);
    addToListAtBack(listA, 5);
    addToListAtBack(listA, 6);
    addToListAtBack(listA, 8);
    int size = 0;
    int *arr = toArray(listA, &size);
    printArray(arr, size);
    free(arr);
    int test[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LinkedList *listB = fromArrayToList(test, 10);
    deleteValue(listB, 9);
    addToListAtFront(listB, -4);
    int *testArr = toArray(listB, &size);
    printArray(testArr, size);
    int result = containsValue(listB, -4);
    printf("%d\n", result);
    return 0;
}
