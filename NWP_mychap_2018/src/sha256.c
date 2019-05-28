/*
** EPITECH PROJECT, 2019
** sha256.c
** File description:
** sha256
*/

#include "mychap.h"
#include <openssl/sha.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sha256(const char *str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH] = { 0 };
    SHA256_CTX sha256;
    char *output_buffer;

    if (!(output_buffer = calloc(1,
              sizeof(char) * ((SHA256_DIGEST_LENGTH * 2) + 1))))
        return (NULL);
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str, strlen(str));
    SHA256_Final(hash, &sha256);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(output_buffer + (i * 2), "%02x", hash[i]);
    output_buffer[64] = 0;
    return (output_buffer);
}