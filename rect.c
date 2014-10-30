/*=============================================================================
#     FileName: rect.c
#         Desc:  none
#       Author: dongwencai
#        Email: mrdong0826@gmail.com
#     HomePage: null
#      Version: 0.0.1
#   LastChange: 2014-10-29 15:50:45
#      History:
=============================================================================*/
#include "rect.h"

bool coord_in_rect(const PCOORD o,const PRECT r);

bool rect_intersect(const PRECT pR0,const PRECT pR1);

PRECT rect_dec(const PRECT pR0,const PRECT pR1);

RECT get_intersect_rect(const PRECT pR0,const PRECT pR1);

static get_pos_srcRect_in_dstRect(const PRECT pSrc,const PRECT pDst);

#define COORD_IN_RECT(o,r)  (o->x >= r->x0 && o->x <= r->x1 && o->y >= r->x0 && o->y <= r->y1)

#define RECT_IS_VALID(RECT r)    (r->x0 < r->x1 && r->y0 < r->y1)

#define MAX(a,b)    (a > b ? a : b)

#define MIN(a,b)    (a < b ? a : b)

bool rect_intersect(const PRECT pR0,const PRECT pR1)
{
  if (pr0->y0 <= pr1->y1) {
    if (pr1->y0 <= pr0->y1) {
      if (pr0->x0 <= pr1->x1) {
        if (pr1->x0 <= pr0->x1) {
          return 1;
        }
      }
    }
  }
  return 0;
}

PRECT rect_dec(const PRECT pSrc,const PRECT pDst)
{
    RECT r;
    PRECT pR;
    r = get_intersect_rect(pSrc,pDst);
    if(RECT_IS_VALID(r))
    {
        if(r->x0 < pSrc->x0)
        {
            pR = (PRECT)malloc(sizeof(RECT));
            pR->x0 = pSrc->x0;
            pR->y0 = r->y0;
            pR->x1 = r->x0;
            pR->y1 = r->y1;
        }
        if(r->x1 < pSrc->x1)
        {
            pR = (PRECT)malloc(sizeof(RECT));
            pR->x0 = r->x1;
            pR->y0 = r->y0;
            pR->x1 = pSrc->x1;
            pR->y1 = r->y1;
        }
        if(r->y0 > pSrc->y0)
        {
            pR = (PRECT)malloc(sizeof(RECT));
            pR->x0 = pSrc->x0;
            pR->y0 = pSrc->y0
            pR->x1 = pSrc->x1;
            pR-y1 = r->y0;
        }
        if(r->y1 < pSrc->y1)
        {
            pR = (PRECT)malloc(sizeof(RECT));
            pR->x0 = pSrc->x0;
            pR->y0 = r->y1;
            pR->x1 = pSrc->x1;
            pR->y1 = pSrc->y1;
        }
    }
    else
    {
        return pSrc;
    }
    return ;
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

static get_pos_srcRect_in_dstRect(const PRECT pSrc,const PRECT pDst)
{
       
}
