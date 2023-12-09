#include <stdio.h>
#include <ctype.h>

void p1()
{
    int contor = 0, oglindit = 0;
    char c, a;
    a = getchar();
    while ((c = getchar()) != EOF)
    {
        if (isalpha(a) && ((c == '\t') || (c == ' ') || (c == '\n')))
        {
            contor++;
        }
        a = c;
    }
    if (isalpha(a))
    {
        contor++;
    }
    while (contor != 0)
    {
        oglindit = oglindit * 10 + contor % 10;
        contor = contor / 10;
    }
    while (oglindit != 0)
    {
        putchar((oglindit % 10) + '0');
        oglindit = oglindit / 10;
    }
    putchar('\n');
}

void p2()
{
    char c, a;
    a = getchar();
    while ((c = getchar()) != EOF)
    {
        if (a == '/' && c == '/')
        {
            while ((c = getchar()) != '\n' && c != EOF)
            {
                a = c;
            }
        }
        else
        {
            if (a == '/' && c == '*')
            {
                while ((c = getchar()) != EOF && a != '*' && c != '/')
                {
                    a = c;
                }
            }
        }
        if (c != EOF && c != '/' && c != '*')
        {
            putchar(c);
        }
        a = c;
    }
    putchar('\n');
}

void p3()
{
    int a[26] = {0}, A[26] = {0}, i, dif, s = 0;
    float procent;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (isalpha(c))
        {
            if (islower(c))
            {
                dif = c - 'a';
                a[dif]++;
                s++;
            }
            else
            {
                if (isupper(c))
                {
                    dif = c - 'A';
                    A[dif]++;
                    s++;
                }
            }
        }
    }
    for (i = 0; i < 26; i++)
    {
        c = 'a' + i;
        procent = ((float)a[i] / s) * 100;
        printf("%c: %.2f%%\n", c, procent);
    }
    for (i = 0; i < 26; i++)
    {
        c = 'A' + i;
        procent = ((float)A[i] / s) * 100;
        printf("%c: %.2f%%\n", c, procent);
    }
}

void p4()
{
    char c;
    while ((c = getchar()) != EOF)
    {
        if (isalpha(c))
        {
            if (isupper(c))
            {
                c = tolower(c);
            }
            else
            {
                if (islower(c))
                {
                    c = toupper(c);
                }
            }
        }
        putchar(c);
    }
    putchar('\n');
}

void p5()
{
    char c, a;
    int nr_cuvinte = 0, nr_linii = 0, nr_caractere = 0;
    a = getchar();
    while ((c = getchar()) != EOF)
    {
        if (isalpha(a) && ((c == '\t') || (c == ' ') || (c == '\n')))
        {
            nr_cuvinte++;
        }
        if (c == '\n')
        {
            nr_linii++;
        }
        a = c;
        nr_caractere++;
    }
    if (isalpha(a))
    {
        nr_cuvinte++;
    }
    nr_linii++;
    nr_caractere++;
    printf("%7d%7d%7d", nr_linii, nr_cuvinte, nr_caractere);
}

void p6()
{
    char a, c;
    int nr_cuvinte = 0, nr_linii = 0;
    a = getchar();
    while ((c = getchar()) != EOF)
    {
        if (((isalnum(a)) || a == '.' || a == '_') && ((c == '\t') || (c == ' ') || (c == '\n')))
        {
            nr_cuvinte++;
        }
        if (c == '\n')
        {
            nr_linii++;
        }
    }
    if (((isalnum(a)) || a == '.' || a == '_'))
    {
        nr_cuvinte++;
    }
    nr_linii++;
    printf("%7d %7d\n", nr_cuvinte, nr_linii);
}

void p7()
{
    char a, c;
    int nr_cuvinte = 0, nr_cuvinte_rand = 0, max_nr_cuvinte = 0;
    a = getchar();
    if (isalpha(a))
    {
        a = toupper(a);
        putchar(a);
    }
    while ((c = getchar()) != EOF)
    {
        if (((a == '\t') || (a == ' ') || (a == '\n')) && isalpha(c))
        {
            c = toupper(c);
        }
        if (isalpha(a) && ((c == '\t') || (c == ' ') || (c == '\n')))
        {
            nr_cuvinte++;
            nr_cuvinte_rand++;
        }
        if (c == '\n')
        {
            if (nr_cuvinte_rand > max_nr_cuvinte)
            {
                max_nr_cuvinte = nr_cuvinte_rand;
            }
            nr_cuvinte_rand = 0;
        }
        putchar(c);
        a = c;
    }
    if (isalpha(a))
    {
        nr_cuvinte++;
        nr_cuvinte_rand++;
        if (nr_cuvinte_rand > max_nr_cuvinte)
        {
            max_nr_cuvinte = nr_cuvinte_rand;
        }
    }
    putchar('\n');
    printf("Numar cuvinte: %d\nNumar maxim de cuvinte pe rand: %d\n", nr_cuvinte, max_nr_cuvinte);
}

void p8()
{
    char a, c;
    int nr_tag_d = 0, nr_tag_i = 0;
    a = getchar();
    while ((c = getchar()) != EOF)
    {
        if (a == '<' && c != '/')
        {
            nr_tag_d++;
        }
        if (a == '<' && c == '/')
        {
            nr_tag_i++;
        }
        a = c;
    }
    printf("Numar taguri deschise: %d\nNumar taguri inchise: %d\n", nr_tag_d, nr_tag_i);
}

int main(void)
{
    // p1();
    //  p2();
    //  p3();
    // p4();
    // p5();
    // p6();
    // p7();
    // p8();
    return 0;
}