#include <stdio.h>
#include <stdint.h>

#define SIZE 100

void printf32(uint32_t numar)
{
    uint32_t m = 1 << 31, i;
    for (i = 0; i < 32; i++)
    {
        if ((numar & m) == 0)
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

int nrBiti1(int n)
{
    int i, contor = 0;
    for (i = 0; i < 8 * sizeof(int); i++)
    {
        if ((n & (1 << i)) != 0)
        {
            contor++;
        }
    }
    return contor;
}

void scanfArray(int *v, int *size)
{
    int index = 0, nr;
    while ((scanf("%d", &nr) == 1) && (index < *size))
    {
        v[index++] = nr;
    }
    *size = index;
}

void printfArray(int *v, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void p1()
{
    int a[SIZE], b[SIZE], size = SIZE, i, index = 0, sizeB = 0;
    scanfArray(a, &size);
    for (i = 0; i < size; i++)
    {
        if (nrBiti1(a[i]) % 2 == 0)
        {
            b[index++] = a[i];
        }
    }
    sizeB = index;
    printfArray(b, sizeB);
}

// Problema 2 e identica cu prima (int e identic cu uint32_t, deci se poate lasa exact asa)

void p3()
{
    int a[SIZE], size = SIZE, i, contor = 0;
    scanfArray(a, &size);
    for (i = 0; i < size; i = i + 2)
    {
        if (a[i] % 2 != 0)
        {
            contor++;
        }
    }
    printf("%d\n", contor);
}

void scanfArray16(uint16_t *v, uint16_t *size)
{
    uint16_t index = 0, nr;
    while ((scanf("%hd", &nr) == 1) && (index < *size))
    {
        *(v + index) = nr;
        index++;
    }
    *size = index;
}

void printfArray16(uint16_t *v, uint16_t size)
{
    uint16_t i;
    for (i = 0; i < size; i++)
    {
        printf("%hd ", *(v + i));
    }
    printf("\n");
}

uint16_t max16(uint16_t a, uint16_t b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

uint16_t min16(uint16_t a, uint16_t b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void p4()
{
    uint16_t v[SIZE], size = SIZE, i, maxImpar = 0, pozitieMaxImpar;
    uint32_t numar;
    scanfArray16(v, &size);
    for (i = 0; i < size; i++)
    {
        if (*(v + i) % 2 != 0 && *(v + i) > maxImpar)
        {
            maxImpar = *(v + i);
            pozitieMaxImpar = i;
        }
    }
    numar = maxImpar << 16 | pozitieMaxImpar;
    printf32(numar);
}

// Problema 5 este identica cu problema 4

void scanfArrayPointer(int *v, int *size)
{
    int index = 0, nr;
    while ((scanf("%d", &nr) == 1) && (index < *size))
    {
        *(v + index) = nr;
        index++;
    }
    *size = index;
}

void printfArrayPointer(int *v, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", *(v + i));
    }
    printf("\n");
}

void p6()
{
    int a[SIZE], size = SIZE, i, j;
    scanfArrayPointer(a, &size);
    for (i = 0; i < size; i++)
    {
        if (*(a + i) % 3 == 0)
        {
            size = size - 1;
            for (j = i; j < size; j++)
            {
                *(a + j) = *(a + j + 1);
            }
            i--;
        }
    }
    printfArrayPointer(a, size);
}

int main(void)
{
    // p1();
    // p3();
    // p4();
    // p6();
}