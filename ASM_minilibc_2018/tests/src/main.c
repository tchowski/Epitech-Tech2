#include <stdio.h>
#include <string.h>

size_t _strlen(const char *);
size_t _strnlen(const char *, size_t);
int _strcmp(const char *, const char *);
int _strncmp(const char *, const char *, size_t);
int _memset(void *, int c, size_t);
void *_memcpy(void *str1, const void *str2, size_t n);

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main(void)
{
    const char str[] = "Hello World!";

    printf("\n      MOULINETTE MAISON: \n\n");

    // Strlen
    printf(ANSI_COLOR_RED "Strlen System: %ld\n" ANSI_COLOR_RESET, strlen(str));
    printf(ANSI_COLOR_GREEN "Strlen Lib: %ld\n\n" ANSI_COLOR_RESET, _strlen(str));

    // Strnlen
    printf(ANSI_COLOR_RED "Strnlen System: %ld\n" ANSI_COLOR_RESET, strnlen(str, 5));
    printf(ANSI_COLOR_GREEN "Strnlen Lib: %ld\n\n" ANSI_COLOR_RESET, _strnlen(str, 5));

    // Strcmp
    printf(ANSI_COLOR_RED "Strcmp System: %d\n" ANSI_COLOR_RESET, strcmp(str, "Hello World!"));
    printf(ANSI_COLOR_GREEN "Strcmp Lib: %d\n\n" ANSI_COLOR_RESET, _strcmp(str, "Hello World!"));

    // Strncmp
    printf(ANSI_COLOR_RED "Strncmp System: %d\n" ANSI_COLOR_RESET, strncmp(str, "Hello World!", 5));
    printf(ANSI_COLOR_GREEN "Strncmp Lib: %d\n\n" ANSI_COLOR_RESET, _strncmp(str, "Hello World!", 5));

    // memset
    char str1[] = "J'adore le code";
    memset(str1, '0', 7);
    printf(ANSI_COLOR_RED "Memset System: %s\n" ANSI_COLOR_RESET, str1);
    _memset(str1, '0', 7);
    printf(ANSI_COLOR_GREEN "Memset Lib: %s\n\n" ANSI_COLOR_RESET, str1);

    // memcpy
    char str3[50] = "J'adore le code";
    char str4[50] = "Je fais des test";

    // memcpy(str4, str3, strlen(str3) + 1);
    printf(ANSI_COLOR_RED "Memcpy System: %s\n" ANSI_COLOR_RESET, str4);
    _memcpy(str4, str3, strlen(str3) + 1);
    printf(ANSI_COLOR_GREEN "Memcpy Lib: %s\n\n" ANSI_COLOR_RESET, str4);

    // const char src[50] = "http://www.tutorialspoint.com";
    // char dest[50];
    // strcpy(dest, "Helloooo!!");
    // printf("Before memcpy dest = %s\n", dest);
    // _memcpy(dest, src, 1);
    // printf("After memcpy dest = %s\n", dest);

    return 0;
}