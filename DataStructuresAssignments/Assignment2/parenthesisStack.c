#include <stdio.h>
#include <stdlib.h>

// pop function - will go to the last index of the array and remove it
void pop() {
    // last index, replace 
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

    while (k <= i) {
        if (exp[k] == '(' || exp[k] == '[' || exp[k] == '{') {
            // push function
            k++;
            break;
        }
        
        if (exp[k] == ')' || exp[k] == ']' || exp[k] == '}') {
            // if top of stack == exp[k]
                // pop function
            
            k++;
            break;    
        }
    }
    
    return 0;
}