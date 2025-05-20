#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

typedef int EntryType;

typedef struct NodeT {
    EntryType info;
    struct NodeT *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

void CreateList(LinkedList *L);
int EmptyList(LinkedList L);
int FullList(LinkedList L);
void insert(LinkedList *L, int pos, EntryType item);
void delete(LinkedList *L, int pos, EntryType *item);
int size(LinkedList L);
void clear(LinkedList *L);
void printAll(LinkedList *L);
void searchForElement(LinkedList *L, EntryType item);

#endif // LINKEDLIST_H_INCLUDED
