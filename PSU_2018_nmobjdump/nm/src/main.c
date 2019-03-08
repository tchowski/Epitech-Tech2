/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "nm.h"
#include <sys/stat.h>

int init_elf(char *argv, void **map)
{
    int fd;
    size_t len;

    fd = open(argv, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "./my_nm: \"%s\": No such file\n", argv);
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
        fprintf(stderr, "./my_nm: \"%s\": No such file\n", path);
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
    char *strtab;

    sym->sym = NULL;
    sym->tabsize = 0;
    strs = (char *)(map + shdrs[ehdr->e_shstrndx].sh_offset);
    for (int i = 0; i < ehdr->e_shnum; i++) {
        if (strcmp(strs + shdrs[i].sh_name, ".strtab") == 0) {
            strtab = (map + shdrs[i].sh_offset);
        }
        if (strcmp(strs + shdrs[i].sh_name, ".symtab") == 0) {
            sym->sym = (Elf64_Sym *)(map + shdrs[i].sh_offset);
            sym->tabsize = shdrs[i].sh_size / sizeof(Elf64_Sym);
        }
    }
    if (strtab)
        return (strtab);
    fprintf(stderr, "No .strtab");
    return (NULL);
}

int run_elf(char *map, char *path, int argc)
{
    char *strtab;
    t_sym sym;
    list_p *list;

    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)map;
    if (check_elf(ehdr) == -1) {
        fprintf(stderr, "my_nm: %s: File format not recognized\n", path);
        return (-1);
    }
    if (argc > 2)
        printf("\n%s:\n", path);
    Elf64_Shdr *shdrs = (Elf64_Shdr *)(map + ehdr->e_shoff);
    if ((strtab = set_strtab(&sym, shdrs, ehdr, map)) == NULL)
        return (-1);
    list = get_symbol_by_list(&sym, shdrs, strtab);
    list_to_array(list);
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