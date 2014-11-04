/*=============================================================================
# FileName: rect.c
# Desc: none
# Author: dongwencai
# Email: mrdong0826@gmail.com
# HomePage: null
# Version: 0.0.1
# LastChange: 2014-10-29 15:50:45
# History:
=============================================================================*/
#include "rect.h"
#include "list.h"
#include "common.h"
#include "stdio.h"
#define bool char
bool coord_in_rect(const PCOORD o,const PRECT r);

bool rect_intersect(const PRECT pR0,const PRECT pR1);

PLIST rect_dec(const PRECT pR0,const PRECT pR1);

RECT get_intersect_rect(const PRECT pR0,const PRECT pR1);

#define COORD_IN_RECT(o,r) (o->x0 >= r->x0 && o->x0 <= r->x1 && o->y0 >= r->x0 && o->y0 <= r->y1)

#define RECT_IS_VALID(r) (r.x0 < r.x1 && r.y0 < r.y1)

bool rect_intersect(const PRECT pR0,const PRECT pR1)
{
	if (pR0->y0 <= pR1->y1) {
		if (pR1->y0 <= pR0->y1) {
			if (pR0->x0 <= pR1->x1) {
				if (pR1->x0 <= pR0->x1) {
					return 1;
				}
			}
		}
	}
	return 0;
}
PLIST rect_dec(const PRECT pSrc,const PRECT pDst)
{
	RECT r;
	PRECT pR;
    PLIST head = NULL;
	r = get_intersect_rect(pSrc,pDst);
	if(RECT_IS_VALID(r))
	{
		if(r.x0 > pSrc->x0)
		{
			pR = (PRECT)malloc(sizeof(RECT));
			pR->x0 = pSrc->x0;
			pR->y0 = r.y0;
			pR->x1 = r.x0;
			pR->y1 = r.y1;
            list_add(&head,pR);
		}
		if(r.x1 < pSrc->x1)
		{
			pR = (PRECT)malloc(sizeof(RECT));
			pR->x0 = r.x1;
			pR->y0 = r.y0;
			pR->x1 = pSrc->x1;
			pR->y1 = r.y1;
            list_add(&head,pR);
		}
		if(r.y0 > pSrc->y0)
		{
			pR = (PRECT)malloc(sizeof(RECT));
			pR->x0 = pSrc->x0;
			pR->y0 = pSrc->y0;
			pR->x1 = pSrc->x1;
			pR->y1 = r.y0;
            list_add(&head,pR);
		}
		if(r.y1 < pSrc->y1)
		{
			pR = (PRECT)malloc(sizeof(RECT));
			pR->x0 = pSrc->x0;
			pR->y0 = r.y1;
			pR->x1 = pSrc->x1;
			pR->y1 = pSrc->y1;
            list_add(&head,pR);
		}
	}
	else
	{
        pR = (PRECT)malloc(sizeof(RECT));
        *pR = *pSrc;
        list_add(&head,pR);
	}
	return head;
}
RECT get_intersect_rect(const PRECT pR0,const PRECT pR1)
{
	RECT rect = {0};
	rect.x0 = (pR0->x0 > pR1->x0) ? pR0->x0 : pR1->x0;
	rect.y0 = (pR0->y0 > pR1->y0) ? pR0->y0 : pR1->y0;
	rect.x1 = (pR0->x1 < pR1->x1) ? pR0->x1 : pR1->x1;
	rect.y1 = (pR0->y1 < pR1->y1) ? pR0->y1 : pR1->y1;
	return rect;
}

