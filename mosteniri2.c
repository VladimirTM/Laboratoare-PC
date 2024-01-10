#include <stdio.h>
#include <stdlib.h>

void printfBinary(int n)
{
    int m, i;
    for (i = sizeof(n) * 8 - 1; i >= 0; i--)
    {
        m = 1 << i;
        if ((n & m) == 0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
    }
    printf("\n");
}

void p1()
{
    int n, contorSecventa = 0, ant = 0, m, digit, i;
    scanf("%d", &n);
    printfBinary(n);
    for (i = 0; i <= sizeof(n) * 8; i++)
    {
        m = 1 << i;
        digit = n & m;
        if (ant != 0 && digit == 0)
        {
            contorSecventa++;
        }
        ant = digit;
    }
    if (contorSecventa == 1)
    {
        printf("Numarul are biti de 1 continuu\n");
    }
    else
    {
        printf("Numarul nu are biti de 1 continuu\n");
    }
}

int *array0(int size)
{
    int *array = NULL;
    if ((array = calloc(size, sizeof(int))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    return array;
}

int **matrix0(int size)
{
    int **matrix = NULL, i;
    if ((matrix = malloc(size * sizeof(int *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (i = 0; i < size; i++)
    {
        matrix[i] = array0(size);
    }
    return matrix;
}

void printfMatrix(int **matrix, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void p2()
{
    int **matrix, size, nr, i;
    scanf("%d", &size);
    matrix = matrix0(size);
    scanf("%d", &nr);
    while (nr != 0)
    {
        if (abs(nr) <= size)
        {
            if (nr > 0)
            {
                for (i = size - 1; i > 0; i--)
                {
                    matrix[nr - 1][i] = matrix[nr - 1][i - 1];
                }
                matrix[nr - 1][0] = nr;
            }
            else
            {
                nr = -nr;
                for (i = 0; i < size - 1; i++)
                {
                    matrix[i][nr - 1] = matrix[i + 1][nr - 1];
                }
                matrix[size - 1][nr - 1] = nr;
            }
        }
        printfMatrix(matrix, size);
        scanf("%d", &nr);
    }
    printfMatrix(matrix, size);
    for (i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void printfShortInt(short int nr)
{
    short int m, i;
    for (i = sizeof(short int) * 8 - 1; i >= 0; i--)
    {
        m = 1 << i;
        if ((nr & m) == 0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
    }
    // printf("\n");
}

void p3()
{
    short int nr;
    scanf("%hd", &nr);
    while (nr != 0)
    {
        printfShortInt(nr);
        printf(" %0X ", nr);
        if ((nr & 1) != 0 && (nr & (1 << 1)) != 0 && (nr & (1 << 2)) != 0)
        {
            nr = nr | (1 << 1);
            nr = nr | (1 << 3);
            nr = nr | (1 << 4);
            nr = nr | (1 << 5);
        }
        else
        {
            nr = nr | (1 << 0);
            nr = nr | (1 << 1);
            nr = nr | (1 << 2);
        }
        printfShortInt(nr);
        printf(" %0X\n", nr);
        scanf("%hd", &nr);
    }
}

void printfArray(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void p4()
{
    int n, m, *a = NULL, *b = NULL, *c = NULL, i, j = 0, k = 0, l;

    scanf("%d", &n);
    if ((a = malloc(n * sizeof(int))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);
    if ((b = malloc(m * sizeof(int))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    if ((c = malloc((n + m) * sizeof(int))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    i = 0;

    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            c[k] = a[i];
            for (l = i; l < n - 1; l++)
            {
                a[l] = a[l + 1];
            }
            for (l = j; l < m - 1; l++)
            {
                b[l] = b[l + 1];
            }
            n--;
            m--;
            k++;
        }
        else
        {
            if (a[i] < b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }

    printfArray(a, n);
    printfArray(b, m);
    printfArray(c, k);
    free(a);
    free(b);
    free(c);
}

int main(void)
{
    // p1();
    // p2();
    // p3();
    p4();
    return 0;
}