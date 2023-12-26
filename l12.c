#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *concatenatedStrings(char *s1, char *s2)
{
    char *concat = NULL;
    int len = strlen(s1) + strlen(s2) + 2;
    if ((concat = malloc(len * sizeof(char))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    strcpy(concat, "");
    if (strcat(concat, s1) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if (strcat(concat, " ") == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if (strcat(concat, s2) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    return concat;
}

void p1()
{
    char s1[100], s2[100], *concat = NULL;
    if (fgets(s1, 100, stdin) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    s1[strlen(s1) - 1] = 0;
    if (fgets(s2, 100, stdin) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    s2[strlen(s2) - 1] = 0;
    concat = concatenatedStrings(s1, s2);
    printf("%s\n", concat);
    free(concat);
}

void p2()
{
    int numar, *vector = NULL, index = 0, current_size = 0;
    scanf("%d", &numar);
    while (numar != 0)
    {
        if (index == current_size)
        {
            current_size += 1;
            if ((vector = realloc(vector, current_size * sizeof(int))) == NULL)
            {
                perror(NULL);
                exit(-1);
            }
        }
        vector[index++] = numar;
        scanf("%d", &numar);
    }
    current_size = index;
    for (index = current_size - 1; index >= 0; index--)
    {
        printf("%d", vector[index]);
        printf(" ");
    }
    printf("\n");
    free(vector);
}

void p3()
{
    char cuvant[50], *fazan = NULL;
    int size = 0;
    while (scanf("%49s", cuvant) == 1)
    {
        if (size == 0)
        {
            size = strlen(cuvant) + 2;
            if ((fazan = malloc(size * sizeof(char))) == NULL)
            {
                perror(NULL);
                exit(-1);
            }
            strcpy(fazan, cuvant);
            strcat(fazan, "-");
        }
        else
        {
            if ((tolower(fazan[strlen(fazan) - 3] == tolower(cuvant[0]))) && ((tolower(fazan[strlen(fazan) - 2]) == tolower(cuvant[1]))))
            {
                size = size + strlen(cuvant) + 2;
                if ((fazan = realloc(fazan, size * sizeof(char))) == NULL)
                {
                    perror(NULL);
                    exit(-1);
                }
                strcat(fazan, cuvant);
                strcat(fazan, "-");
            }
        }
    }
    fazan[strlen(fazan) - 1] = 0;
    printf("%s\n", fazan);
    free(fazan);
}

char *string_replace_dynamic(const char *where, const char *what, const char *replace)
{
    char *text = NULL, *p = NULL, aux[100], aaux[100];
    strcpy(aux, where);
    while ((p = strstr(aux, what)) != NULL)
    {
        if ((text = realloc(text, (p - aux + strlen(replace) + 1) * sizeof(char))) == NULL)
        {
            return NULL;
        }
        strncat(text, aux, p - aux);
        strcat(text, replace);
        strcpy(aaux, p + strlen(what));
        strcpy(aux, aaux);
    }
    if ((text = realloc(text, (strlen(aux) + 1) * sizeof(char))) == NULL)
    {
        return NULL;
    }
    strcat(text, aux);
    return text;
}

void p4()
{
    char s1[] = "Acesta este un string si un string este terminat cu 0x00";
    char s2[] = "string";
    char s3[] = "sir de caractere";
    char *s = NULL;
    s = string_replace_dynamic(s1, s2, s3);
    printf("%s\n", s);
    free(s);
}

void swap(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void p5()
{
    int *v = NULL, index = 0, current_size = 0, size, i, j, nr;
    // citire
    while (scanf("%d", &nr) == 1)
    {
        if (index == current_size)
        {
            if (current_size == 0)
            {
                current_size = 1;
            }
            else
            {
                current_size = current_size * 2;
            }
            if ((v = realloc(v, current_size * sizeof(int))) == NULL)
            {
                perror(NULL);
                exit(-1);
            }
        }
        v[index++] = nr;
    }
    size = index;
    // sortare
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (v[i] < v[j])
            {
                swap(&v[i], &v[j]);
            }
        }
    }
    // afisare
    for (i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    free(v);
}

char *text2hex(const char *string)
{
    char *hex = NULL, aux[3];
    int i;
    if ((hex = malloc((2 * strlen(string) + 1) * sizeof(char))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    strcpy(hex, "");
    for (i = 0; i < strlen(string); i++)
    {
        sprintf(aux, "%02X", string[i]);
        strcat(hex, aux);
    }
    return hex;
}

void p6()
{
    char s[] = "abc";
    char *hex = NULL;
    hex = text2hex(s);
    printf("%s\n", hex);
    free(hex);
}

char *hex2text(const char *hexstring)
{
    char *charText = NULL, aux[3];
    int i, hex;
    if ((charText = malloc((strlen(hexstring) / 2 + 1) * sizeof(char))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    strcpy(charText, "");
    for (i = 0; i < strlen(hexstring) - 2; i = i + 2)
    {
        strncpy(aux, hexstring + i, 2);
        hex = strtol(aux, NULL, 16);
        sprintf(aux, "%c", hex);
        strcat(charText, aux);
    }
    return charText;
}

void p7()
{
    char s[2000], *charText = NULL;
    if (fgets(s, 2000, stdin) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    s[strlen(s) - 1] = 0;
    charText = hex2text(s);
    printf("%s\n", charText);
    free(charText);
}

char *text2pasareasca(const char *text)
{
    char *pasareasca = NULL;
    int i, contorVocale = 0, index = 0;
    for (i = 0; i < strlen(text); i++)
    {
        if (strchr("aeiouAEIOU", text[i]) != NULL)
        {
            contorVocale++;
        }
    }
    if ((pasareasca = malloc((strlen(text) + 2 * contorVocale + 1) * sizeof(char))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (i = 0; i < strlen(text); i++)
    {
        if (strchr("aeiouAEIOU", text[i]) == NULL)
        {
            pasareasca[index] = text[i];
            index += 1;
        }
        else
        {
            pasareasca[index] = text[i];
            index += 1;
            pasareasca[index] = 'p';
            index += 1;
            pasareasca[index] = text[i];
            index += 1;
        }
    }
    pasareasca[index] = 0;
    return pasareasca;
}

void p8()
{
    char s[] = "ana are mere si apa";
    char *pasareasca = NULL;
    pasareasca = text2pasareasca(s);
    printf("%s\n", pasareasca);
    free(pasareasca);
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
    return 0;
}