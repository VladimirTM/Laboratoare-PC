#include <stdio.h>
#include <stdint.h>

void printf8(uint8_t nr)
{
    uint8_t m = 1 << 7;
    uint8_t i;
    for (i = 0; i < 8; i++)
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

void printf16(uint16_t nr)
{
    uint16_t m = 1 << 15;
    uint8_t i;
    for (i = 0; i < 16; i++)
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

void printf32(uint32_t nr)
{
    uint32_t m = 1 << 31;
    uint8_t i;
    for (i = 0; i < 32; i++)
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

void printf64(uint64_t nr)
{
    uint64_t m = (uint64_t)1 << 63;
    uint8_t i;
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

void p8(uint8_t nr)
{
    printf8(nr);
    uint8_t i;
    for (i = 0; i < 8; i++)
    {
        switch (i)
        {
        case 0:
        case 2:
        case 3:
        {
            nr = nr | (1 << i);
            break;
        }
        case 1:
        case 5:
        case 6:
        {
            nr = nr & ~(1 << i);
            break;
        }
        case 4:
        case 7:
        {
            nr = nr ^ (1 << i);
            break;
        }
        }
    }
    printf8(nr);
}

void p9(uint8_t n1, uint8_t n2)
{
    uint8_t nr;
    nr = n1 << 4;
    nr = nr | n2;
    printf8(nr);
}

void p10(uint8_t n)
{
    printf8(n);
    uint8_t bitSemn;
    bitSemn = n >> 7;
    bitSemn = bitSemn & 1;
    printf("%d\n", bitSemn);
}

void p11(uint8_t n)
{
    uint8_t s = 0, i;
    for (i = 0; i < 4; i++)
    {
        s = s + (n & 1);
        n = n >> 1;
    }
    printf("%d\n", s);
}

void p13(uint8_t n)
{
    uint8_t i, contor = 0;
    for (i = 0; i < 8; i++)
    {
        if ((n & 1) != 0)
        {
            contor++;
        }
        n = n >> 1;
    }
    printf("%d\n", contor);
}

uint8_t invers(uint8_t nr)
{
    uint8_t invers = 0;
    while (nr)
    {
        invers = invers | (nr & 1);
        nr = nr >> 1;
        invers = invers << 1;
    }
    return invers;
}

void p14(uint8_t n)
{
    uint8_t n1, n2, nr;
    n1 = invers(n >> 4);
    n2 = invers(n << 4);
    nr = n2 | n1;
    printf8(nr);
}

void p15(int n)
{
    int contor = 2, curent, anterior;
    anterior = n & 1;
    n = n >> 1;
    while (n)
    {
        curent = n & 1;
        if (curent != anterior)
        {
            contor++;
        }
        anterior = curent;
        n = n >> 1;
    }
    printf("%d\n", contor);
}

void p16(int a, int b)
{
    int suma, rest;
    while (b)
    {
        suma = a ^ b;
        rest = a & b;
        a = suma;
        b = rest << 1;
    }
    printf("%d\n", suma);
}

void p17(int a, int b)
{
    int diferenta, rest;
    while (b)
    {
        diferenta = a ^ b;
        rest = ~a & b;
        a = diferenta;
        b = rest << 1;
    }
    printf("%d\n", diferenta);
}

void p18(uint32_t nr, uint8_t n, int p)
{
    printf32(nr);
    uint32_t a, b;
    a = nr >> 8 * (p + 1);
    a = a << 8;
    a = a | n;
    a = a << 8 * p;
    b = nr << 8 * p;
    b = b >> 8 * p;
    a = a | b;
    printf32(a);
}

void p19(uint64_t nr, uint8_t n, int p)
{
    printf64(nr);
    uint64_t a, b;
    a = nr >> 8 * (p + 1);
    a = a << 8;
    a = a | n;
    a = a << 8 * p;
    b = nr << 8 * p;
    b = b >> 8 * p;
    a = a | b;
    printf64(a);
}

void p20(uint8_t n1, uint8_t n2)
{
    uint16_t nr;
    nr = n2 << 8;
    nr = nr | n1;
    printf16(nr);
}

uint32_t p21(uint8_t n3, uint8_t n2, uint8_t n1, uint8_t n0)
{
    uint32_t nr;
    nr = n3 << 8 * 3;
    nr = nr | (n2 << 8 * 2);
    nr = nr | (n1 << 8);
    nr = nr | n0;
    return nr;
}

void p22(uint8_t n7, uint8_t n6, uint8_t n5, uint8_t n4, uint8_t n3, uint8_t n2, uint8_t n1, uint8_t n0)
{
    uint64_t nr;
    nr = p21(n7, n6, n5, n4);
    nr = nr << 8 * 4;
    nr = nr | p21(n3, n2, n1, n0);
    printf64(nr);
}

int main(void)
{
    /*
    p8(123);
    p9(1,1);
    p10(-23);
    p11(123);
    p13(123);
    p14(123);
    p15(123);
    p16(4,6);
    p17(6,4);
    p18(911947355,239,2);
    p19(911947355,239,2);
    p20(0b11001011, 0b01100111);
    printf32(p21(0b11110000, 0b00111100, 0b10100011, 0b00101101));
    p22(0b11110000, 0b00111100, 0b10100011, 0b00101101, 0b11110000, 0b00111100, 0b10100011, 0b00101101);
    */
    return 0;
}