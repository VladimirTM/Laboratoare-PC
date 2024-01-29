#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void printf16(uint16_t numar)
{
    uint16_t m = 1 << 15, i;
    for (i = 0; i < 16; i++)
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

void printf64(uint64_t numar)
{
    uint64_t m = (uint64_t)1 << 63, i;
    for (i = 0; i < 64; i++)
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

uint32_t p1(uint8_t a, uint8_t b)
{
    uint16_t suma, diferenta;
    uint32_t numar;
    suma = a + b;
    diferenta = abs(a - b);
    numar = suma << 16 | diferenta;
    return numar;
}

uint8_t inverse_nibble(uint8_t bit)
{
    uint8_t n1, n0, newBit;
    n1 = bit >> 4;
    n0 = bit << 4;
    newBit = n0 | n1;
    return newBit;
}

void p2(void)
{
    uint32_t numar;
    scanf("%d", &numar);
    uint8_t b3, b2, b1, b0;
    b0 = inverse_nibble(numar & 0xFF);
    b1 = inverse_nibble(numar >> 8);
    b2 = inverse_nibble(numar >> 16);
    b3 = inverse_nibble(numar >> 24);
    numar = b3 << 24 | b2 << 16 | b1 << 8 | b0;
    printf32(numar);
}

uint8_t p3(int n)
{
    uint8_t nrCifre = 0, nrCifrePare = 0, cifra, nouN;
    while (n != 0)
    {
        cifra = n % 10;
        n = n / 10;
        nrCifre++;
        if (cifra % 2 == 0)
        {
            nrCifrePare++;
        }
    }
    nouN = nrCifre << 4 | nrCifrePare;
    return nouN;
}

int min(int a, int b)
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

void p4(void)
{
    int nr, contor = 0;
    uint16_t suma = 0, mediaA, minim = 65535;
    uint32_t rezultat;
    scanf("%d", &nr);
    while (nr != 0)
    {
        minim = min(nr, minim);
        suma = suma + nr;
        contor++;
        scanf("%d", &nr);
    }
    mediaA = suma / contor;
    rezultat = mediaA << 16 | minim;
    printf32(rezultat);
}

uint32_t p5(uint32_t data, int n)
{
    uint8_t zi, luna;
    uint32_t an;
    switch (n)
    {
    case 0:
    {
        zi = data & 0x0F;
        return zi;
    }
    case 1:
    {
        luna = (data >> 4) & 0x0F;
        return luna;
    }
    case 2:
    {
        an = data >> 8;
        return an;
    }
    default:
    {
        return 0;
    }
    }
}

void p6(uint16_t nr, uint8_t n, uint8_t p)
{
    uint16_t i;
    for (i = 0; i < 16; i++)
    {
        if (i >= p && n != 0)
        {
            nr = nr ^ (1 << i);
            n--;
        }
    }
    printf16(nr);
}

uint64_t p7(uint32_t numar)
{
    uint8_t cifra, p = 0;
    uint64_t rezulatat = 0;
    while (numar != 0)
    {
        cifra = numar % 10;
        rezulatat = rezulatat | (cifra << (4 * p));
        numar = numar / 10;
        p++;
    }
    return rezulatat;
}

int main(void)
{
    // uint8_t a, b;
    // scanf("%hhd %hhd", &a, &b);
    // printf32(p1(a,b));
    // p2();
    // int n;
    // scanf("%d", &n);
    // printf("0x%x\n", p3(n));
    // p4();
    // int data, p;
    // scanf("%d %d", &data, &p);
    // printf("%d\n", p5(data, p));
    // uint16_t nr;
    // uint8_t n, p;
    // scanf("%hd %hhd %hhd", &nr, &n, &p);
    // p6(nr, n, p);
    // uint32_t nr;
    // scanf("%d", &nr);
    // printf64(p7(nr));
    return 0;
}