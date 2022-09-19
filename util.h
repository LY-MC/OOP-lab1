#ifndef SDA_TASKS_UTIL_H
#define SDA_TASKS_UTIL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct nodeD {
    int data;
    struct nodeD* next;
    struct nodeD* prev;
} NodeD;

typedef enum {
    EMPTY,
    LOAD_FROM_FILE,
    INPUT_FROM_KEYBOARD,
    PRINT,
    SAVE_TO_FILE,
    APPEND,
    PREPEND,
    REVERSE,
    ADD_TO_INDEX,
    REMOVE_FROM_INDEX,
    SORT,
    SEARCH,
    JOIN,
    BACKWARDS
} ACTION;

void addNode(Node **head, int val);
void printList(Node *head);
void serialize(Node *head);
void deserialize(Node **head);
void push(Node **head, int new_data);
void reverse(Node **head);
Node *getNode(int data);
void insertPos(Node **current, int pos, int data);
int getListLength(Node *head);
void deleteNode(Node **head, int pos);
Node *swap(Node *ptr1, Node *ptr2);
void bubbleSort(Node **head, int count);
int findPos(Node *head, int val);
void printMenu();
void concatenate(Node *a, Node *b);
void pushD(NodeD **head_ref, int new_data);
void reversePrint(NodeD **head_ref);

#endif //SDA_TASKS_UTIL_H
