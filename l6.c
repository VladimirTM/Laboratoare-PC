#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define SIZE 100000
#define MAX 10000

void printf8(u_int8_t n)
{
    u_int8_t m = 1 << 7;
    for (int i = 0; i < 8; i++)
    {
        if ((n & m) == 0)
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

void printfV(int *v, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int p1(u_int16_t n)
{
    int contor = 0, curentBit, anteriorBit;
    anteriorBit = n & 1;
    n = n >> 1;
    while (n)
    {
        curentBit = n & 1;
        if (curentBit != anteriorBit)
        {
            printf("%d %d\n", curentBit, anteriorBit);
            contor++;
        }
        anteriorBit = curentBit;
        n = n >> 1;
    }
    return contor;
}

int p2(int *v, int size)
{
    int min = v[0], i;
    for (i = 0; i < size; i++)
    {
        if (v[i] < min)
        {
            min = v[i];
        }
    }
    return min;
}

void p3()
{
    int n, v[11], i, ok = 1;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (v[i] > 0 && v[i] % 2 != 0)
        {
            ok = 0;
            break;
        }
    }
    if (ok)
    {
        printf("Numerele citite sunt ok");
    }
    else
    {
        printf("Numerele citite nu sunt ok");
    }
}

void p4(int *v, int size)
{
    int k, ok = 0, i;
    scanf("%d", &k);
    for (i = 0; i < size; i++)
    {
        if (v[i] > k)
        {
            ok = 1;
        }
    }
    if (ok == 1)
    {
        printf("Exista");
    }
    else
    {
        printf("Nu exista");
    }
}

void p5(int *v, int size)
{
    int x, y, m[10], minim, i, j = 0;
    scanf("%d %d", &x, &y);
    for (i = 0; i < size; i++)
    {
        if ((x <= v[i]) && (v[i] <= y))
        {
            m[j] = v[i];
            j++;
        }
    }
    minim = m[0];
    for (i = 0; i < j; i++)
    {
        if (m[i] < minim)
        {
            minim = m[i];
        }
    }
    printf("%d\n", minim);
}

void p6()
{
    int n, v[6], i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (abs(v[i]) > 10)
        {
            printf("%d\n", v[i]);
        }
    }
}

void p7()
{
    int n, v[11], i, j, aux;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (v[j] % 2 == 0 && v[j + 1] % 2 != 0)
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
    printfV(v, n);
}

void p8()
{
    int n, v[11], i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        if (v[i] < v[i + 1])
        {
            for (j = i; j < n; j++)
            {
                v[j] = v[j + 1];
            }
            n--;
            i--;
        }
    }
    printfV(v, n);
}

void p9()
{
    int n, v[22], i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (v[i] % 2 != 0)
        {
            for (j = n; j > i; j--)
            {
                v[j] = v[j - 1];
            }
            v[i] = 0;
            i++;
            n++;
        }
    }
    printfV(v, n);
}

void p10()
{
    int n, v[22], i, j, aux;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    printfV(v, n);
}

void p11()
{
    int n, v[22], i, j, k;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (v[i] == v[j])
            {
                for (k = j; k < n; k++)
                {
                    v[k] = v[k + 1];
                }
                n--;
            }
        }
    }
    printfV(v, n);
}

void p12()
{
    int n, v[22], i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; i = i + 2)
    {
        n++;
        for (j = n; j > i; j--)
        {
            v[j] = v[j - 1];
        }
        v[i + 1] = v[i] * v[i];
    }
    printfV(v, n);
}

void p13()
{
    int n, v[44], i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; i = i + 4)
    {
        n = n + 2;
        for (j = n - 1; j > i + 1; j--)
        {
            v[j] = v[j - 2];
        }
        v[i + 2] = v[i] + v[i + 1];
        v[i + 3] = v[i] * v[i + 1];
    }
    printfV(v, n);
}

int main(void)
{
    // printf("%d\n", p1(0b00100));
    //  printf("%d\n", p1(123));
    //  int v[] = {7, -5, 4, 3, -9, 2, -8};
    //  int size = 7;
    //  printf("%d\n", p2(v, size));
    //  p3();
    //  p4(v, size);
    //  p5(v, size);
    //  p6();
    //  p7();
    //  p8();
    //  p9();
    //  p10();
    //  p11();
    //  p12();
    //  p13();
    return 0;
}