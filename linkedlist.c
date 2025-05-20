#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"

void CreateList(LinkedList *L){
    L->head = NULL;
    L->size = 0;
}

int EmptyList(LinkedList L){
    return (L.head == NULL);
}

int FullList(LinkedList L){
    return 0;
}

void insert(LinkedList *L, int pos, EntryType item){
    Node *newnode = (Node*)malloc(sizeof(Node));

    if (newnode == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    newnode->info = item;

    if(pos == 0){
        newnode->next = L->head;
        L->head = newnode;
        L->size++;
    }else{
        Node *slider = L->head;

        for(int i = 0; i < pos - 1 && slider != NULL; i++){
            slider = slider->next;
        }
        // If slider is NULL, it means the position is out of the list's bounds (greater than the list size).
        // Accessing slider->next in this case would cause a runtime error.
        if (slider == NULL) {
            printf("Error: Position out of range.\n");
            free(newnode);
            return;
        }

        newnode->next = slider->next;
        slider->next = newnode;
        L->size++;
    }
}

void delete(LinkedList *L, int pos, EntryType *item){
    if(L->head == NULL){
        return;
    }


    if (pos < 0 || pos >= L->size) {
        printf("Error: Position out of range.\n");
        return;
    }

    Node *temp;

    if(pos == 0){
        *item = L->head->info;
        temp = L->head;
        L->head = L->head->next;
        L->size--;
        free(temp);
    }else{
        Node *slider = L->head;
        for(int i = 0; i < pos - 1 && slider != NULL; i++){
            slider = slider->next;
        }

        if(slider == NULL || slider->next == NULL){
            printf("Error: Unexpected NULL pointer.\n");
            return;
        }

        *item = slider->next->info;
        temp = slider->next;
        slider->next = slider->next->next;
        L->size--;
        free(temp);
    }
}

int size(LinkedList L){
    return L.size;
}

void printAll(LinkedList *L){
    if(EmptyList(*L)){
        printf("List is empty.\n");
        return;
    }

    Node *current = L->head;

    for(int i = 0; i < L->size && current != NULL; i++){
        printf("Index [%d] = %d\n", i, current->info);
        current = current->next;
    }
}

void clear(LinkedList *L){
    Node *temp;
    while(!EmptyList(*L)){
        temp = L->head;
        L->head = L->head->next;
        free(temp);
    }
    L->head = NULL;
    L->size = 0;
}

void searchForElement(LinkedList *L, EntryType item){
    if(EmptyList(*L)){
        printf("List is empty.\n");
        return;
    }

    Node *current = L->head;
    bool flag = false;

    for(int i = 0; i < L->size && current != NULL; i++){
        if(current->info == item){
            printf("Element %d found at index %d.\n", item, i);
            flag = true;
        }
        current = current->next;
    }
    if(!flag){
        printf("Element %d not found in the list.\n", item);
    }
}
