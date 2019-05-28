/*
** EPITECH PROJECT, 2019
** strace.c
** File description:
** strace
*/

#include "strace.h"
#include <signal.h>
#include <sys/reg.h>

static int ptrace_instruction_pointer(int pid)
{
    struct user_regs_struct reg;
    syscall_t program;

    if ((ptrace(PTRACE_GETREGS, pid, NULL, &reg) == -1)) {
        fprintf(stderr, "Error fetching registers from child process: %s\n",
        strerror(errno));
        return (-1);
    }
    program = get_name_syscall(&reg);
    result_syscall(&reg, program);
    return (0);
}

static int singlestep(int pid)
{
    int retval, status;
    retval = ptrace(PTRACE_SINGLESTEP, pid, 0, 0);
    if (retval) {
        return retval;
    }
    waitpid(pid, &status, 0);
    return status;
}

int run_ptrace(pid_t pid)
{
    int status;

    waitpid(pid, &status, 0);
    while (WIFSTOPPED(status) && (WSTOPSIG(status) == SIGTRAP
    || WSTOPSIG(status) == SIGSTOP)) {
        if ((ptrace_instruction_pointer(pid) == -1))
            exit(1);
        status = singlestep(pid);
    }
    ptrace(PTRACE_DETACH, pid, 0, 0);
    return (fprint_wait_status(status));
}

int run_ptrace_p(pid_t pid)
{
    int status;

    if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1) {
        fprintf(stderr, "No such pid %d\n", pid);
        exit(1);
    }
    waitpid(pid, &status, 0);
    while (WIFSTOPPED(status) && (WSTOPSIG(status) == SIGTRAP
    || WSTOPSIG(status) == SIGSTOP)) {
        if ((ptrace_instruction_pointer(pid) == -1))
            exit(1);
        status = singlestep(pid);
    }
    ptrace(PTRACE_DETACH, pid, 0, 0);
    return (fprint_wait_status(status));
}

int strace(char **argv, char **envp, char *program)
{
    pid_t pid;
    const char *execute = (const char *)program;
    int return_code;

    if (check_pid(&pid) == -1)
        return (-1);
    if (pid == 0) {
        if ((ptrace(PTRACE_TRACEME, 0, 0, 0) == -1)) {
            fprintf(stderr, "Error setting TRACEME: %s\n", strerror(errno));
            return (-1);
        }
        execve(execute, argv, envp);
    }
    return_code = run_ptrace(pid);
    fprintf(stderr, "+++ exited with %d +++\n", return_code);
    return (return_code);
}