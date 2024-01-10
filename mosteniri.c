#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define CHUNK 1000
#define LINECHUNK 16
#define LINESIZE 256

int *array(FILE *f, int size)
{
    int i, *array = NULL, index = 0, current_size = 0;
    for (i = 0; i < size; i++)
    {
        if (index == current_size)
        {
            current_size += CHUNK;
            if ((array = realloc(array, current_size * sizeof(int))) == NULL)
            {
                perror(NULL);
                exit(-1);
            }
        }
        fscanf(f, "%d", &array[index++]);
    }
    return array;
}

int **matrix(FILE *f, int m, int n)
{
    int i, **matrix = NULL, index = 0, current_size = 0;
    for (i = 0; i < m; i++)
    {
        if (index == current_size)
        {
            current_size += CHUNK;
            if ((matrix = realloc(matrix, current_size * sizeof(int*))) == NULL)
            {
                perror(NULL);
                exit(-1);
            }
        }
        matrix[index++] = array(f, n);
    }
    return matrix;
}

void printfMatrix(int **a, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void aparitii(int **a, int m, int n)
{
    int i, j, k, l, contor = 0;
    for (i = 0; i < m; i++)
    {
        printf("Linia %d: ", i);
        for (j = 0; j < n; j++)
        {
            contor = 0;
            for (k = 0; k < m; k++)
            {
                if (k != i)
                {
                    for (l = 0; l < n; l++)
                    {
                        if (a[i][j] == a[k][l])
                        {
                            contor++;
                        }
                    }
                }
            }
            if (contor >= 2)
            {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }
}

void p1(FILE *f)
{
    int m, n, **a = NULL, i;
    fscanf(f, "%d %d", &m, &n);
    a = matrix(f, m, n);
    aparitii(a, m, n);
    for (i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);
}

int verificareSpecial(int n)
{
    int d, s = 0;
    for (d = 1; d <= n / 2; d++)
    {
        if (n % d == 0)
        {
            s += d;
        }
    }
    if (n < s)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int *scanfArrayDynamic(int *size)
{
    int *array = NULL, index = 0, actualSize = 0, nr;
    while (scanf("%d", &nr) == 1)
    {
        if (nr == -1)
        {
            break;
        }
        if (index == actualSize)
        {
            actualSize += CHUNK;
            if ((array = realloc(array, actualSize * sizeof(int))) == NULL)
            {
                perror(NULL);
                exit(-1);
            }
        }
        array[index++] = nr;
    }
    *size = index;
    return array;
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

void p2()
{
    int *a1 = NULL, *a2 = NULL, *array = NULL, sizea1 = 0, sizea2 = 0, i = 0, j = 0, index = 0;
    a1 = scanfArrayDynamic(&sizea1);
    a2 = scanfArrayDynamic(&sizea2);
    if ((array = malloc((sizea1 + sizea2) * sizeof(int))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    while (i < sizea1 && j < sizea2)
    {
        if (a1[i] < a2[j])
        {
            if (verificareSpecial(a1[i]) == 1)
            {
                array[index++] = a1[i];
            }
            i++;
        }
        else
        {
            if (a2[j] < a1[i])
            {
                if (verificareSpecial(a2[j]) == 1)
                {
                    array[index++] = a2[j];
                }
                j++;
            }
            else
            {
                if (verificareSpecial(a1[i]) == 1)
                {
                    array[index++] = a1[i];
                }
                i++;
                j++;
            }
        }
    }
    while (i < sizea1)
    {
        if (verificareSpecial(a1[i]) == 1)
        {
            array[index++] = a1[i];
        }
        i++;
    }
    while (j < sizea2)
    {
        if (verificareSpecial(a2[j]) == 1)
        {
            array[index++] = a2[j];
        }
        j++;
    }
    printfArray(array, index);
    free(a1);
    free(a2);
    free(array);
}

void printfBinary(int n)
{
    int m, i;
    for (i = sizeof(int) * 8 - 1; i >= 0; i--)
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
        if (i % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void secventaBinara(int n)
{
    int m, i, contor = 0, digit;
    for (i = 0; i < sizeof(int) * 8; i++)
    {
        m = 1 << i;
        digit = n & m;
        if (digit != 0)
        {
            contor++;
        }
        else
        {
            if (contor != 0)
            {
                printf("%d ", contor);
            }
            contor = 0;
        }
    }
    printf("\n");
}

void p3()
{
    int n;
    scanf("%d", &n);
    printfBinary(n);
    secventaBinara(n);
}

void p4()
{
    char text[200], aux[200];
    int i;
    if (fgets(text, 200, stdin) == NULL)
    {
        perror(NULL);
        exit(-3);
    }
    text[strlen(text) - 1] = 0;
    for (i = 0; i < strlen(text) - 1; i++)
    {
        if ((text[i] == ' ') && (text[i + 1] == ' '))
        {
            strcpy(aux, text + i + 1);
            strcpy(text + i, aux);
            i--;
        }
    }
    printf("%s\n", text);
}

char *processLine()
{
    char *line = NULL, ch;
    int index = 0, curentsize = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
        {
            break;
        }
        if (index == curentsize)
        {
            curentsize += LINESIZE;
            if ((line = realloc(line, curentsize * sizeof(char))) == NULL)
            {
                perror(NULL);
                exit(-1);
            }
        }
        line[index++] = ch;
    }
    if (line == NULL)
    {
        return NULL;
    }
    if (index == curentsize)
    {
        curentsize += 1;
        if ((line = realloc(line, curentsize * sizeof(char))) == NULL)
        {
            perror(NULL);
            exit(-1);
        }
    }
    line[index] = 0;
    return line;
}

char **processLines(int *size)
{
    char **lines = NULL, *line = NULL;
    int index = 0, curentsize = 0;
    while ((line = processLine()) != NULL)
    {
        if (index == curentsize)
        {
            curentsize += LINECHUNK;
            if ((lines = realloc(lines, curentsize * sizeof(char *))) == NULL)
            {
                perror(NULL);
                exit(-1);
            }
        }
        lines[index++] = line;
    }
    if (lines == NULL)
    {
        return NULL;
    }
    if (index == curentsize)
    {
        curentsize += 1;
        if ((lines = realloc(lines, curentsize * sizeof(char *))) == NULL)
        {
            perror(NULL);
            exit(-1);
        }
    }
    lines[index] = NULL;
    *size = index;
    return lines;
}

int nrVocale(char *text)
{
    int contor = 0, i;
    for (i = 0; i < strlen(text); i++)
    {
        if (strchr("aeiouAEIOU", text[i]) != 0)
        {
            contor++;
        }
    }
    return contor;
}

void printfLines(char **lines)
{
    int index = 0;
    while (lines[index] != NULL)
    {
        printf("%d - %s\n", nrVocale(lines[index]), lines[index]);
        index++;
    }
}

void swapString(char **s1, char **s2)
{
    char *aux = *s1;
    *s1 = *s2;
    *s2 = aux;
}

void p5()
{
    char **lines = NULL;
    int index = 0, size = 0, i, j;
    lines = processLines(&size);
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (nrVocale(lines[i]) < nrVocale(lines[j]))
            {
                swapString(&lines[i], &lines[j]);
            }
            else
            {
                if (nrVocale(lines[i]) == nrVocale(lines[j]))
                {
                    if (strcmp(lines[i], lines[j]) < 0)
                    {
                        swapString(&lines[i], &lines[j]);
                    }
                }
            }
        }
    }
    printfLines(lines);
    while (lines[index] != NULL)
    {
        free(lines[index++]);
    }
    free(lines);
}

void scanfArray(int *v, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

int reprezentareInterna(int n)
{
    int m, digit, contor = 0, i;
    for (i = 0; i < sizeof(int) * 8; i++)
    {
        m = 1 << i;
        digit = n & m;
        if (digit != 0)
        {
            contor++;
        }
    }
    return contor;
}

void p6()
{
    int v[100], bit[100], i, n;
    scanf("%d", &n);
    scanfArray(v, n);
    for (i = 0; i < n; i++)
    {
        bit[i] = reprezentareInterna(v[i]);
    }
    printfArray(bit, n);
}

void p7()
{
    char text[200], aux[200];
    int contor = 1, i;
    if (fgets(text, 100, stdin) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    text[strlen(text) - 1] = 0;
    for (i = 0; i < strlen(text) - 1; i++)
    {
        if ((strchr("aeiouAEIOU", text[i]) != NULL && strchr("aeiouAEIOU", text[i]) != NULL) || (strchr("aeiouAEIOU", text[i]) == NULL && strchr("aeiouAEIOU", text[i]) == NULL))
        {
            strcpy(aux, text + i + 1);
            i += 1;
            text[i] = '-';
            strcpy(text + i + 1, aux);
            i += 1;
            contor++;
        }
    }
    printf("%s are %d silabe\n", text, contor);
}

int maxColoana(int **matrix, int nrLinii, int coloana)
{
    int i, max = -999999999;
    for (i = 0; i < nrLinii; i++)
    {
        if (matrix[i][coloana] > max)
        {
            max = matrix[i][coloana];
        }
    }
    return max;
}

int minLinie(int **matrix, int nrColoane, int linie)
{
    int j, min = 999999999;
    for (j = 0; j < nrColoane; j++)
    {
        if (matrix[linie][j] < min)
        {
            min = matrix[linie][j];
        }
    }
    return min;
}

void p8(FILE *f)
{
    int m, n, **a = NULL, i, j;
    fscanf(f, "%d %d", &m, &n);
    a = matrix(f, m, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == maxColoana(a, m, j) && a[i][j] == minLinie(a, n, i))
            {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
    for (i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);
}

void printf8(uint8_t nr)
{
    uint8_t m = 1 << 7, i;
    for (i = 0; i < 8; i++)
    {
        if ((m & nr) == 0)
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

uint8_t p9(uint8_t v, int n)
{
    uint8_t aux;
    if (n > 0)
    {
        aux = v >> (8 - n);
        v = v << n;
        v = v | aux;
    }
    else
    {
        n = -n;
        aux = v << (8 - n);
        v = v >> n;
        v = v | aux;
    }
    return v;
}

int sumaLinie(int **a, int linie, int n)
{
    int s = 0, j;
    for (j = 0; j < n; j++)
    {
        s += a[linie][j];
    }
    return s;
}

int sumaColoana(int **a, int m, int coloana)
{
    int s = 0, i;
    for (i = 0; i < m; i++)
    {
        s += a[i][coloana];
    }
    return s;
}

void swapLinie(int **l1, int **l2)
{
    int *aux;
    aux = *l1;
    *l1 = *l2;
    *l2 = aux;
}

void p10(FILE *f)
{
    int m, n, **a = NULL, i, j, ok = 1;
    fscanf(f, "%d %d", &m, &n);
    a = matrix(f, m, n);
    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (sumaLinie(a, i, n) > sumaLinie(a, j, n))
            {
                swapLinie(&a[i], &a[j]);
            }
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (sumaColoana(a, m, i) > sumaColoana(a, m, j))
            {
                ok = 0;
            }
        }
    }
    printfMatrix(a, m, n);
    if (ok == 0)
    {
        printf("Matricea nu are suma coloanelor in ordine crescatoare\n");
    }
    else
    {
        printf("Matricea are suma coloanelor in ordine crescatoare\n");
    }
    for (i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);
}

int main(void)
{
    FILE *f;
    if ((f = fopen("in.txt", "r")) == NULL)
    {
        perror(NULL);
        exit(-2);
    }

    // p1(f);
    // p2();
    // p3();
    // p4();
    // p5();
    // p6();
    // p7();
    // p8(f);
    // printf8(p9((uint8_t)0b10100110, -2));
    //p10(f);

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-2);
    }
    return 0;
}