#include "vector.h"
#include "malloc.h"
#include <assert.h>
#include "stdio.h"

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

bool isEmpty(vector *v) {
    return (v->size == 0 ? true : false);
}

bool isFull(vector *v) {
    return (v->size == v->capacity ? true : false);
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i - 1];
}

void pushBack(vector *v, int x) {
    if(v->capacity == 0) {
        reserve(v, 1);
        v->capacity++;
        v->data[0] = x;
        v->size++;
    } else if (isFull(v)) {
        reserve(v, v->capacity * 2);
        v->data[v->size] = x;
        v->size++;
        v->capacity *= 2;
    } else {
        v->data[v->size] = x;
        v->size++;
    }
}

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 42);
    assert(v.capacity == 1);
    assert(v.size == 1);
    assert(v.data[v.size - 1] == 42);
}

void test_pushBack_fullVector() {
    vector v = createVector(12);
    v.size = 12;
    pushBack(&v, 42);
    assert(v.capacity == 24);
    assert(v.size == 13);
    assert(v.data[v.size - 1] == 42);
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else {
        v->size--;
    }
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}