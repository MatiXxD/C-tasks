#include <stdio.h>
#include <stdlib.h>
#include "list.h"


static void CopyToArray(Item item, List* pnode);


void InitializeList(List* plist){

    plist->entries = malloc(MAXSIZE * sizeof(Item));
    plist->items = 0;

}

bool ListIsEmpty(const List* plist){

    return plist->items == 0;

}


bool ListIsFull(const List* plist){

    return plist->items == MAXSIZE;

}

unsigned int ListItemCount(const List* plist){

    return plist->items;

}

bool AddItem(Item item, List* plist){

    if (ListIsFull(plist))
        return false;
    else
        CopyToArray(item, plist);

    return true;

}

void Traverse(const List* plist, void (*pfun)(Item item)){

    for (int i = 0; i < plist->items; i++)
        (*pfun)(plist->entries[i]);

}

void EmptyTheList(List* plist) {

    free(plist->entries);
    plist->items = 0;

}

static void CopyToArray(Item item, List* pnode) {

    pnode->entries[pnode->items] = item;
    (pnode->items)++;

}