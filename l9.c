#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

void p1()
{
    int i;
    char text[100];
    if (fgets(text, 100, stdin) != NULL)
    {
        if (isalpha(text[0]))
        {
            text[0] = toupper(text[0]);
        }
        for (i = 1; i < strlen(text); i++)
        {
            if (!(isalpha(text[i - 1])) && isalpha(text[i]))
            {
                text[i] = toupper(text[i]);
            }
        }
    }
    printf("%s\n", text);
}

void p2()
{
    int n, i, lungime_maxima = 0, lungime_curenta, j;
    char vector_de_nume[10][100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%99s", vector_de_nume[i]);
    }
    for (i = 0; i < n; i++)
    {
        lungime_curenta = 0;
        for (j = 0; j < strlen(vector_de_nume[i]); j++)
        {
            if (isalpha(vector_de_nume[i][j]))
            {
                lungime_curenta++;
            }
        }
        if (lungime_curenta > lungime_maxima)
        {
            lungime_maxima = lungime_curenta;
        }
    }
    for (i = 0; i < n; i++)
    {
        lungime_curenta = strlen(vector_de_nume[i]);
        if (lungime_curenta == lungime_maxima)
        {
            printf("%s %d\n", vector_de_nume[i], lungime_maxima);
            break;
        }
    }
}

void p3()
{
    int n, i, j, k, aparitii;
    char vector_de_nume[10][100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%99s", vector_de_nume[i]);
    }
    for (i = 0; i < n; i++)
    {
        aparitii = 1;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(vector_de_nume[i], vector_de_nume[j]) == 0)
            {
                aparitii++;
                for (k = j; k < n; k++)
                {
                    strcpy(vector_de_nume[k], vector_de_nume[k + 1]);
                }
                n--;
                j--;
            }
        }
        printf("%s %d\n", vector_de_nume[i], aparitii);
    }
}

void p4()
{
    int a[26] = {0}, A[26] = {0}, i;
    char text[100];
    if (fgets(text, 100, stdin) != NULL)
    {
        for (i = 0; i < strlen(text); i++)
        {
            if (isalpha(text[i]) && islower(text[i]))
            {
                a[text[i] - 'a']++;
            }
            else
            {
                if (isalpha(text[i]) && isupper(text[i]))
                {
                    A[text[i] - 'A']++;
                }
            }
        }
        for (i = 0; i < 26; i++)
        {
            printf("Litera %c : %d\n", i + 'a', a[i]);
        }
        for (i = 0; i < 26; i++)
        {
            printf("Litera %c : %d\n", i + 'A', A[i]);
        }
    }
}

void p5()
{
    int n, i;
    char vector_de_nume[10][100], text[1000] = "";
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%99s", vector_de_nume[i]);
    }
    for (i = 0; i < n - 2; i++)
    {
        strcat(text, vector_de_nume[i]);
        strcat(text, ", ");
    }
    strcat(text, vector_de_nume[i]);
    strcat(text, " si ");
    strcat(text, vector_de_nume[++i]);
    strcat(text, " invata.");
    printf("%s\n", text);
}

void p6()
{
    int n, i, j, k;
    char vector_de_produse[10][100];
    float cantitate[10], pret[10], pret_global = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%99s", vector_de_produse[i]);
        scanf("%f", &cantitate[i]);
        scanf("%f", &pret[i]);
        pret[i] = cantitate[i] * pret[i];
        pret_global += pret[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(vector_de_produse[i], vector_de_produse[j]) == 0)
            {
                cantitate[i] += cantitate[j];
                pret[i] += pret[j];
                for (k = j; k < n; k++)
                {
                    strcpy(vector_de_produse[k], vector_de_produse[k + 1]);
                }
                n--;
                j--;
            }
        }
        printf("%s %.1f, %.1f\n", vector_de_produse[i], cantitate[i], pret[i]);
    }
    printf("Pret global: %.1f\n", pret_global);
}

int my_strcmp(char *s1, char *s2)
{
    int l1, l2, i;
    l1 = strlen(s1);
    l2 = strlen(s2);
    if (l1 > l2)
    {
        return 1;
    }
    else
    {
        if (l1 < l2)
        {
            return -1;
        }
        else
        {
            for (i = 0; i < l1; i++)
            {
                if (s1[i] > s2[i])
                {
                    return 1;
                }
                else
                {
                    if (s1[i] < s2[i])
                    {
                        return -1;
                    }
                }
            }
        }
    }
    return 0;
}

uint32_t upper_sub_string(char *str, const char *substr)
{
    uint32_t contor = 0;
    int i, j, ok;
    for (i = 0; i < strlen(str); i++)
    {
        ok = 1;
        if (str[i] == substr[0])
        {
            for (j = 0; j < strlen(substr) && (i + j) < strlen(str); j++)
            {
                if (str[i + j] != substr[j])
                {
                    ok = 0;
                }
            }
            if (ok == 1)
            {
                contor++;
                for (j = 0; j < strlen(substr) && (i + j) < strlen(str); j++)
                {
                    str[i + j] = toupper(str[i + j]);
                }
            }
        }
    }
    printf("%s\n", str);
    return contor;
}
uint32_t string_replace(char *where, const char *what, const char *replace)
{
    uint32_t contor = 0;
    int i, j, ok;
    char aux[100] = "", new_text[100] = "";
    strcpy(aux, where);
    for (i = 0; i < strlen(where); i++)
    {
        ok = 1;
        if (where[i] == what[0])
        {
            for (j = 0; j < strlen(what) && (i + j) < strlen(where); j++)
            {
                if (where[i + j] != what[j])
                {
                    ok = 0;
                }
            }
            if (ok == 1)
            {
                contor++;
                strncat(new_text, where, i);
                strcat(new_text, replace);
                strcpy(aux, where + i + j);
                strcpy(where, aux);
                i = 0;
            }
        }
    }
    strcat(new_text, where);
    strcpy(where, new_text);
    printf("%s\n", where);
    return contor;
}
void p10()
{
    char vector_de_produse[100][15];
    float pret[100], pret_maxim;
    int i = 0, n;
    while (scanf("%s %f", vector_de_produse[i], &pret[i]) == 2)
    {
        i++;
    }
    n = i;
    for (i = 0; i < n; i++)
    {
        if (pret[i] > pret_maxim)
        {
            pret_maxim = pret[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (pret[i] == pret_maxim)
        {
            printf("%s\n", vector_de_produse[i]);
        }
    }
}

int main(void)
{
    // p1();
    // p2();
    // p3();
    // p4();
    // p5();
    // p6();
    // char s1[1000] = "Acesta este un string si un string este terminat cu 0x00";
    // char s2[] = "string";
    // char s3[] = "sir de caractere";
    // printf("%d\n", upper_sub_string(s1, s2));
    // printf("%d\n", string_replace(s1, s2, s3));
    // p10();
    return 0;
}