#include "list.h"
#include "stdio.h"

void list_add(PLIST *pphead, void *date)
{
    struct list *newNode;
    newNode = (struct list *)malloc(sizeof(struct list));
    if(newNode)
    {
        newNode->date = date;
        if(*pphead)
        {
            newNode->next = (*pphead)->next;
            *pphead = newNode;
        }
        else
        {
            *pphead = newNode;
            newNode->next = NULL;
        }

    }
    else
    {
        printf("alloc mem failt\n");
    }
}

void list_del(PLIST head,PLIST node)
{
    if(head == node)
    {
        release_node(head);
        head = NULL;
    }
    while(head)
    {
        if(head->next == node)
        {
            head->next = node->next;
            release_node(node);
        }
    }
}

void release_node(PLIST node)
{
    if(node)
    {
        if(node->date)
        {
            free(node->date);
        }
        free(node);
    }
    return ;
}

void release_list(PLIST head)
{
    PLIST nxt = NULL;
    while(head)
    {
        nxt = head->next;
        release_node(head);
        head = nxt;
    }
    head = NULL;

}
