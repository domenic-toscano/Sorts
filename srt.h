#ifndef SRT_H
#define SRT_H

#include <string.h>

#define MAX_BUF 256

#define swap(qx,qy,sz)                                              \
do {                                                                \
    char buf[MAX_BUF];                                              \
    char *q1 = qx;                                                  \
    char *q2 = qy;                                                  \
    for (size_t m, ms = sz; ms > 0; ms -= m, q1 += m, q2 += m) {    \
        m = ms < sizeof(buf) ? ms : sizeof(buf);                    \
        memcpy(buf, q1, m);                                         \
        memcpy(q1, q2, m);                                          \
        memcpy(q2, buf, m);                                         \
    }                                                               \
} while (0)

void srtbubb(void *, size_t, size_t, int (*)(const void *, const void *));
void srtheap(void *, size_t, size_t, int (*)(const void *, const void *));
void srtinsr(void *, size_t, size_t, int (*)(const void *, const void *));
void srtmerg(void *, size_t, size_t, int (*)(const void *, const void *));

#endif /* SRT_H */