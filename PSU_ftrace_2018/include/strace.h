/*
** EPITECH PROJECT, 2019
** strace.h
** File description:
** strace
*/

#ifndef STRACE_H_
#define STRACE_H_

#include <elf.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <syscall.h>
#include <unistd.h>

typedef struct sym {
    Elf64_Sym *sym;
    size_t tabsize;
} t_sym;

typedef struct syscall_s {
    unsigned int id;
    char *name;
    int nb_args;
} syscall_t;

int init_elf_out(char *path, void **map);
int init_elf(char *argv, void **map);
int run_elf(char *map, char *path, int argc);
int strace(char **argv, char **envp, char *program);
int check_elf(Elf64_Ehdr *ehdr);
int check_loop_arguments(int argc, char **argv, int check_error, void *map);
int check_arguments(int argc, char **argv, char **envp);
void print_tabs(char **array, int size);
int print_usage(void);
int check_pid(pid_t *pid);
int open_file(char *argv);
int fprint_wait_status(int status);
int run_ptrace(pid_t pid);
int run_ptrace_p(pid_t pid);

syscall_t get_name_syscall(struct user_regs_struct *);
void result_syscall(struct user_regs_struct *regs, syscall_t system);

#endif /* !STRACE_H_ */
