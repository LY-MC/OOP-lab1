#include "util.h"

void addNode(Node **head, int val) {
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        Node *lastNode = *head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }

        lastNode->next = temp;
    }
}

void printList(Node *head) {
    Node *temp = head;
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void serialize(Node *head) {
    FILE *file = fopen("list.txt", "w+");

    for (Node *temp = head; temp != NULL; temp = temp->next) {
        fprintf(file, "%d -> ", temp->data);
    }

    fclose(file);
}

void deserialize(Node **head) {
    FILE *file = fopen("list.txt", "r");

    int val;
    while (fscanf(file, "%d -> ", &val) > 0) {
        addNode(head, val);
    }

    fclose(file);
}

void push(Node **head, int new_data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void reverse(Node **head) {
    Node *prev = NULL;
    Node *current = *head;
    Node *next = NULL;
    while (current != NULL) {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }
    *head = prev;
}

Node *getNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertPos(Node **current, int pos, int data) {
    while (pos--) {
        if (pos == 0) {
            Node *temp = getNode(data);
            temp->next = *current;
            *current = temp;
        } else {
            current = &(*current)->next;
        }
    }
}

int getListLength(Node *head) {
    int cnt = 1;
    while (head->next != NULL) {
        head = head->next;
        cnt++;
    }

    return cnt;
}

void deleteNode(Node **head, int pos) {
    if (pos >= getListLength(*head)) {
        return;
    }

    Node *temp = *head;
    if (pos == 0) {
        *head = (*head)->next;
        temp->next = NULL;
    } else {
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }

        Node *del = temp->next;
        temp->next = temp->next->next;
        del->next = NULL;
    }
}

Node *swap(Node *ptr1, Node *ptr2) {
    Node *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void bubbleSort(Node **head, int count) {
    Node **h;
    int swapped;

    for (int i = 0; i <= count; i++) {
        h = head;
        swapped = 0;

        for (int j = 0; j < count - i - 1; j++) {
            Node *p1 = *h;
            Node *p2 = p1->next;
            if (p1->data > p2->data) {
                *h = swap(p1, p2);
                swapped = 1;
            }
            h = &(*h)->next;
        }

        if (!swapped) {
            break;
        }
    }
}

int findPos(Node *head, int val) {
    int cursor = 0;
    while (head->next != NULL) {
        if (head->data == val) {
            return cursor;
        }
        head = head->next;
        cursor++;
    }

    return -1;
}

void concatenate(Node *a, Node *b) {
    if( a != NULL && b!= NULL ) {
        if (a->next == NULL)
            a->next = b;
        else
            concatenate(a->next,b);
    } else {
        printf("Either a or b is NULL\n");
    }
}

void pushD(NodeD **head_ref, int new_data) {
    NodeD *new_node = (NodeD*)malloc(sizeof(NodeD));
    NodeD *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
    return;
}

void reversePrint(NodeD **head_ref) {
    NodeD *tail = *head_ref;
    while (tail->next != NULL) {
        tail = tail->next;
    }
 
    while (tail != *head_ref) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("%d \n", tail->data);
}

void printMenu() {
    printf("Press 1 to load the list from saved file.\n");
    printf("Press 2 to input the data structure from keyboard\n");
    printf("Press 3 to print the data to the terminal\n");
    printf("Press 4 to save the data to file\n");
    printf("Press 5 to append\n");
    printf("Press 6 to prepend\n");
    printf("Press 7 to reverse\n");
    printf("Press 8 to add a value to the specific index\n");
    printf("Press 9 to remove a value to the specific index\n");
    printf("Press 10 to sort the linked list, with re-arranging the cells, not just copying values\n");
    printf("Press 11 to search for a value\n");
    printf("Press 12 to join two linked lists\n");
    printf("Press 13 to print doubly linked list in reverse order \n");
    printf("Enter your choice:\n");
}
