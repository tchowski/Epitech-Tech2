/*
** EPITECH PROJECT, 2019
** objdump.h
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
#define OBJDUMP_H_

#include <elf.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

#define NAME strtab + shdr[i].sh_name

#define BFD_NO_FLAGS 0x00
#define HAS_RELOC 0x01
#define EXEC_P 0x02
#define HAS_LINENO 0x04
#define HAS_DEBUG 0x08
#define HAS_SYMS 0x10
#define HAS_LOCALS 0x20
#define DYNAMIC 0x40
#define WP_TEXT 0x80
#define D_PAGED 0x100

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

int check_elf(Elf64_Ehdr *ehdr);
bool check_elf_64(Elf64_Ehdr *ehdr);
int check_arguments(int argc, char **argv, int check_error, void *map);
int run_elf(char *map, char *path);
int init_elf(char *argv, void **map);
int init_elf_out(char *path, void **map);
void objdump_header(Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, char *strtab, t_sym *);

#endif /* !OBJDUMP_H_ */
