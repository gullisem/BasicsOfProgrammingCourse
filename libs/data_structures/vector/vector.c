#include "vector.h"
#include "malloc.h"

vector createVector(size_t n) {
    int *v = (int *) malloc(sizeof(int) * n);
    if (NULL == v) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {(n == 0 ? NULL : v), 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    v->data = (int*) realloc(v->data, newCapacity);
    if (v->data == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    if(v->data > newCapacity)
        v->data = newCapacity;

    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}