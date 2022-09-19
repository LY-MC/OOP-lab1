#include "util.h"

int main() {
    int running = 1;
    Node *head = NULL;
    while (running) {
        printMenu();

        int temp;
        scanf("%d", &temp);
        ACTION action = (ACTION) temp;
        switch (action) {

            case LOAD_FROM_FILE: {
                head = NULL;
                deserialize(&head);
                break;
            }

            case INPUT_FROM_KEYBOARD: {
                head = NULL;
                int n;
                printf("Enter quantity of nodes in linked list: \n");
                scanf("%d", &n);
                int values[n];

                printf("Enter nodes: \n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &values[i]);
                }

                addNode(&head, values[0]);

                for (int i = 1; i < n; i++) {
                    addNode(&head, values[i]);
                }
                break;
            }

            case PRINT: {
                printList(head);
                break;
            }

            case SAVE_TO_FILE: {
                serialize(head);
                break;
            }

            case APPEND: {
                int node;
                printf("Enter a node: \n");
                scanf("%d", &node);
                addNode(&head, node);
                break;
            }

            case PREPEND: {
                int node;
                printf("Enter a node: \n");
                scanf("%d", &node);
                push(&head, node);
                break;
            }

            case REVERSE: {
                reverse(&head);
                break;
            }

            case ADD_TO_INDEX: {
                int position, node;
                printf("Enter position: \n");
                scanf("%d", &position);
                printf("Enter a node: \n");
                scanf("%d", &node);
                insertPos(&head, position, node);
                break;
            }

            case REMOVE_FROM_INDEX: {
                int position;
                printf("Enter position: \n");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            }

            case SORT: {
                bubbleSort(&head, getListLength(head));
                break;
            }

            case SEARCH: {
                int val;
                printf("What value should be searched? \n");
                scanf("%d", &val);

                int index = findPos(head, val);
                if (index == -1) {
                    printf("This value is NOT in the list \n");
                } else {
                    printf("This value IS in the list at index %d \n", index);
                }
                break;
            }

            case JOIN: {
                printf("Enter the second linked list \n");
                Node *head2 = NULL;
                int n;
                printf("Enter number of nodes in the linked list: \n");
                scanf("%d", &n);
                printf("Enter nodes: \n");
                int values[n];

                for (int i = 0; i < n; i++){
                    scanf("%d", &values[i]);
                    addNode(&head2, values[i]);
                }

                concatenate(head, head2);
                break;
            }

            case 13: BACKWARDS: {
                NodeD *root = NULL;

                int n;
                printf("Enter number of nodes in the doubly linked list: \n");
                scanf("%d", &n);
                printf("Enter nodes: \n");
                int values[n];

                for (int i = 0; i < n; i++){
                    scanf("%d", &values[i]);
                    pushD(&root, values[i]);
                }

                reversePrint(&root);
                break;
            }

            default:
                printf("wrong Input\n");
        }
    }

    return 0;
}
