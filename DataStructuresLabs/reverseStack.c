#include <stdio.h>
#include <stdlib.h>

// pop function - will go to the last index of the array and remove it
void pop(int *top)
{
    // remove the top element
    (*top)--;
    // printf("The top index is now: %d\n", *top); // Dereference the pointer to print the value
}

void push(int *top, char value, char *stack)
{
    (*top)++;
    stack[*top] = value;
    // printf("The top index is now: %d\n", *top); // Dereference the pointer to print the value
}

int main()
{

    int size = 4;
    char stack[size];
    int i;

    printf("Enter expression: ");
    for (i = 0; i < size; i++)
    {
        scanf("%c", stack);
    }

    printf("This is the stack: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d: %c\n", i, stack[i]);
    }

    return 0;
}
