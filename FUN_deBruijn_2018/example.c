#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNS 200000
typedef unsigned int uint;

uint num = 0, /* # sequences */
    *C, /* De Bruijn sequence */
    N, /* word length */
    P, /* alphabet length */
    M, NS; /* # words NS = P^N, M = P^(N-1) */
char *W, /* words, vertices (ham.) edges (Euler) */
    *A; /* alphabet */
void next(uint n, uint i)
{ /* next word */
    uint j, k, r, s;
    r = n / P;
    C[i] = n / M, W[n] = (char)0;
    if (i < NS - 1) {
        for (k = 0; k < P; k++) {
            s = r + k * M;
            if (W[s])
                next(s, i + 1);
        }
    } else {
        num++;
        for (j = 0; j < NS; j++)
            printf("%c", A[C[j]]);
        printf("\n");
#ifdef ONE
        exit(0); // only one
#endif
    }
    W[n] = (char)1;
}

int main(int argc, char *argv[])
{
    uint i;
    if (argc < 3)
        printf("usage: debruijn wordlen alphabet\n"), exit(0);
    N = atoi(argv[1]), P = strlen(argv[2]), A = argv[2];
    for (NS = 1, i = 0; i < N && NS <= MAXNS; NS *= P, i++)
        ;
    if (i < N - 1 || NS > MAXNS)
        printf("too long\n"), exit(1);
    M = NS / P;
    printf("# De Bruijn sequences\n# letters %d  alphabet \"%s\"\n", N, A);
    printf("# Word length %d\n", NS);
    if ((W = (char *)malloc(NS * sizeof(char))) == NULL)
        printf("malloc 1 fails\n"), exit(1);
    memset((void *)W, (char)1, NS);
    for (i = 0; i < NS; W[i] = (char)1, i++)
        ;
    if ((C = (uint *)malloc(NS * sizeof(uint))) == NULL)
        printf("malloc 2 fails\n"), exit(1);
    next(0, 0);
    //  printf("# %d sequences\n",num);
}