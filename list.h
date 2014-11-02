#ifndef __LIST_H__
#define __LIST_H__

typedef struct list{
    void *date;
    struct list *next;
}LIST,*PLIST;


extern void list_add(PLIST *pphead, void *date);

extern void list_del(PLIST head,PLIST node);

extern void release_node(PLIST node);

extern void release_list(PLIST head);

#endif
