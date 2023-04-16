#ifndef GITPRO_VECTOR_H
#define GITPRO_VECTOR_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct vector {
    int *data;          // указатель на элементы вектора
    size_t size;        // размер вектора
    size_t capacity;    // вместимость вектора
} vector;

//Создать вектор размера n
vector createVector(size_t n);

//Bзменяет количество памяти,
//выделенное под хранение элементов вектора
void reserve(vector *v, size_t newCapacity);

//удаляет элементы из контейнера,
//но не освобождает выделенную память.
void clear(vector *v);

//освобождает память, выделенную под
//неиспользуемые элементы.
void shrinkToFit(vector *v);

//освобождает память, выделенную вектору.
void deleteVector(vector *v);

//является ли вектор пустым
bool isEmpty(vector *v);

//является ли вектор полным
bool isFull(vector *v);

//которая возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);

//добавляет элемент x в конец вектора v.
//Если вектор заполнен, увеличьте количество выделенной ему памяти в
//2 раза, используя reserve.
void pushBack(vector *v, int x);

void test_pushBack_emptyVector();

void test_pushBack_fullVector();

//удаляет последний элемент из вектора
void popBack(vector *v);

void test_popBack_notEmptyVector();

#endif //GITPRO_VECTOR_H
