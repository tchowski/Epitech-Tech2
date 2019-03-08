/*
** EPITECH PROJECT, 2019
** malloc.c
** File description:
** malloc
*/

#include "../include/malloc.h"
#include "unistd.h"

void *resize_break(size_t size, memory_t *memory, void *allocate_address)
{
    while (memory != NULL) {
        if (memory->is_free == true && size <= memory->data_size) {
            memory->is_free = false;
            return (memory->allocate_adress);
        }
        memory = memory->next;
    }
    if (globale != NULL && size != 0) {
        while (globale->next != NULL)
            globale = globale->next;
        if ((allocate_address = sbrk(size + sizeof(memory_t))) == (void *)-1)
            return (NULL);
        globale = allocate_address;
        globale->allocate_adress = allocate_address + sizeof(memory_t);
        globale->data_size = size;
        globale->next = NULL;
        globale->is_free = false;
        return (globale->allocate_adress);
    } else
        return (NULL);
}

void *malloc(size_t size)
{
    void *allocate_address;
    memory_t *memory;

    if (size == 0)
        return (NULL);
    if (globale == NULL && size != 0) {
        if ((allocate_address = sbrk(size + sizeof(memory_t))) == (void *)-1)
            return (NULL);
        globale = allocate_address;
        globale->allocate_adress = allocate_address + sizeof(memory_t);
        globale->data_size = size;
        globale->next = NULL;
        globale->is_free = false;
        return (globale->allocate_adress);
    }
    memory = globale;
    return (resize_break(size, memory, allocate_address));
}

void free(void *ptr)
{
    memory_t *memory;
    memory = globale;

    if (ptr == NULL)
        return;
    while (memory != NULL) {
        if (memory->allocate_adress == ptr) {
            memory->is_free = true;
            return;
        }
        memory = memory->next;
    }
}

void *realloc(void *ptr, size_t size)
{
    void *new_realloc;

    new_realloc = malloc(size);
    return (new_realloc);
}
