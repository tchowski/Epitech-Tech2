/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include "objdump.h"
#include <sys/stat.h>

int init_elf(char *argv, void **map)
{
    int fd;
    size_t len;

    fd = open(argv, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "No such file: %s\n", argv);
        return (-1);
    }
    len = lseek(fd, 0, SEEK_END);
    *map = mmap(NULL, len, PROT_READ, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        fprintf(stderr, "MAP_FAILED\n");
        return (-1);
    }
    return (0);
}

int init_elf_out(char *path, void **map)
{
    int fd;
    size_t len;

    fd = open(path, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "No such file: %s\n", path);
        return (-1);
    }
    len = lseek(fd, 0, SEEK_END);
    *map = mmap(NULL, len, PROT_READ, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        fprintf(stderr, "MAP_FAILED\n");
        return (-1);
    }
    return (0);
}

char *set_strtab(t_sym *sym, Elf64_Shdr *shdrs, Elf64_Ehdr *ehdr, char *map)
{
    char *strs;

    sym->sym = NULL;
    sym->tabsize = 0;
    strs = (char *)(map + shdrs[ehdr->e_shstrndx].sh_offset);
    for (int i = 0; i < ehdr->e_shnum; i++) {
        if (strcmp(strs + shdrs[i].sh_name, ".symtab") == 0) {
            sym->sym = (Elf64_Sym *)(map + shdrs[i].sh_offset);
            sym->tabsize = shdrs[i].sh_size / sizeof(Elf64_Sym);
        }
    }
    if (strs)
        return (strs);
    fprintf(stderr, "No .strtab");
    return (NULL);
}

int run_elf(char *map, char *path)
{
    char *strtab;
    t_sym sym;

    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)map;
    if (check_elf(ehdr) == -1) {
        fprintf(stderr, "my_objdump: %s: File format not reconized\n", path);
        return (-1);
    }
    Elf64_Shdr *shdrs = (Elf64_Shdr *)(map + ehdr->e_shoff);
    if ((strtab = set_strtab(&sym, shdrs, ehdr, map)) == NULL)
        return (-1);
    if (check_elf_64(ehdr) == true) {
        printf("\n%s:     file format elf64-x86-64\n", path);
        objdump_header(ehdr, shdrs, strtab, &sym);
    }
    return (0);
}

int main(int argc, char **argv)
{
    int check_error;
    void *map;

    check_error = 0;
    map = NULL;
    return (check_arguments(argc, argv, check_error, &map));
}