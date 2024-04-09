#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int top;
    int capacity;
    char * array;
} Stack;

Stack* createStack()
{
    Stack* pStack = malloc(sizeof(Stack));
    if (pStack == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    pStack->top = -1;
    pStack->capacity = 10;
    pStack->array = malloc(pStack->capacity * sizeof(char));
    if (pStack->array == NULL)
    {
        printf("Memory allocation failed\n");
        free(pStack);
        return NULL;
    }
    return pStack;
}

// TODO
void push(Stack* stack, char charToBeAdded)
{
    if (stack->top == stack->capacity)
    {
        printf("Push Failed - Stack Full\n");
        return;
    }
    else
    {
        // current top tells us last value
        stack->array[stack->top + 1] = charToBeAdded;
        // re-assign top to be one more than previous
        stack->top++;
        return;
    }
}

bool isEmpty(Stack* stack)
{
    if (stack->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Pop Failed - Stack Empty\n");
        return;
    }
    else
    {
        stack->top--;
        return;
    }
}

int peek(Stack* stack)
{
    return stack->array[stack->top];
}

int main()
{
    Stack* stackA = createStack();

    printf("stackA top: %d", stackA->top);
}
