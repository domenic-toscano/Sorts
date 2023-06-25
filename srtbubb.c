#include <stdbool.h>
#include <stddef.h>
#include "srt.h"

void srtbubb(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *)) {

    for (size_t i = nelem - 1; i > 0; --i) {

        bool sorted = true;

        for (size_t j = 0; j < i; ++j) {

            char *qj = (char *)base + size * j;
            char *qn = qj + size;

            if (compar(qj, qn) > 0) {

	            swap(qj, qn, size);
	            sorted = false;
            }
        }

        if (sorted) {
            break;
        }
    }

    return;
}