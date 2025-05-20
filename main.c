#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Insert Element\n");
    printf("2. Remove Element\n");
    printf("3. Clear List\n");
    printf("4. Check if List is Empty\n");
    printf("5. Size of List\n");
    printf("6. Display All Elements\n");
    printf("7. Search for an Element\n");
    printf("8. Exit\n");
}

int main() {
    LinkedList list;
    CreateList(&list);
    int choice, pos;
    EntryType item;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                printf("Enter position to insert at: ");
                scanf("%d", &pos);
                insert(&list, pos, item);
                break;

            case 2:
                printf("Enter position to retrieve and remove: ");
                scanf("%d", &pos);
                delete(&list, pos, &item);
                printf("Removed item: %d\n", item);
                break;

            case 3:
                clear(&list);
                printf("List cleared.\n");
                break;

            case 4:
                if (EmptyList(list)) {
                    printf("List is empty.\n");
                } else {
                    printf("List is not empty.\n");
                }
                break;

            case 5:
                printf("Size of list: %d\n", size(list));
                break;

            case 6:
                printAll(&list);
                break;

            case 7:
                printf("Enter item to search for: ");
                scanf("%d", &item);
                searchForElement(&list, item);
                break;

            case 8:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
