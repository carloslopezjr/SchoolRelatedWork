#include <stdio.h>
#include <string.h>

char *simplifyPath(char *path)
{

    char delimeter[] = "/.";
    char token = strtok(path, delimeter);
    char *newString = malloc(3000 * sizeof(char));
    newString[0] = '\0';
    if (token == NULL)
    {
        strcat(newString, "/");
    }

    while (token != NULL)
    {
        strcat(newString, "/");
        strcat(newString, token);
        token = strtok(NULL, delimeter);
    }

    printf("%s\n", newString);

    return newString;
    // test
}
