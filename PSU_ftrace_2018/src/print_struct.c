/*
** EPITECH PROJECT, 2019
** print_struct.c
** File description:
** print_struct
*/

#include "strace.h"
#include "syscall_list.h"

static void check_args(int index, struct user_regs_struct *regs)
{
    if (index == 1)
        fprintf(stderr, "0x%llx", regs->rdi);
    if (index == 2)
        fprintf(stderr, "0x%llx", regs->rsi);
    if (index == 3)
        fprintf(stderr, "0x%llx", regs->rdx);
    if (index == 4)
        fprintf(stderr, "0x%llx", regs->r8);
    if (index == 5)
        fprintf(stderr, "0x%llx", regs->r9);
    if (index == 6)
        fprintf(stderr, "0x%llx", regs->r10);
    return;
}

syscall_t get_name_syscall(struct user_regs_struct *reg)
{
    for (int i = 0; i < 329; i++) {
        if (reg->orig_rax == syscall_list_s[i].id)
            return (syscall_list_s[i]);
    }
    return (syscall_list_s[329]);
}

void result_syscall(struct user_regs_struct *regs, syscall_t system)
{
    int index;

    index = 1;
    if (system.name && system.id > 0) {
        fprintf(stderr, "%s(", system.name);
        for (; system.nb_args > 0; system.nb_args--) {
            check_args(index, regs);
            if (system.nb_args - 1 > 0)
                fprintf(stderr, ", ");
            index++;
        }
        fprintf(stderr, ") = 0x%llx\n", regs->rax);
    } else
        return;
}