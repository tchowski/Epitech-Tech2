/*
** EPITECH PROJECT, 2019
** print_fill.c
** File description:
** print_fill
*/

#include "mychap.h"

void fill_buff(unsigned char *data, int i, int j)
{
    for (j = i - i % 16; j <= i; j++) {
        if (data[j] >= 32 && data[j] <= 128) {
            msg_server[j] = data[j];
        } else {
            msg_server[j] = data[j];
        }
    }
}

void print_data(unsigned char *data, int size_packet)
{
    int i;
    int j = 0;

    for (i = 0; i < size_packet; i++) {
        if (i == size_packet - 1) {
            fill_buff(data, i, j);
        }
    }
}

void print_udp_packet(unsigned char *buffer, int size_packet)
{

    unsigned short iphdrlen;
    struct iphdr *iph = (struct iphdr *)buffer;
    iphdrlen = iph->ihl * 4;
    struct udphdr *udph = (struct udphdr *)(buffer + iphdrlen);

    print_data(buffer + iphdrlen + sizeof udph,
        (size_packet - sizeof udph - iph->ihl * 4));
}
