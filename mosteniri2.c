#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define LINECHUNK 256
#define LINESCHUNK 16

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

int intersectie(int a, int b)
{
    int c = 0, m, i;
    for (i = 0; i < sizeof(int) * 8; i++)
    {
        m = 1 << i;
        if ((a & m) != 0 && (b & m) != 0)
        {
            c = c & ~m;
        }
        else
        {
            c = c | m;
        }
    }
    return c;
}

void p5()
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    printfBinary(a);
    printfBinary(b);
    c = intersectie(a, b);
    printfBinary(c);
}

int verificareOrdine(int *v, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (v[i] > v[j])
            {
                return 0;
            }
        }
    }
    return 1;
}

void swapInt(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void sortare(int *v, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (v[i] > v[j])
            {
                swapInt(&v[i], &v[j]);
            }
        }
    }
}

void p6()
{
    int *a = NULL, *b = NULL, *c = NULL, n, m, i, j, index = 0;

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

    if (verificareOrdine(a, n) == 0)
    {
        sortare(a, n);
    }

    if (verificareOrdine(b, m) == 0)
    {
        sortare(b, m);
    }

    printfArray(a, n);
    printfArray(b, m);

    if ((c = malloc((m + n) * sizeof(int))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    i = n - 1;
    j = m - 1;

    while (i >= 0 && j >= 0)
    {
        if (a[i] > b[j])
        {
            i--;
        }
        else
        {
            if (a[i] < b[j])
            {
                j--;
            }
            else
            {
                c[index++] = a[i];
                i--;
                j--;
            }
        }
    }

    printfArray(c, index);

    free(a);
    free(b);
    free(c);
}

void p7()
{
    char text[SIZE], *p, separatori[] = " ,.!?:;", vocale[] = "aeiouAEIOU";
    while (fgets(text, SIZE, stdin) != NULL)
    {
        text[strlen(text) - 1] = 0;
        p = strtok(text, separatori);
        while (p != NULL)
        {
            if ((strchr(vocale, p[0]) != NULL) && (strchr(vocale, p[strlen(p) - 1]) == NULL))
            {
                printf("%s\n", p);
            }
            p = strtok(NULL, separatori);
        }
    }
}

int *array(int size)
{
    int *array = NULL, i;
    if ((array = malloc(size * sizeof(int))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    return array;
}

int **matrix(int size)
{
    int **matrix = NULL, i;
    if ((matrix = malloc(size * sizeof(int *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (i = 0; i < size; i++)
    {
        matrix[i] = array(size);
    }
    return matrix;
}

void printfMatrixGeneral(int **matrix, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void p8()
{
    int n, **matrice, i, j, k;
    scanf("%d", &n);
    matrice = matrix(n);
    printfMatrixGeneral(matrice, n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                for (k = j; k < n - 1; k++)
                {
                    matrice[i][k] = matrice[i][k + 1];
                }
                if ((matrice[i] = realloc(matrice[i], (n - 1) * sizeof(int))) == NULL)
                {
                    perror(NULL);
                    exit(-1);
                }
            }
        }
    }
    printfMatrixGeneral(matrice, n, n - 1);
    for (i = 0; i < n; i++)
    {
        free(matrice[i]);
    }
    free(matrice);
}

uint32_t conversieToData(uint8_t zi, uint8_t luna, uint16_t an)
{
    uint32_t data;
    data = (zi << 24) | (luna << 16) | an;
    return data;
}

uint8_t extragereLuna(uint32_t data)
{
    uint8_t luna;
    luna = (data >> 16);
    return luna;
}

void p9()
{
    uint32_t data;
    uint16_t an;
    uint8_t zi, luna;
    scanf("%hhd %hhd %hd", &zi, &luna, &an);
    data = conversieToData(zi, luna, an);
    printfBinary(data);
    luna = extragereLuna(data);
    printf("%d\n", luna);
}

char *processLine(void)
{
    char *line = NULL, ch;
    int index = 0, current_size = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
        {
            break;
        }
        if (index == current_size)
        {
            current_size = current_size + LINECHUNK;
            if ((line = realloc(line, current_size * sizeof(char))) == NULL)
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
    if (index == current_size)
    {
        current_size = current_size + 1;
        if ((line = realloc(line, current_size * sizeof(char))) == NULL)
        {
            perror(NULL);
            exit(-1);
        }
    }
    line[index] = 0;
    return line;
}

char **processLines(void)
{
    char **lines = NULL, *line;
    int index = 0, current_size = 0;
    while ((line = processLine()) != NULL)
    {
        if (index == current_size)
        {
            current_size = current_size + LINESCHUNK;
            if ((lines = realloc(lines, current_size * sizeof(char *))) == NULL)
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
    if (index == current_size)
    {
        current_size = current_size + 1;
        if ((lines = realloc(lines, current_size * sizeof(char *))) == NULL)
        {
            perror(NULL);
            exit(-1);
        }
    }
    lines[index] = NULL;
    return lines;
}

void printfLines(char **lines)
{
    int i = 0;
    while (lines[i] != NULL)
    {
        printf("%s\n", lines[i++]);
    }
    printf("\n");
}

void freeLines(char **lines)
{
    int i = 0;
    while (lines[i] != NULL)
    {
        free(lines[i++]);
    }
}

// Aici nu inteleg cum se citeste textul (pe o linie tot sau pe mai multe randuri)
// void p10()
// {
//     int i = 0, max = -1, contor = 0;
//     char **lines = NULL, aux[SIZE], *p, separatori[] = " ,.!?:;", cuvant[SIZE];
//     strcpy(aux, "");
//     lines = processLines();
//     printfLines(lines);
//     while (lines[i] != NULL)
//     {
//         strcpy(aux, lines[i]);
//         p = strtok(aux, separatori);
//         while (p != NULL)
//         {
//             p = strtok(NULL, separatori);
//         }
//         i++;
//     }
//     freeLines(lines);
//     free(lines);
// }

uint32_t conversieToRGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
    uint32_t rgba;
    rgba = red << 24 | green << 16 | blue << 8 | alpha;
    return rgba;
}

float extragereAlpha(uint32_t rgba)
{
    uint8_t alpha;
    float procent;
    alpha = rgba;
    procent = ((float)alpha * 100) / 255;
    return procent;
}

void p11()
{
    uint8_t r, g, b, a;
    uint32_t rgba;
    scanf("%hhd %hhd %hhd %hhd", &r, &g, &b, &a);
    rgba = conversieToRGBA(r, g, b, a);
    printfBinary(rgba);
    printf("%.2f%%\n", extragereAlpha(rgba));
}

typedef enum
{
    electica,
    conventionala,
} TipMasina;

typedef struct
{
    uint16_t capacitate_baterie;
    uint16_t timp_incarcare;
} CaracteristicaElectrica;

typedef enum
{
    benzina,
    motorina,
} TipCarburant;

typedef enum
{
    automata,
    manuala,
} TipCutieViteza;

typedef struct
{
    TipCarburant tip_carburant;
    TipCutieViteza tip_cutie_viteza;
} CaracteristicaConventionala;

typedef union
{
    CaracteristicaConventionala caracteristica_conventionala;
    CaracteristicaElectrica caracteristica_electrica;
} CaracteristicaMasina;

typedef struct
{
    char model[20];
    uint16_t viteza_maxima;
    uint8_t nr_locuri;
    TipMasina tip_masina;
    CaracteristicaMasina caracteristica_masina;
} Masina;

void pritfMasina(Masina *masina)
{
    printf("Masina ");
    switch (masina->tip_masina)
    {
    case electica:
    {
        printf("electrica ");
        break;
    }
    case conventionala:
    {
        printf("conventionala ");
        break;
    }
    }
    printf("%s are viteza maxima de %d km/h, %d locuri, ", masina->model, masina->viteza_maxima, masina->nr_locuri);
    switch (masina->tip_masina)
    {
    case electica:
    {
        printf("cu o capacitate a bateriei de %d Ah si se incarca in %d minute.\n", masina->caracteristica_masina.caracteristica_electrica.capacitate_baterie, masina->caracteristica_masina.caracteristica_electrica.timp_incarcare);
        break;
    }
    case conventionala:
    {
        printf("pe ");
        switch (masina->caracteristica_masina.caracteristica_conventionala.tip_carburant)
        {
        case benzina:
        {
            printf("benzina ");
            break;
        }
        case motorina:
        {
            printf("motorina ");
            break;
        }
        }
        printf("si cu cutie ");
        switch (masina->caracteristica_masina.caracteristica_conventionala.tip_cutie_viteza)
        {
        case automata:
        {
            printf("automana.\n");
            break;
        }
        case manuala:
        {
            printf("manuala.\n");
            break;
        }
        }
        break;
    }
    }
}

void procesareMasina(Masina *masina)
{
    scanf("%19s %hd %hhd %d", masina->model, &masina->viteza_maxima, &masina->nr_locuri, &masina->tip_masina);
    switch (masina->tip_masina)
    {
    case electica:
    {
        scanf("%hd %hd", &masina->caracteristica_masina.caracteristica_electrica.capacitate_baterie, &masina->caracteristica_masina.caracteristica_electrica.timp_incarcare);
        break;
    }
    case conventionala:
    {
        scanf("%d %d", &masina->caracteristica_masina.caracteristica_conventionala.tip_carburant, &masina->caracteristica_masina.caracteristica_conventionala.tip_cutie_viteza);
        break;
    }
    }
}

void adaugareMasina(Masina **masini, int *index, int *size)
{
    *size = *size + 1;
    Masina *aux = *masini, masina;
    procesareMasina(&masina);
    if ((aux = realloc(aux, *size * sizeof(Masina))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    aux[*index] = masina;
    *masini = aux;
    *index = *index + 1;
}

void cautareMasina(int tip_cautat, Masina *masini, int size)
{
    int i, ok = 0;
    for (i = 0; i < size; i++)
    {
        if (tip_cautat == masini[i].tip_masina)
        {
            pritfMasina(&masini[i]);
            ok = 1;
        }
    }
    if (ok == 0)
    {
        printf("Nu s-au gasit masini de tipul respectiv\n");
    }
}

void p12()
{
    int optiune = 0, index = 0, current_size = 0, tip_cautat;
    Masina *masini = NULL;
    while (optiune != 3)
    {
        printf("1 - Adaugare\n");
        printf("2 - Cautare\n");
        printf("3 - Iesire\n");
        printf("Introdu optiunea: ");
        scanf("%d", &optiune);
        switch (optiune)
        {
        case 1:
        {
            adaugareMasina(&masini, &index, &current_size);
            break;
        }
        case 2:
        {
            scanf("%d", &tip_cautat);
            cautareMasina(tip_cautat, masini, current_size);
            break;
        }
        }
    }
    free(masini);
}

void p13()
{
    char **lines = NULL, vocale[] = "aeiou", aux[SIZE];
    int i = 0, j = 0, k = 0, index = 0, size = 0;
    lines = processLines();
    while (lines[i] != NULL)
    {
        size = strlen(lines[i]);
        index = size;
        for (j = 0; j < strlen(lines[i]) - 2; j++)
        {
            if (lines[i][j] == ' ')
            {
                k = 0;
            }
            if (strchr(vocale, lines[i][j]) == NULL && strchr(vocale, lines[i][j + 1]) == NULL)
            {
                if (index == size)
                {
                    size = size + LINESCHUNK;
                    if ((lines[i] = realloc(lines[i], size * sizeof(char))) == NULL)
                    {
                        perror(NULL);
                        exit(-1);
                    }
                }
                strcpy(aux, lines[i] + j + 1);
                strcpy(lines[i] + j + 2, aux);
                if (k == 5)
                {
                    k = 0;
                }
                lines[i][j + 1] = vocale[k];
                k++;
            }
        }
        i++;
    }
    printfLines(lines);
    freeLines(lines);
    free(lines);
}

int **matrixGeneral(int n, int m)
{
    int **matrix = NULL, i;
    if ((matrix = malloc(n * sizeof(int *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (i = 0; i < n; i++)
    {
        matrix[i] = array(m);
    }
    return matrix;
}

int cuprinde(int **matrice, int i, int j, int m)
{
    int ok = 0, a, b;
    for (a = 0; a < m; a++)
    {
        for (b = 0; b < m; b++)
        {
            if (matrice[i][a] < matrice[j][b])
            {
                ok++;
                b = m;
                a = m;
            }
        }
    }
    for (a = 0; a < m; a++)
    {
        for (b = 0; b < m; b++)
        {
            if (matrice[i][a] > matrice[j][b])
            {
                ok++;
                b = m;
                a = m;
            }
        }
    }
    if (ok == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void p14()
{
    int n, m, i, **matrice, max = -1, j, ok;
    scanf("%d %d", &n, &m);
    matrice = matrixGeneral(n, m);
    for (i = 0; i < n; i++)
    {
        ok = 0;
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                ok = ok + cuprinde(matrice, i, j, m);
            }
        }
        if (ok > max)
        {
            max = ok;
        }
    }
    for (i = 0; i < n; i++)
    {
        ok = 0;
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                ok = ok + cuprinde(matrice, i, j, m);
            }
        }
        if (ok == max)
        {
            printf("%d\n", i);
        }
    }
    for (i = 0; i < n; i++)
    {
        free(matrice[i]);
    }
    free(matrice);
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
    // p11();
    // p12();
    // p13();
    // p14();
    return 0;
}
