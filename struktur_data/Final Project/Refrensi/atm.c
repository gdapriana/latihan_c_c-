#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data) {
    struct StackNode* stackNode = (struct StackNode*) malloc (sizeof(struct StackNode));
    stackNode -> data = data;
    stackNode -> next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* root) {
    return !root;
}

int main() { 
    printf("Hello World");
}