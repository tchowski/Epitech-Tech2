/*
** EPITECH PROJECT, 2019
** nm.h
** File description:
** nm
*/

#ifndef NM_H_
#define NM_H_

#include <elf.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

int check_elf(Elf64_Ehdr *ehdr);

typedef struct sym {
    Elf64_Sym *sym;
    size_t tabsize;
} t_sym;

typedef struct list_symbol {
    char *name_symbol;
    Elf64_Addr virtual_address;
    char type;
    struct list_symbol *next;
} t_list;

typedef struct list {
    t_list *head;
} list_p;

typedef struct display {
    int i;
    char *tmp;
    char *prev;
    char *next;
} t_display;

typedef struct swap {
    t_list *prev1;
    t_list *prev2;
    t_list *node1;
    t_list *node2;
    t_list *tmp;
} t_swap;

list_p *get_symbol_by_list(t_sym *sym, Elf64_Shdr *shdrs, char *strtab);
list_p *init_list(void);
void display_list(t_list *list);
void print_list(list_p *);
void sort_and_print_list(list_p *list);
char **list_to_array(list_p *list);
int get_size_list(list_p *list);
char *delete_under(char *string);
void print_all_list(list_p *);
void swap_list(int index_prev, int index_next, list_p *list);
int check_arguments(int argc, char **argv, int check_error, void *map);
int run_elf(char *map, char *path, int argc);
int init_elf(char *argv, void **map);
int init_elf_out(char *path, void **map);
void sort(char **arr[], int n);
void swap_array_and_list(char **array, char **tmp, list_p *list, int size);
char **create_tmp_array(int size, char **array);
void free_tabs(char **tab, int size);
void check_under(char **array, list_p *list, int size);
void print_tabs(char **array, int size);

#endif /* !NM_H_ */
