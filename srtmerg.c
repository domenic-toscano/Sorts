#include <stdlib.h>
#include <string.h>
#include "srt.h"

void srtmerg(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *)) {

    char *qb = base, *ql, *qr, *qt;
    size_t i, j, l, r;

    if (nelem <= 1) {
        return;
    }
    else if (nelem == 2) {
        if (compar(qb, qb + size) > 0) {
            swap(qb, qb + size, size);
        }
        return;
    }

    l = nelem / 2;
    r = nelem - l;

    ql = qt = malloc(size * l);
    memcpy(ql, qb, size * l);

    qr = qb + size * l;

    srtmerg(ql, l, size, compar);
    srtmerg(qr, r, size, compar);

    i = 0; j = l;

    while(i < l && j < nelem) {
        if (compar(ql, qr) <= 0) {
            memcpy(qb, ql, size);
            qb += size;
            ql += size;
            ++i;
        }
        else {
            memcpy(qb, qr, size);
            qb += size;
            qr += size;
            ++j;
        }
    }

    if (i < l) {
        memcpy(qb, ql, size * (l - i));
    }

    free(qt);

    return;
}