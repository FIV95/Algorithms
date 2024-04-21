#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define MAX_CAPACITY 10

// STRUCTS
typedef struct Node {
    char* data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Que {
    struct Node* head;
    struct Node* tail;
    int currentSize;
    int capacity;
} Que;

// FUNCTIONS

Que* createQue();
struct Node* peakFrontOfQue(Que* que);
struct Node* peakBackOfQue(Que* que);
void enque(Que* que, char* stringToBeAdded);
void deque(Que* que);
Que* prioritizeQue(Que* que, Node* nodeToBeCompared);
int currentSize(Que* que);
void printQue(Que* que);

Que* createQue() {
    Que *newQue = malloc(sizeof(Que));
    newQue->capacity = MAX_CAPACITY;
    newQue->currentSize = 0;
    newQue-> head = NULL;
    newQue-> tail = NULL;
    return newQue;
}

void enque(Que* que, char* stringToBeAdded) {

    if (que->currentSize+1 > MAX_CAPACITY) {
        printf("ERROR ATTEMPTING TO ENQUE: Que Full\n");
        return;
    }
    struct Node* newNode = malloc(sizeof(Node));
    newNode->data = stringToBeAdded;

    // next we check the status of the Que
    // if head and tail are empty
    if (que->head == NULL && que->tail == NULL) {
        que->head = newNode;
        que->tail = newNode;
        que->currentSize++;
    }
    // the only other option is that the que has a tail and we need to adjust it.
    // we need to compare the stringToBeAdded to the head->data
        // if length is less than head->data
            // we have to check each node....
            // recursively call it?
    else if (que->tail != NULL || que->head != NULL) {
        newNode->prev = que->tail;
        que->tail->next = newNode;
        que->tail = newNode;
        que->currentSize++;
    }
}

void deque(Que* que) {
    struct Node *nodeToBeDeleted = que->head;
    if (que->head->next == NULL) {
        que->currentSize--;
        free(nodeToBeDeleted);
        return;
    }
    que->head = que->head->next;
    que->head->prev = NULL;
    free(nodeToBeDeleted);
    que->currentSize--;
    return;
}

struct Node* peakFrontOfQue(Que* que) {
    return que->head;
}

struct Node* peakBackOfQue(Que* que) {
    return que->tail;
}

int currentSize(Que* que) {
    return que->currentSize;
}

void printQue(Que* que) {
    Node* runner = malloc(sizeof(Node*));

    runner = que->head;

    while (runner) {
        if (runner->next == NULL) {
            printf("%s\n", runner->data);
            return;
        }
        printf("%s,", runner->data);
        runner = runner->next;
    }
    printf("\n");
    free(runner);
}

Que* prioritizeQue(Que* que, Node* nodeToBeCompared) {
    Node *runner = malloc(sizeof(Node));
    // Node *tailRunner = malloc(sizeof(Node));
    runner = que->head;
    // tailRunner = que->tail;
    while (runner)
    {
        // if current node is less than the stringToBeAdded
        if (strlen(runner->data) < strlen(nodeToBeCompared->data)) {
            runner->prev = nodeToBeCompared;
            nodeToBeCompared->next = runner;
        }
        if (runner->next == NULL) {
            nodeToBeCompared->prev = runner;
            runner->next = nodeToBeCompared;
            nodeToBeCompared->next == NULL;
        }
            runner = runner->next;
    }




}

// ! we can get the size of the que to determine how many possible movements we need to make
// ! we have to find the largest word and set it to position 0 - AKA - HEAD of que
// ! we can recursively call the prioitizeQue function until it has no more strings left


int main () {

    Que* queA = createQue();
    enque(queA, "0"); enque(queA, "01");enque(queA, "001");enque(queA, "0001");enque(queA, "00001");
    enque(queA, "000001"); enque(queA, "0000001"); enque(queA, "00000001"); enque(queA, "000000001"); enque(queA, "0000000001");
    printQue(queA);
    int queALength = currentSize(queA);
    printf("%i\n", queALength);
    // deque(queA);
    queALength = currentSize(queA);
    printf("%i\n", queALength);
    printQue(queA);
    queALength = currentSize(queA);
    printf("%i\n", queALength);
    prioritizeQue(queA);
    printQue((queA));
    return 0;
}
