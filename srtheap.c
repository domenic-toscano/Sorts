#include <stdlib.h>
#include <string.h>
#include "srt.h"

void heapify(void* base, size_t nelem, size_t rootIndex, int (*compar)(const void*, const void*)) {
    size_t largest = rootIndex;
    size_t leftChild = 2 * rootIndex + 1;
    size_t rightChild = 2 * rootIndex + 2;

    char* qLargest = (char*)base + nelem * largest;
    char* qLeftChild = (char*)base + nelem * leftChild;
    char* qRightChild = (char*)base + nelem * rightChild;

    // If the left child is larger than the root
    if (leftChild < nelem && compar(qLeftChild, qLargest) > 0)
        largest = leftChild;

    // If the right child is larger than the largest so far
    if (rightChild < nelem && compar(qRightChild, qLargest) > 0)
        largest = rightChild;

    // If the largest is not the root
    if (largest != rootIndex) {
        char* qRoot = (char*)base + nelem * rootIndex;
        swap(qRoot, qLargest, nelem);
        heapify(base, nelem, largest, compar);
    }
}

void srtheap(void *base, size_t nelem, size_t size, int (*compar)(const void *, const void *)){
    // Build the heap (rearrange the array)
    for (size_t i = nelem / 2 - 1; i >= 0; --i)
        heapify(base, nelem, i, compar);

    // Extract elements from the heap one by one
    for (size_t i = nelem - 1; i > 0; --i) {
        char* qRoot = (char*)base;
        char* qLast = (char*)base + size * i;
        swap(qRoot, qLast, size);
        heapify(base, i, 0, compar);
    }
}