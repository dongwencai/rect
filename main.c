#include "stdio.h"
#include "rect.h"
#include "list.h"

int main()
{
    PLIST head = NULL,tmp = NULL;
    RECT src = {0,0,720,568};
    RECT dst = {50,50,200,300};
    PRECT pR = NULL;
    head = rect_dec(&src,&dst);
    tmp = head;
    while(tmp)
    {
        pR =(PRECT)tmp->date;
        printf("x0:%d,y0:%d\tx1:%d,y1:%d\n",pR->x0,pR->y0,pR->x1,pR->y1);
        tmp = tmp->next;
    }
    release_list(head);
    return 0;
}
