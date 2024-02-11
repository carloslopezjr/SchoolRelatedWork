#include <stdio.h>
#include <stdlib.h>

// pop function - will go to the last index of the array and remove it
void pop(int *top) {
    // remove the top element 
    (*top)--;
    printf("The top index is now: %d\n", top);

}

void push(int *top, int value, char *stack) {
    (*top)++;
    stack[*top] = value;
    printf("The top index is now: %d\n", top);
}

// push function - will add a value to the end of the array

// stack array - will hold all the values in the stack



int main() {

    int size = 10; 
    char *exp = malloc(size * sizeof(char));
    int ch, i = 0;

    printf("Carlos Lopez - nvu267 - Spring 2024\n\n");

    printf("Enter expression: ");
    while((ch = getchar()) != '\n' && ch != EOF) {
        if(i == size) {
            size *= 2;
            exp = realloc(exp, size * sizeof(char));
            if (exp == NULL) {
                printf("No Memory Allocated.\n");
                return 1;
            }
        }
        exp[i++] = ch;
    }

    exp[i] = '\0';

    int k = 0;
    int top = -1;

    printf("This is the expression: %s\n", exp);

    char *stack = malloc(size *sizeof(char)); // allocate memory for the stack

    while (k <= i) {

        if (exp[k] == '(' || exp[k] == '[' || exp[k] == '{') {
            
            // if there's an open parenthesis, we want to push that to the stack
            push(&top, exp[k], stack); // there's an issue with the push function
            k++; // increment k
        }
        else if (exp[k] == ')' || exp[k] == ']' || exp[k] == '}') {

            if (stack[top] == exp[k]) {
                pop(&top); // pop function
            }

            k++; // increment k
            break;    
        } else {
            printf("Couldn't find match\n");
            k++; // if nothing is met, just continue
        }
    }

    printf("This is the final stack: %s\n", stack);
    
    return 0;
}