/*
** EPITECH PROJECT, 2019
** fil_up
** File description:
** fil_up
*/

#include "nm.h"

static char upper_or_not_upper(char symbol, Elf64_Sym sym)
{
    if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && symbol != '?')
        symbol += 32;
    return (symbol);
}

char get_type3(Elf64_Shdr *shdrs, Elf64_Sym sym, char symbol)
{
    if (shdrs[sym.st_shndx].sh_type == SHT_NOBITS
        && shdrs[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        symbol = 'B';
    if (shdrs[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdrs[sym.st_shndx].sh_flags == SHF_ALLOC)
        symbol = 'R';
    else if (shdrs[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdrs[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        symbol = 'D';
    else if (shdrs[sym.st_shndx].sh_type == SHT_DYNAMIC)
        symbol = 'D';
    else if (shdrs[sym.st_shndx].sh_type == SHT_PROGBITS
        && shdrs[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        symbol = 'T';
    else if (sym.st_shndx == 19 || sym.st_shndx == 20)
        symbol = 'T';
    return symbol;
}

char get_type2(Elf64_Sym sym, char symbol, char *name_symbol)
{
    if (strncmp("wm4.", name_symbol, 4) == 0)
        return ('n');
    if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
        symbol = 'u';
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK) {
        symbol = 'W';
        if (sym.st_shndx == SHN_UNDEF)
            symbol = 'w';
    } else if (ELF64_ST_BIND(sym.st_info) == STB_WEAK
    && ELF64_ST_TYPE(sym.st_info) == STT_OBJECT) {
        symbol = 'V';
        if (sym.st_shndx == SHN_UNDEF)
            symbol = 'v';
    }
    return symbol;
}

static char get_type1(Elf64_Shdr *shdrs, Elf64_Sym sym, char *name_symbol)
{
    char symbol;

    symbol = '0';
    if (sym.st_shndx == SHN_UNDEF)
        symbol = 'U';
    else if (sym.st_shndx == SHN_ABS)
        symbol = 'A';
    else if (sym.st_shndx == SHN_COMMON)
        symbol = 'C';
    symbol = get_type3(shdrs, sym, symbol);
    symbol = get_type2(sym, symbol, name_symbol);
    symbol = upper_or_not_upper(symbol, sym);
    return symbol;
}

list_p *get_symbol_by_list(t_sym *sym, Elf64_Shdr *shdrs, char *strtab)
{
    t_list *symbol;
    list_p *list;
    char *tmp;

    list = init_list();
    for (size_t i = 0; i < sym->tabsize; i++) {
        if (*(strtab + sym->sym[i].st_name) != '\0') {
            tmp = strtab + sym->sym[i].st_name;
            if (strstr(tmp, ".c") == NULL) {
                symbol = malloc((sizeof(t_list) * sym->tabsize));
                symbol->name_symbol = strtab + sym->sym[i].st_name;
                symbol->virtual_address = sym->sym[i].st_value;
                symbol->type = get_type1(shdrs, sym->sym[i], tmp);
                symbol->next = list->head;
                list->head = symbol;
            }
        }
    }
    return (list);
}