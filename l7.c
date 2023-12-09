#include <stdio.h>

#define SIZE 100

void p1()
{
    int a, b, *max;
    scanf("%d %d", &a, &b);
    if (a > b)
    {
        max = &a;
    }
    else
    {
        max = &b;
    }
    printf("%d\n", *max);
}

void citire(int v[], int *size)
{
    int i = 0;
    while ((i < *size) && (scanf("%d", v + i) == 1))
    {
        i++;
    }
    *size = i;
}

void afisare(int v[], int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        printf("%d ", *(v + i));
    }
    printf("\n");
}

int egal(int v1[], int v2[], int size)
{
    int i, ok = 1;
    for (i = 0; i < size - 1; i++)
    {
        if (*(v1 + i) != *(v2 + i))
        {
            ok = 0;
        }
    }
    return ok;
}

void p2()
{
    int v1[100], v2[100], size = SIZE;
    citire(v1, &size);
    citire(v2, &size);
    if (egal(v1, v2, size) == 1)
    {
        printf("Vectorii sunt egali\n");
    }
    else
    {
        printf("Vectroii sunt diferiti\n");
    }
}

void p3()
{
    double a, b, *n1, *n2;
    scanf("%lf %lf", &a, &b);
    n1 = &a;
    n2 = &b;
    if (n1 < n2)
    {
        printf("a\n");
    }
    else
    {
        printf("b\n");
    }
}

void p4()
{
    int a, b, *n1, *n2, aux;
    scanf("%d %d", &a, &b);
    n1 = &a;
    n2 = &b;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
    printf("%d %d\n", a, b);
}

void p5()
{
    int v[100], size = SIZE, c = 0, i;
    citire(v, &size);
    for (i = 0; i < size; i++)
    {
        if (*(v + i) < 0)
        {
            c++;
        }
    }
    printf("%d\n", c);
}

void p6()
{
    int v[100], size = SIZE, min, i;
    citire(v, &size);
    min = *v;
    for (i = 0; i < size; i++)
    {
        if (*(v + i) < min)
        {
            min = *(v + i);
        }
    }
    printf("%d\n", min);
}

void p7()
{
    int v[10], size, i, j, aux;
    scanf("%d", &size);
    citire(v, &size);
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (*(v + i) < *(v + j))
            {
                aux = *(v + i);
                *(v + i) = *(v + j);
                *(v + j) = aux;
            }
        }
    }
    afisare(v, size);
}

void p8()
{
    int v[10], size = 10, i, j;
    citire(v, &size);
    for (i = 0; i < size; i++)
    {
        if (*(v + i) % 2 == 0)
        {
            for (j = i; j < size - 1; j++)
            {
                *(v + j) = *(v + j + 1);
            }
            size--;
            i = i - 2;
        }
    }
    afisare(v, size);
}

void p9()
{
    int v[20], size = 20, i, j;
    citire(v, &size);
    for (i = 0; i < size; i++)
    {
        size++;
        for (j = size; j > i; j--)
        {
            *(v + j) = *(v + j - 1);
        }
        *(v + i) = -*(v + i + 1);
        i = i + 1;
    }
    afisare(v, size);
}

void p10()
{
    int v[10], size = 10, i, j, k;
    citire(v, &size);
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (*(v + i) == *(v + j))
            {
                for (k = j; k < size - 1; k++)
                {
                    *(v + k) = *(v + k + 1);
                }
                size--;
                i = i - 2;
            }
        }
    }
    afisare(v, size);
}

void stergere(int *v, int *size, int val)
{
    int i, j;
    for (i = 0; i < *size; i++)
    {
        if (*(v + i) == val)
        {
            for (j = i; j < *size; j++)
            {
                v[j] = v[j + 1];
            }
            *size -= 1;
            i--;
        }
    }
}

void p11()
{
    int optiune = 0, v[100], size = 100, valoare;
    while (optiune != 4)
    {
        printf("1. Citire - citește o valoare reală și o adaugă într-un vector cu maxim 100 de elemente\n");
        printf("2. Afișare - afișează toate valorile din vector\n");
        printf("3. Ștergere - citește o valoare și șterge toate elementele egale cu valoarea citită\n");
        printf("4. Ieșire\n");
        printf("Introdu optiunea: ");
        scanf("%d", &optiune);
        switch (optiune)
        {
        case 1:
        {
            citire(v, &size);
            break;
        }
        case 2:
        {
            afisare(v, size);
            break;
        }
        case 3:
        {
            printf("Introdu valoarea pe care vrei sa o stergi: ");
            scanf("%d", &valoare);
            stergere(v, &size, valoare);
        }
        case 4:
        {
            break;
        }
        default:
        {
            printf("Ai introdus o optiune invalida !\n");
            break;
        }
        }
    }
}

void p12()
{
    int v[100], size = 100, x, i = 0, j, k, ok;
    scanf("%d", &x);
    *(v + i) = x;
    i++;
    while (x != 0 && i < size)
    {
        scanf("%d", &x);
        ok = 0;
        if (x > *(v + i - 1) && x != 0)
        {
            *(v + i) = x;
        }
        else
        {
            if (x != 0)
            {
                for (j = i - 1; j >= 0; j--)
                {
                    if (*(v + j) < x)
                    {
                        for (k = i; k > j + 1; k--)
                        {
                            *(v + k) = *(v + k - 1);
                        }
                        *(v + j + 1) = x;
                        ok = 1;
                        break;
                    }
                }
                if (ok == 0)
                {
                    for (j = i; j > 0; j--)
                    {
                        *(v + j) = *(v + j - 1);
                    }
                    v[0] = x;
                }
            }
        }
        i++;
    }
    size = i - 1;
    afisare(v, size);
}

int main(void)
{
    // p1();
    // p2();
    // p3();
    // p4();
    // p5();
    // p6();
    // p7();
    // p8();
    // p9();
    // p10();
    p11();
    // p12();
    return 0;
}