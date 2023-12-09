#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX 100

void pritf64(u_int64_t nr)
{
    u_int64_t m = (u_int64_t)1 << 63;
    int i;
    for (i = 0; i < 64; i++)
    {
        if ((nr & m) == 0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
        m = m >> 1;
    }
    printf("\n");
}

void p1(u_int64_t nr)
{
    pritf64(nr);
    u_int64_t msb = 0, lsb = 0;
    int i, d;
    for (i = 0; i < 64; i++)
    {
        d = nr & (1 << i);
        if (i % 2 == 0)
        {
            lsb = lsb | (d >> i / 2);
        }
        else
        {
            msb = msb | (d >> i / 2);
        }
    }
    nr = (msb << 32) | lsb;
    pritf64(nr);
}

void citeste_numar(int *v, int *size, int max)
{
    int i = 0, nr;
    nr = rand() % 100;
    while (nr != 0 && i < max)
    {
        *(v + i) = nr;
        i++;
        nr = rand() % 100;
    }
    *size = i;
}

void printfArray(int *v, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", *(v + i));
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void p2(int *v, int size)
{
    int i, j, vali, valj;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            vali = *(v + i);
            valj = *(v + j);
            if (valj % 3 == 0 && (vali % 3 == 1 || vali % 3 == 2))
            {
                swap(v + i, v + j);
                // printfArray(v, size);
            }
            else
            {
                if (valj % 3 == 1 && vali % 3 == 2)
                {
                    swap(v + i, v + j);
                    // printfArray(v, size);
                }
            }
        }
    }
}

void p3a(char *text)
{
    char ant[100] = "", *p;
    p = strtok(text, "/");
    while (p != NULL)
    {
        strcpy(ant, p);
        p = strtok(NULL, "/");
    }
    printf("%s\n", ant);
}

void p3b(char *text)
{
    if (text[0] == '/')
    {
        text = text + 1;
    }
    char ant[100] = "", *p, aux[100] = "";
    p = strchr(text, '/');
    while (p != NULL)
    {
        p = p + 1;
        strcpy(ant, p);
        strcpy(aux, p);
        strcpy(text, aux);
        p = strchr(text, '/');
    }
    printf("%s\n", ant);
}

int main(void)
{
    // p1(0b1010);
    // int tab[MAX], size;
    // srand(time(NULL));
    // citeste_numar(tab, &size, MAX);
    // p2(tab, size);
    // printfArray(tab, size);
    // char text[MAX], c;
    // int i = 0;
    // while(((c = getchar()) != EOF) && i < MAX)
    // {
    //     text[i] = c;
    //     i++;
    // }
    // text[i] = 0;
    // printf("%s\n", text);
    // p3a(text);
    // p3b(text);
    return 0;
}