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

    int size = 10;
    char *exp = malloc(size * sizeof(char));
    int ch, i = 0;

    printf("Carlos Lopez - nvu267 - Spring 2024\n");

    printf("Enter expression: ");
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (i == size - 1)
        { 
            size *= 2;
            exp = realloc(exp, size * sizeof(char));
            if (exp == NULL)
            {
                printf("No Memory Allocated.\n");
                return 1;
            }
        }
        exp[i++] = ch;
    }

    exp[i] = '\0';

    int k = 0;
    int top = -1;

    // printf("This is the expression: %s\n", exp);

    char *stack = malloc(100 * sizeof(char));

    while (k < i)
    { 

        if (exp[k] == '(' || exp[k] == '[' || exp[k] == '{')
        {

            push(&top, exp[k], stack); 
            k++;
        }
        else if (exp[k] == ')' || exp[k] == ']' || exp[k] == '}')
        {

            if (top >= 0 && ((exp[k] == ')' && stack[top] == '(') ||
                             (exp[k] == ']' && stack[top] == '[') ||
                             (exp[k] == '}' && stack[top] == '{')))
            {
                pop(&top);
            }
            else
            {
                printf("It's Not Balanced (0_0)\n");
                return 1;
            }

            k++;
        }
        else
        {
            k++;
        }
    }

    if (top == -1)
    {
        printf("It's Balanced (^_^)\n");
    }
    else
    {
        printf("It's Not Balanced (0_0)\n");
    }

    free(exp); // Free allocated memory
    free(stack);

    return 0;
}
