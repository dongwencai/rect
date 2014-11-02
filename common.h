#ifndef __COMMON_H__
#define __COMMON_H__

#define SWAP(a,b)   {   \
    typeof(c)           \
    c = a;              \
    a = b;              \
    b = c;              \
    }

typedef short   i16;
typedef char	bool;
#define MAX(a,b)    (a > b ? a : b)

#define MIN(a,b)    (a < b ? a : b)

#endif
