#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char inputStack[100];
char infix[100];
char postfix[100];

int top = -1;

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

int order(char operation)
{

    if (operation == '^')
    {
        return 3;
    }
    else if (operation == '/' || operation == '*')
    {
        return 2;
    }
    else if (operation == '+' || operation == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char pop()
{

    char ch;
    ch = inputStack[top];
    top = top - 1;
    return ch;
}

void postStack()
{
    int j = 0;
    char operation;
    char temp;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        operation = infix[i];

        if (operation == '(')
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
        else if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '^')
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

    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main()
{

    printf("Carlos Lopez, nvu267 <Spring 2024>\n");
    printf("Enter the Infix Expression: \n");
    gets(infix);

    postStack();
    printf("The Postfix expression: \n");
    for (int i = 0; postfix[i] != '\0'; i++) {
        printf("%c ", postfix[i]);
    }

    printf("\n");

    return 0;
}