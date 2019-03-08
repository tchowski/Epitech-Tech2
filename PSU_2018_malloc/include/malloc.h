/*
** EPITECH PROJECT, 2019
** malloc.h
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct memory_s {
    struct memory_s *next;
    void *allocate_adress;
    unsigned int data_size;
    bool is_free;
} memory_t;

memory_t *globale = NULL;

void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);

#endif /* !MALLOC_H_ */
