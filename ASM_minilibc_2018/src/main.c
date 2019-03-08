#include <stdio.h>
#include <string.h>

size_t  _strlen(char *);
size_t _strnlen(const char *, size_t );

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(void)
{
    char str[] = "Hello World!";

    printf("MOULINETTE MAISON: \n\n");

    // Strlen
    printf(ANSI_COLOR_RED "Strlen System: %ld\n" ANSI_COLOR_RESET, strlen(str));
    printf(ANSI_COLOR_GREEN "Strlen Lib: %ld\n"ANSI_COLOR_RESET, _strlen(str));

    // Strnlen
    printf(ANSI_COLOR_RED "Strnlen System: %ld\n"ANSI_COLOR_RESET, strnlen(str, 5));
    printf(ANSI_COLOR_GREEN "Strnlen Lib: %ld\n"ANSI_COLOR_RESET, _strnlen(str, 5));
    return 0;
}