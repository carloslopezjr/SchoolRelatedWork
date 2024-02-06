#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;
    struct Node *nextNode;
};

struct Node *newNode(int data)
{

    // allocate memory for the node
    struct Node *stackNode = (struct Node *)malloc(sizeof(struct Node));

    stackNode->data = data;
    stackNode->nextNode = NULL;

    return stackNode;
}