#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// initial stacks
char inputStack[100];
char infix[100];
char postfix[100];

// intital value for top
int top = -1;

// looks to see if top is maxed out, if not, increase top and add character
void push(char ch)
{

    if (top == 100 - 1)
    {

        printf("Stack Overflow\n");
        return;
    }

    top++;
    inputStack[top] = ch;
}

// checks value of top and returns 0 or 1 depending if it's at the initial value
int isEmpty()
{

    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// checks operation character and returns value that determines precedence
int order(char operation)
{

    if (operation == '^')
    {
        return 3; // high priority
    }
    else if (operation == '/' || operation == '*')
    {
        return 2; // mid priority
    }
    else if (operation == '+' || operation == '-')
    {
        return 1; // low priority
    }
    else
    {
        return 0;
    }
}

// creates a temp char and equals it to the last element in the array, and reduces the stack by 1
char pop()
{

    char ch;
    ch = inputStack[top];
    top = top - 1;
    return ch;
}

// does the logic to put elements in the postStack
void postStack()
{
    int j = 0; // counter variable for iterations
    char operation;
    char temp; // stores value of pop()
    for (int i = 0; infix[i] != '\0'; i++)
    {
        operation = infix[i];

        if (operation == '(') // if operation is ( then push into inputStack
        {
            push(operation);
        }
        else if (operation == ')')
        {
            while ((temp = pop()) != '(')
            {
                postfix[j++] = temp;
            }
        }
        else if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '^') // if operation equals any one of these, it will check to see if the stack is empty and if the top of the stack is greater precedence than the one below it
        {
            while (!isEmpty() && order(inputStack[top]) >= order(operation))
            {
                postfix[j++] = pop();
            }
            push(operation);
        }
        else
        {
            postfix[j++] = operation;
        }
    }

    while (!isEmpty()) // check to see if stack is empty so it can finish with the '\0'
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main()
{

    printf("Carlos Lopez, nvu267 <Spring 2024>\n");
    printf("Enter the Infix Expression: \n");
    fgets(infix, sizeof(infix), stdin);

    size_t len = strlen(infix);
    if (infix[len - 1] == '\n')
    {
        infix[len - 1] = '\0';
    }

    postStack();
    printf("The Postfix expression: \n");
    for (int i = 0; i < strlen(postfix); i++) {
        printf("%c ", postfix[i]);
    }

    printf("\n");
    printf("End of Program\n");



    return 0;
}