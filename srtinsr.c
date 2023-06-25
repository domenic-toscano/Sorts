#include <stdlib.h>
#include <string.h>
#include "srt.h"

void srtinsr(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *)) {

    char buf[size], *qb = base;

    for (size_t i = 1; i < nelem; ++i) {

        memcpy(buf, qb + size * i, size);

        size_t j = i;

        while (j > 0 && compar(buf, qb + size * (j - 1)) < 0) {

            memcpy(qb + size * j, qb + size * (j - 1), size);
            --j;
        }

        memcpy(qb + size * j, buf, size);
    }

    return;
}