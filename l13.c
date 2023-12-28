#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

#define LINE_SIZE 200
#define CHUNK 1000
#define ARRAY_SIZE 100
#define READ_CHUNK 100
#define SENSOR_SIZE 50

typedef struct
{
    char titlu[1000];
    uint16_t an;
    uint32_t buget;
} Film;

void printfFilm(Film *film)
{
    printf("%d - %s - %d\n", film->an, film->titlu, film->buget);
}

void swapFilm(Film *a, Film *b)
{
    Film aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void swapInt(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int processLine(char *linie, Film *film)
{
    char *p;
    int i;
    if ((p = strtok(linie, ",")) == NULL)
    {
        return 1;
    }
    for (i = 0; i < 7; i++)
    {
        switch (i)
        {
        case 0:
        {
            film->an = strtol(p, NULL, 10);
            break;
        }
        case 2:
        {
            strcpy(film->titlu, p);
            break;
        }
        case 6:
        {
            film->buget = strtol(p, NULL, 10);
            break;
        }
        }
        if ((p = strtok(NULL, ",")) == NULL)
        {
            return 1;
        }
    }
    return 0;
}

void f1(Film **filme, int size)
{
    Film *aux = *filme;
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (aux[i].an > aux[j].an)
            {
                swapFilm(&aux[i], &aux[j]);
            }
        }
    }
    *filme = aux;
}

void f2(Film **filme, int size)
{
    Film *aux = *filme;
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (strcmp(aux[i].titlu, aux[j].titlu) > 0)
            {
                swapFilm(&aux[i], &aux[j]);
            }
        }
    }
    *filme = aux;
}

void f3(Film **filme, int size)
{
    Film *aux = *filme;
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (aux[i].buget > aux[j].buget)
            {
                swapFilm(&aux[i], &aux[j]);
            }
        }
    }
    *filme = aux;
}

void p1()
{
    FILE *f, *out1, *out2, *out3;
    Film *filme = NULL, aux;
    int index = 0, current_size = 0;
    char linie[LINE_SIZE];

    if ((f = fopen("movies.csv", "r")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if ((out1 = fopen("out1.txt", "w")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if ((out2 = fopen("out2.txt", "w")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if ((out3 = fopen("out3.txt", "w")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    if (fgets(linie, LINE_SIZE, f) == NULL)
    {
        perror(NULL);
        exit(-3);
    }

    while (fgets(linie, LINE_SIZE, f) != NULL)
    {
        if (processLine(linie, &aux) == 0)
        {
            if (index == current_size)
            {
                current_size = current_size + CHUNK;
                if ((filme = realloc(filme, current_size * sizeof(Film))) == NULL)
                {
                    perror(NULL);
                    exit(-2);
                }
            }
            filme[index++] = aux;
        }
    }

    current_size = index;

    f1(&filme, current_size);
    for (index = 0; index < current_size; index++)
    {
        fprintf(out1, "%d - %s - %d\n", filme[index].an, filme[index].titlu, filme[index].buget);
    }

    f2(&filme, current_size);
    for (index = 0; index < current_size; index++)
    {
        fprintf(out2, "%d - %s - %d\n", filme[index].an, filme[index].titlu, filme[index].buget);
    }

    f3(&filme, current_size);
    for (index = 0; index < current_size; index++)
    {
        fprintf(out3, "%d - %s - %d\n", filme[index].an, filme[index].titlu, filme[index].buget);
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }
    if (fclose(out1) != 0)
    {
        perror(NULL);
        exit(-1);
    }
    if (fclose(out2) != 0)
    {
        perror(NULL);
        exit(-1);
    }
    if (fclose(out3) != 0)
    {
        perror(NULL);
        exit(-1);
    }
}

void p2()
{
    FILE *f;
    int v[ARRAY_SIZE], i = 0, nr, size = ARRAY_SIZE, j;
    if ((f = fopen("out.txt", "w")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    // citire
    scanf("%d", &nr);
    while (i < size && nr != 0)
    {
        v[i++] = nr;
        scanf("%d", &nr);
    }

    size = i;

    // sortare
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
    // afisare

    for (i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            fprintf(f, "%d | ", v[i]);
        }
        else
        {
            fprintf(f, "%d", v[i]);
        }
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }
}

typedef struct
{
    char judet[50];
    uint16_t beneficiari_plati;
    uint32_t suma_totala;
} Plati;

void printfPlati(Plati *plata)
{
    printf("%s - %d - %d\n", plata->judet, plata->beneficiari_plati, plata->suma_totala);
}

void swapPlata(Plati *a, Plati *b)
{
    Plati aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int procesareLinie(char *linie, Plati *plati, char *judet_populatie, char *judet_alte_plati)
{
    char *p, judet[50];
    int i, populatie, alte_plati;
    static int max_populatie = -1, max_alte_plati = -1;
    if ((p = strtok(linie, ";")) == NULL)
    {
        return 1;
    }
    for (i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
        {
            strcpy(plati->judet, p);
            strcpy(judet, p);
            break;
        }
        case 1:
        {
            populatie = strtol(p, NULL, 10);
            if (populatie > max_populatie)
            {
                max_populatie = populatie;
                strcpy(judet_populatie, judet);
            }
            break;
        }
        case 2:
        {
            plati->beneficiari_plati = strtol(p, NULL, 10);
            break;
        }
        case 4:
        {
            plati->suma_totala = strtol(p, NULL, 10);
            break;
        }
        case 5:
        {
            alte_plati = strtol(p, NULL, 10);
            if (alte_plati > max_alte_plati)
            {
                max_alte_plati = alte_plati;
                strcpy(judet_alte_plati, judet);
            }
            break;
        }
        }
        if (((p = strtok(NULL, ";")) == NULL) && i != 5)
        {
            return 1;
        }
    }
    return 0;
}

void sortareJudet(Plati **plati, int size)
{
    int i, j;
    Plati *aux = *plati;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (strcmp(aux[i].judet, aux[j].judet) > 0)
            {
                swapPlata(&aux[i], &aux[j]);
            }
        }
    }
    *plati = aux;
}

void sortarePlati(Plati **plati, int size)
{
    int i, j;
    Plati *aux = *plati;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (aux[i].suma_totala < aux[j].suma_totala)
            {
                swapPlata(&aux[i], &aux[j]);
            }
        }
    }
    *plati = aux;
}

void p3()
{
    FILE *f, *out;
    Plati *plati = NULL, aux;
    int index = 0, current_size = 0;
    char linie[LINE_SIZE], judet_populatie[50], judet_alte_plati[50];

    if ((f = fopen("indemnizatie.csv", "r")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if ((out = fopen("out.txt", "w")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    if (fgets(linie, LINE_SIZE, f) == NULL)
    {
        perror(NULL);
        exit(-3);
    }

    while (fgets(linie, LINE_SIZE, f) != NULL)
    {
        if (procesareLinie(linie, &aux, judet_populatie, judet_alte_plati) == 0)
        {
            if (index == current_size)
            {
                current_size += CHUNK;
                if ((plati = realloc(plati, current_size * sizeof(Plati))) == NULL)
                {
                    perror(NULL);
                    exit(-2);
                }
            }
            plati[index++] = aux;
        }
    }

    current_size = index;

    sortareJudet(&plati, current_size);

    for (index = 0; index < current_size; index++)
    {
        printfPlati(&plati[index]);
    }

    printf("\n");

    sortarePlati(&plati, current_size);

    for (index = 0; index < current_size; index++)
    {
        printfPlati(&plati[index]);
    }

    fprintf(out, "Judetul cu cea mai mare populatie este: %s\n", judet_populatie);
    fprintf(out, "Judetul cu cele mai multe alte plati este: %s\n", judet_alte_plati);

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }
    if (fclose(out) != 0)
    {
        perror(NULL);
        exit(-1);
    }
    free(plati);
}

char *getLine(FILE *f)
{
    char *line = NULL, ch;
    int index = 0, current_size = 0;
    while ((ch = fgetc(f)) != EOF)
    {
        if (ch == '\n')
        {
            break;
        }
        if (index == current_size)
        {
            current_size += CHUNK;
            if ((line = realloc(line, current_size * sizeof(char))) == NULL)
            {
                return NULL;
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
        current_size += 1;
        if ((line = realloc(line, current_size * sizeof(char))) == NULL)
        {
            return NULL;
        }
    }
    line[index] = 0;
    return line;
}

char **getLines(FILE *f)
{
    char **lines = NULL, *line = NULL;
    int index = 0, current_size = 0;
    while ((line = getLine(f)) != NULL)
    {
        if (index == current_size)
        {
            current_size += CHUNK;
            if ((lines = realloc(lines, current_size * sizeof(char *))) == NULL)
            {
                return NULL;
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
        current_size += 1;
        if ((lines = realloc(lines, current_size * sizeof(char *))) == NULL)
        {
            return NULL;
        }
    }
    lines[index] = NULL;
    return lines;
}

void swapString(char **a, char **b)
{
    char *aux = *a;
    *a = *b;
    *b = aux;
}

void sortareAlfabetica(char **lines, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (strcmp(lines[i], lines[j]) > 0)
            {
                swapString(&lines[i], &lines[j]);
            }
        }
    }
}

int nr_linii(char **lines)
{
    int nr_linii = 0, i = 0;
    while (lines[i] != NULL)
    {
        i++;
    }
    nr_linii = i;
    return nr_linii;
}

void write_sort(char **lines, char *filepath)
{
    int line_size = nr_linii(lines), i;
    FILE *f;
    if ((f = fopen(filepath, "w")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    sortareAlfabetica(lines, line_size);

    for (i = 0; i < line_size; i++)
    {
        fprintf(f, "%s\n", lines[i]);
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }
}

void write_random(char **lines, char *filepath)
{
    int line_size = nr_linii(lines), i = 0, random;
    uint8_t *aparitii = NULL;
    FILE *f;
    if ((f = fopen(filepath, "w")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    if ((aparitii = calloc(line_size, sizeof(uint8_t))) == NULL)
    {
        perror(NULL);
        exit(-2);
    }

    while (i < line_size)
    {
        random = rand() % 100;
        if (random < line_size)
        {
            if (aparitii[random] == 0)
            {
                aparitii[random] = 1;
                fprintf(f, "%s\n", lines[random]);
                i += 1;
            }
        }
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }

    free(aparitii);
}

uint32_t find_word(char **lines, char *word)
{
    int line_size = nr_linii(lines), count = 0, i;
    char *line_aux = NULL, *p, *aux = NULL, *rest = NULL;
    for (i = 0; i < line_size; i++)
    {
        line_aux = lines[i];
        while ((p = strstr(line_aux, word)) != NULL)
        {
            if ((rest = realloc(rest, (p - line_aux) * sizeof(char))) == NULL)
            {
                perror(NULL);
                exit(-2);
            }
            strncpy(rest, line_aux, p - line_aux);
            if (!isalpha(rest[strlen(rest) - 1]) && !isalpha(p[(strlen(word))]))
            {
                count++;
            }
            aux = p + strlen(word);
            line_aux = aux;
        }
    }
    free(rest);
    return count;
}

void p4()
{
    FILE *f;
    char **lines = NULL;
    int i, size;

    if ((f = fopen("scrisoare.txt", "r")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    lines = getLines(f);

    size = nr_linii(lines);

    write_sort(lines, "out.txt");

    write_random(lines, "out.txt");

    printf("%d\n", find_word(lines, "ei"));

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }

    for (i = 0; i < size; i++)
    {
        free(lines[i]);
    }

    free(lines);
}

void p5()
{
    FILE *f, *out;
    int a[26] = {0}, A[26] = {0}, i, count = 0;
    char ch;
    float percentage;

    if ((f = fopen("scrisoare.txt", "r")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    if ((out = fopen("histo.txt", "w")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    while ((ch = fgetc(f)) != EOF)
    {
        if (isalpha(ch))
        {
            if (islower(ch))
            {
                a[ch - 'a'] += 1;
            }
            else
            {
                A[ch - 'A'] += 1;
            }
            count++;
        }
    }

    for (i = 0; i < 26; i++)
    {
        percentage = (a[i] * 100) / count;
        fprintf(out, "%c - %f %%\n", ('a' + i), percentage);
    }

    for (i = 0; i < 26; i++)
    {
        percentage = (A[i] * 100) / count;
        fprintf(out, "%c - %f %%\n", ('A' + i), percentage);
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }

    if (fclose(out) != 0)
    {
        perror(NULL);
        exit(-1);
    }
}

void p6()
{
    FILE *f, *out;
    int r = 0, i;
    uint32_t v[READ_CHUNK];

    if ((f = fopen("integers.bin", "rb")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    if ((out = fopen("out.txt", "w")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    while ((r = fread(v, sizeof(uint32_t), READ_CHUNK, f)) > 0)
    {
        for (i = 0; i < r; i++)
        {
            fprintf(out, "%08X\n", v[i]);
        }
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }

    if (fclose(out) != 0)
    {
        perror(NULL);
        exit(-1);
    }
}

uint32_t *readArray(FILE *f, int *size)
{
    uint32_t *array = NULL, buffer[READ_CHUNK];
    int index = 0, current_size = 0, r = 0, i;
    while ((r = fread(buffer, sizeof(uint32_t), READ_CHUNK, f)) > 0)
    {
        for (i = 0; i < r; i++)
        {
            if (index == current_size)
            {
                current_size += CHUNK;
                if ((array = realloc(array, current_size * sizeof(uint32_t))) == NULL)
                {
                    return NULL;
                }
            }
            array[index++] = buffer[i];
        }
    }
    *size = index;
    return array;
}

void swap32(uint32_t *a, uint32_t *b)
{
    uint32_t aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void sortArray(uint32_t *array, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (array[i] < array[j])
            {
                swap32(&array[i], &array[j]);
            }
        }
    }
}

void writeArray(FILE *f, uint32_t *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        fprintf(f, "%d\n", array[i]);
    }
}

void p7()
{
    FILE *f, *out;
    uint32_t *array = NULL;
    int size;

    if ((f = fopen("integers.bin", "rb")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    if ((out = fopen("out.txt", "w")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    if ((array = readArray(f, &size)) == NULL)
    {
        fprintf(stderr, "Eroare la alocare dinamica");
        exit(-2);
    }

    sortArray(array, size);

    writeArray(out, array, size);

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }

    if (fclose(out) != 0)
    {
        perror(NULL);
        exit(-1);
    }

    free(array);
}

void p8(char *source, char *destination)
{
    FILE *f, *out;
    int r = 0, w = 0;
    uint32_t array[READ_CHUNK];

    if ((f = fopen(source, "rb")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if ((out = fopen(destination, "wb")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    while ((r = fread(array, sizeof(uint32_t), READ_CHUNK, f)) > 0)
    {
        if ((w = fwrite(array, sizeof(uint32_t), READ_CHUNK, out)) != READ_CHUNK)
        {
            perror(NULL);
            exit(-1);
        }
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }
    if (fclose(out) != 0)
    {
        perror(NULL);
        exit(-1);
    }
}

typedef enum
{
    frontala,
    verticala
} Caracteristica_masina_de_spalat1;

typedef enum
{
    bumbac,
    sintetic,
    lana,
    spalare_rapida,
    delicat,
    spalare_aburi
} Programe;

typedef struct
{
    uint8_t capacitateIncarcare;
    char clasaEficienta;
    Programe programe[6];
    uint8_t nr_programe;
} CaracteristicaFrontala;

typedef enum
{
    analogic,
    digital
} TipAfisaj;

typedef enum
{
    viteza_maxima,
    viteza_minima,
    fara_stoarcere
} SelectorCentrifugare;

typedef struct
{
    TipAfisaj tipAfisaj;
    uint8_t nr_programe;
    SelectorCentrifugare tip_centrifuga[3];
    uint8_t zgomot;
    uint8_t nr_tip_centrifuga;
} CaracteristicaVerticala;

typedef union
{
    CaracteristicaFrontala caracteristicaFrontala;
    CaracteristicaVerticala caracteristicaVerticala;
} Caracteristica_masina_de_spalat2;

typedef struct
{
    char producator[50];
    char model[50];
    uint16_t pretFurnizor;
    uint16_t pretVanzare;
    uint8_t greutate;
    Caracteristica_masina_de_spalat1 caracteristica1;
    Caracteristica_masina_de_spalat2 caracteristica2;
} Masina_de_spalat;

void printfMasinaDeSpalat(Masina_de_spalat *masinaDeSpalat)
{
    int j;
    printf("Avem o masina de spalat %s ", masinaDeSpalat->producator);
    switch (masinaDeSpalat->caracteristica1)
    {
    case frontala:
    {
        printf("frontala");
        break;
    }
    case verticala:
    {
        printf("verticala");
        break;
    }
    }
    printf(", model %s, de %d kg, cu pretul de furnizor %d lei, pretul de vanzare %d lei, ", masinaDeSpalat->model, masinaDeSpalat->greutate, masinaDeSpalat->pretFurnizor, masinaDeSpalat->pretVanzare);
    switch (masinaDeSpalat->caracteristica1)
    {
    case frontala:
    {
        printf("cu o capacitate de incarcare %d kg, clasa de eficienta energetica %c si urmatoarele programe: ", masinaDeSpalat->caracteristica2.caracteristicaFrontala.capacitateIncarcare, masinaDeSpalat->caracteristica2.caracteristicaFrontala.clasaEficienta);
        for (j = 0; j < masinaDeSpalat->caracteristica2.caracteristicaFrontala.nr_programe; j++)
        {
            switch (masinaDeSpalat->caracteristica2.caracteristicaFrontala.programe[j])
            {
            case bumbac:
            {
                printf("bumbac");
                break;
            }
            case sintetic:
            {
                printf("sintetic");
                break;
            }
            case lana:
            {
                printf("lana");
                break;
            }
            case spalare_rapida:
            {
                printf("spalare rapida");
                break;
            }
            case delicat:
            {
                printf("delicat");
                break;
            }
            case spalare_aburi:
            {
                printf("spalare aburi");
                break;
            }
            }
            if (j != (masinaDeSpalat->caracteristica2.caracteristicaFrontala.nr_programe - 1))
            {
                printf(", ");
            }
        }
        break;
    }
    case verticala:
    {
        printf("cu tip de afisare ");
        switch (masinaDeSpalat->caracteristica2.caracteristicaVerticala.tipAfisaj)
        {
        case analogic:
        {
            printf("analogic, ");
            break;
        }
        case digital:
        {
            printf("digital, ");
            break;
        }
        }
        printf("cu %d programe, tipuri de centrifugare: ", masinaDeSpalat->caracteristica2.caracteristicaVerticala.nr_programe);
        for (j = 0; j < masinaDeSpalat->caracteristica2.caracteristicaVerticala.nr_tip_centrifuga; j++)
        {
            switch (masinaDeSpalat->caracteristica2.caracteristicaVerticala.tip_centrifuga[j])
            {
            case viteza_maxima:
            {
                printf("viteza maxima");
                break;
            }
            case viteza_minima:
            {
                printf("viteza minima");
                break;
            }
            case fara_stoarcere:
            {
                printf("fara stoarcere");
                break;
            }
            }
            if (j != (masinaDeSpalat->caracteristica2.caracteristicaVerticala.nr_tip_centrifuga - 1))
            {
                printf(", ");
            }
        }
        printf(" si produce un zgomot de %d dB", masinaDeSpalat->caracteristica2.caracteristicaVerticala.zgomot);
        break;
    }
    }
    printf("\n");
    printf("\n");
}

void afisare()
{
    FILE *f;
    Masina_de_spalat aux;

    if ((f = fopen("magazin.bin", "rb")) == NULL)
    {
        fprintf(stderr, "Nu ai fisierul cu produse !\n");
        exit(-1);
    }

    while (fread(&aux, sizeof(Masina_de_spalat), 1, f) == 1)
    {
        printfMasinaDeSpalat(&aux);
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }
}

void adaugare()
{
    FILE *f;
    Masina_de_spalat m;
    int i;

    if ((f = fopen("magazin.bin", "ab")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    printf("Introdu producatorul: ");
    scanf("%49s", m.producator);

    printf("Introdu modelul: ");
    scanf("%49s", m.model);

    printf("Introdu pretul furnizorului: ");
    scanf("%hd", &m.pretFurnizor);

    printf("Introdu pretul de vanzare: ");
    scanf("%hd", &m.pretVanzare);

    printf("Introdu greutatea masinii de spalat: ");
    scanf("%hhd", &m.greutate);

    printf("Introdu tipul de incarcare (0 - frontala, 1 - verticala): ");
    scanf("%d", &m.caracteristica1);

    switch (m.caracteristica1)
    {
    case frontala:
    {
        printf("Introdu capacitatea de incarcare: ");
        scanf("%hhd", &m.caracteristica2.caracteristicaFrontala.capacitateIncarcare);

        printf("Introdu clasa de eficienta energetica: ");
        scanf("%s", &m.caracteristica2.caracteristicaFrontala.clasaEficienta);

        printf("Introdu numarul de programe si programele (0 - bumbac, 1 - sintetic, 2 - lana, 3 - spalare rapida, 4 - delicat, 5 - spalare aburi): ");
        scanf("%hhd", &m.caracteristica2.caracteristicaFrontala.nr_programe);

        for (i = 0; i < m.caracteristica2.caracteristicaFrontala.nr_programe; i++)
        {
            scanf("%d", &m.caracteristica2.caracteristicaFrontala.programe[i]);
        }
        break;
    }
    case verticala:
    {
        printf("Introdu tipul de afisaj (0 - analogic, 1 - digital): ");
        scanf("%d", &m.caracteristica2.caracteristicaVerticala.tipAfisaj);

        printf("Introdu numarul de programe: ");
        scanf("%hhd", &m.caracteristica2.caracteristicaVerticala.nr_programe);

        printf("Introdu numarul de tipuri de centrifuga si tipurile (0 - viteza maxima, 1 - viteza minima, 2 - fara stoarcere): ");
        scanf("%hhd", &m.caracteristica2.caracteristicaVerticala.nr_tip_centrifuga);

        for (i = 0; i < m.caracteristica2.caracteristicaVerticala.nr_tip_centrifuga; i++)
        {
            scanf("%d", &m.caracteristica2.caracteristicaVerticala.tip_centrifuga[i]);
        }
        printf("Introdu valoarea zgomotului produs: ");
        scanf("%hhd", &m.caracteristica2.caracteristicaVerticala.zgomot);
        break;
    }
    }

    if (fwrite(&m, sizeof(Masina_de_spalat), 1, f) != 1)
    {
        perror(NULL);
        exit(-1);
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }
}

Masina_de_spalat *procesareMasiniSpalat(FILE *f, int *size)
{
    int index = 0, current_size = 0;
    Masina_de_spalat *masini = NULL, aux;
    while (fread(&aux, sizeof(Masina_de_spalat), 1, f) == 1)
    {
        if (index == current_size)
        {
            current_size += CHUNK;
            if ((masini = realloc(masini, current_size * sizeof(Masina_de_spalat))) == NULL)
            {
                perror(NULL);
                exit(-2);
            }
        }
        masini[index++] = aux;
    }
    *size = index;
    return masini;
}

void swapMasiniSpalat(Masina_de_spalat *m1, Masina_de_spalat *m2)
{
    Masina_de_spalat aux;
    aux = *m1;
    *m1 = *m2;
    *m2 = aux;
}

void afisareCategorie()
{
    FILE *f;
    Masina_de_spalat *masini;
    int i, j, size, countf = 0, countv = 0;

    if ((f = fopen("magazin.bin", "rb")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    masini = procesareMasiniSpalat(f, &size);

    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (masini[i].caracteristica1 == 1 && masini[j].caracteristica1 == 0)
            {
                swapMasiniSpalat(&masini[i], &masini[j]);
            }
        }
    }

    for (i = 0; i < size; i++)
    {
        if (masini[i].caracteristica1 == 0)
        {
            countf++;
        }
        else
        {
            countv++;
        }
    }

    if ((countf + countv) != size)
    {
        fprintf(stderr, "Eroare la citire");
        exit(-3);
    }

    printf("Masini de spalat frontale\n\n");

    for (i = 0; i < countf; i++)
    {
        printfMasinaDeSpalat(&masini[i]);
    }

    printf("Masini de spalat verticale\n\n");

    for (i = countf; i < size; i++)
    {
        printfMasinaDeSpalat(&masini[i]);
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }
    free(masini);
}

void oferta(uint16_t pret)
{
    FILE *f, *out;
    char linieFisier[LINE_SIZE] = "", auxiliar[100];
    Masina_de_spalat aux;
    int i, ok = 0, minim = 999999999;

    if ((f = fopen("magazin.bin", "rb")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    if ((out = fopen("oferta.txt", "wb")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    while (fread(&aux, sizeof(Masina_de_spalat), 1, f) == 1)
    {
        if (minim > aux.pretVanzare)
        {
            minim = aux.pretVanzare;
        }

        if (aux.pretVanzare <= pret)
        {
            ok = 1;
            switch (aux.caracteristica1)
            {
            case frontala:
            {
                strcat(linieFisier, aux.producator);
                strcat(linieFisier, " ");

                strcat(linieFisier, aux.model);
                strcat(linieFisier, " ");

                sprintf(auxiliar, "%d", aux.pretFurnizor);
                strcat(linieFisier, auxiliar);
                strcat(linieFisier, " ");

                strcat(linieFisier, "frontala ");

                sprintf(auxiliar, "%d", aux.caracteristica2.caracteristicaFrontala.capacitateIncarcare);
                strcat(linieFisier, auxiliar);
                strcat(linieFisier, " ");

                strcat(linieFisier, &aux.caracteristica2.caracteristicaFrontala.clasaEficienta);
                strcat(linieFisier, " ");

                for (i = 0; i < aux.caracteristica2.caracteristicaFrontala.nr_programe; i++)
                {
                    switch (aux.caracteristica2.caracteristicaFrontala.programe[i])
                    {
                    case bumbac:
                    {
                        strcat(linieFisier, "bumbac");
                        break;
                    }
                    case sintetic:
                    {
                        strcat(linieFisier, "sintetic");
                        break;
                    }
                    case lana:
                    {
                        strcat(linieFisier, "lana");
                        break;
                    }
                    case spalare_rapida:
                    {
                        strcat(linieFisier, "spalare rapida");
                        break;
                    }
                    case delicat:
                    {
                        strcat(linieFisier, "delicat");
                        break;
                    }
                    case spalare_aburi:
                    {
                        strcat(linieFisier, "spalare aburi");
                        break;
                    }
                    }
                    if (i != (aux.caracteristica2.caracteristicaFrontala.nr_programe - 1))
                    {
                        strcat(linieFisier, " ");
                    }
                }

                break;
            }
            case verticala:
            {
                strcat(linieFisier, aux.producator);
                strcat(linieFisier, " ");

                strcat(linieFisier, aux.model);
                strcat(linieFisier, " ");

                sprintf(auxiliar, "%d", aux.pretFurnizor);
                strcat(linieFisier, auxiliar);
                strcat(linieFisier, " ");

                strcat(linieFisier, "verticala ");

                switch (aux.caracteristica2.caracteristicaVerticala.tipAfisaj)
                {
                case analogic:
                {
                    strcat(linieFisier, "analogic ");
                    break;
                }
                case digital:
                {
                    strcat(linieFisier, "digital ");
                    break;
                }
                }

                sprintf(auxiliar, "%d", aux.caracteristica2.caracteristicaVerticala.nr_programe);
                strcat(linieFisier, auxiliar);
                strcat(linieFisier, " ");

                for (i = 0; i < aux.caracteristica2.caracteristicaVerticala.nr_tip_centrifuga; i++)
                {
                    switch (aux.caracteristica2.caracteristicaVerticala.tip_centrifuga[i])
                    {
                    case viteza_maxima:
                    {
                        strcat(linieFisier, "viteza maxima");
                        break;
                    }
                    case viteza_minima:
                    {
                        strcat(linieFisier, "viteza minima");
                        break;
                    }
                    case fara_stoarcere:
                    {
                        strcat(linieFisier, "fara stoarcere");
                        break;
                    }
                    }
                    strcat(linieFisier, " ");
                }

                sprintf(auxiliar, "%d", aux.caracteristica2.caracteristicaVerticala.zgomot);
                strcat(linieFisier, auxiliar);
                strcat(linieFisier, " ");

                break;
            }
            }
            fprintf(out, "%s\n", linieFisier);
            strcpy(linieFisier, "");
        }
    }

    if (ok == 0)
    {
        fprintf(out, "Nu avem nicio masina de spalat cu pretul de %d lei. Cea mai ieftina masina de spalat pe care o avem este la %d lei\n", pret, minim);
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }

    if (fclose(out) != 0)
    {
        perror(NULL);
        exit(-1);
    }
}

void cautare(uint8_t greutate)
{
    FILE *f;
    Masina_de_spalat *masini;
    int i, size, ok = 0;

    if ((f = fopen("magazin.bin", "rb")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    masini = procesareMasiniSpalat(f, &size);

    for (i = 0; i < size; i++)
    {
        if (masini[i].greutate == greutate)
        {
            printfMasinaDeSpalat(&masini[i]);
            ok = 1;
        }
    }

    if (ok == 0)
    {
        printf("Nu s-au gasit masini de spalat cu greutatea de %d kg\n", greutate);
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }
    free(masini);
}

void sortare()
{
    FILE *f;
    Masina_de_spalat *masini;
    int i, j, size, countf = 0, countv = 0;

    if ((f = fopen("magazin.bin", "rb")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    masini = procesareMasiniSpalat(f, &size);

    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (masini[i].caracteristica1 == 1 && masini[j].caracteristica1 == 0)
            {
                swapMasiniSpalat(&masini[i], &masini[j]);
            }
        }
    }

    for (i = 0; i < size; i++)
    {
        if (masini[i].caracteristica1 == 0)
        {
            countf++;
        }
        else
        {
            countv++;
        }
    }

    if ((countf + countv) != size)
    {
        fprintf(stderr, "Eroare la citire");
        exit(-3);
    }

    for (i = 0; i < countf - 1; i++)
    {
        for (j = i + 1; j < countf; j++)
        {
            if (tolower(masini[i].caracteristica2.caracteristicaFrontala.clasaEficienta) > tolower(masini[j].caracteristica2.caracteristicaFrontala.clasaEficienta))
            {
                swapMasiniSpalat(&masini[i], &masini[j]);
            }
        }
    }

    for (i = 0; i < countf; i++)
    {
        printfMasinaDeSpalat(&masini[i]);
    }

    if (countf == 0)
    {
        printf("Nu avem masini de spalat frontale\n");
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }
    free(masini);
}

void afisareProducator()
{
    FILE *f;
    Masina_de_spalat *masini;
    int i, j, size;

    if ((f = fopen("magazin.bin", "rb")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    masini = procesareMasiniSpalat(f, &size);

    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (strcmp(masini[i].producator, masini[j].producator) > 0)
            {
                swapMasiniSpalat(&masini[i], &masini[j]);
            }
        }
    }

    for (i = 0; i < size; i++)
    {
        printfMasinaDeSpalat(&masini[i]);
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }
    free(masini);
}

void p9()
{
    int optiune = 0;
    while (optiune != 8)
    {
        printf("1.Afisare\n");
        printf("2.Adaugare\n");
        printf("3.Afisare pe categorie\n");
        printf("4.Oferta\n");
        printf("5.Cautare\n");
        printf("6.Sortare\n");
        printf("7.Afisare Producator\n");
        printf("8.Iesire\n");
        printf("Introdu optiunea: ");
        scanf("%d", &optiune);
        printf("\n");
        switch (optiune)
        {
        case 1:
        {

            afisare();
            break;
        }
        case 2:
        {
            adaugare();
            break;
        }
        case 3:
        {
            afisareCategorie();
            break;
        }
        case 4:
        {
            uint16_t pret;
            printf("Introdu suma de bani pentru oferta: ");
            scanf("%hd", &pret);
            oferta(pret);
            break;
        }
        case 5:
        {
            uint8_t greutate;
            printf("Introdu greutatea masinii de spalat: ");
            scanf("%hhd", &greutate);
            printf("\n");
            cautare(greutate);
            break;
        }
        case 6:
        {
            sortare();
            break;
        }
        case 7:
        {
            afisareProducator();
            break;
        }
        }
        printf("\n");
    }
}

typedef enum
{
    funcional,
    probleme,
    defect
} TipSenzor;

typedef struct
{
    uint16_t an;
    uint8_t luna;
    uint8_t zi;
    uint8_t idx_senzor;
    int16_t valoare;
} InregistrareSenzor;

void printfSenzor(InregistrareSenzor *senzor)
{
    printf("%hhd/%hhd/%hd -> %hhd senzor a inregistrat valoarea %hd\n", senzor->zi, senzor->luna, senzor->an, senzor->idx_senzor, senzor->valoare);
}

void creareSenzori()
{
    FILE *f;
    InregistrareSenzor senzor;
    int i, aux, size, nrProbleme, count = 0;

    if ((f = fopen("senzori.bin", "wb")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    size = rand() % 100 + 1;

    if (fwrite(&size, sizeof(int), 1, f) != 1)
    {
        fprintf(stderr, "Eroare la citire");
        exit(-3);
    }

    for (i = 0; i < size; i++)
    {
        senzor.idx_senzor = 0;

        aux = rand() % 100;
        while (aux <= 0 || aux >= 29)
        {
            aux = rand() % 100;
        }
        senzor.zi = aux;

        aux = rand() % 10;
        while (aux <= 0 || aux >= 13)
        {
            aux = rand() % 10;
        }
        senzor.luna = aux;

        aux = rand() % 10000;
        while (aux <= 1900 || aux >= 2024)
        {
            aux = rand() % 10000;
        }
        senzor.an = aux;

        aux = rand() % 100;
        while (aux <= -1000 || aux >= 1000)
        {
            aux = rand() % 100;
        }
        senzor.valoare = aux;

        if (fwrite(&senzor, sizeof(InregistrareSenzor), 1, f) != 1)
        {
            fprintf(stderr, "Eroare la citire");
            exit(-3);
        }
    }

    size = rand() % 100 + 1;

    if (fwrite(&size, sizeof(int), 1, f) != 1)
    {
        fprintf(stderr, "Eroare la citire");
        exit(-3);
    }

    for (i = 0; i < size; i++)
    {
        senzor.idx_senzor = 1;

        aux = rand() % 100;
        while (aux <= 0 || aux >= 29)
        {
            aux = rand() % 100;
        }
        senzor.zi = aux;

        aux = rand() % 10;
        while (aux <= 0 || aux >= 13)
        {
            aux = rand() % 10;
        }
        senzor.luna = aux;

        aux = rand() % 10000;
        while (aux <= 1900 || aux >= 2024)
        {
            aux = rand() % 10000;
        }
        senzor.an = aux;

        aux = rand() % 10000;

        while (aux >= -1000 && aux <= 1000)
        {
            aux = rand() % 10000;
        }
        senzor.valoare = aux;

        if (fwrite(&senzor, sizeof(InregistrareSenzor), 1, f) != 1)
        {
            fprintf(stderr, "Eroare la citire");
            exit(-3);
        }
    }

    size = rand() % 100 + 1;

    nrProbleme = rand() % 100;

    while (nrProbleme <= 0 || nrProbleme >= size)
    {
        nrProbleme = rand() % 100;
    }

    if (fwrite(&size, sizeof(int), 1, f) != 1)
    {
        fprintf(stderr, "Eroare la citire");
        exit(-3);
    }

    for (i = 0; i < size; i++)
    {
        senzor.idx_senzor = 2;

        aux = rand() % 100;
        while (aux <= 0 || aux >= 29)
        {
            aux = rand() % 100;
        }
        senzor.zi = aux;

        aux = rand() % 10;
        while (aux <= 0 || aux >= 13)
        {
            aux = rand() % 10;
        }
        senzor.luna = aux;

        aux = rand() % 10000;
        while (aux <= 1900 || aux >= 2024)
        {
            aux = rand() % 10000;
        }
        senzor.an = aux;

        aux = rand() % 10000;

        while ((aux >= -1000 && aux <= 1000) && count != nrProbleme)
        {
            aux = rand() % 10000;
        }
        while ((aux <= -1000 || aux >= 1000) && count == nrProbleme)
        {
            aux = rand() % 10000;
        }
        senzor.valoare = aux;
        count++;

        if (fwrite(&senzor, sizeof(InregistrareSenzor), 1, f) != 1)
        {
            fprintf(stderr, "Eroare la citire");
            exit(-3);
        }
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }
}

void verificareSenzori(char *filePath)
{
    FILE *f;
    InregistrareSenzor senzor;
    int nrInregistrari, i, nrProbleme = 0;

    if ((f = fopen(filePath, "rb")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    while (fread(&nrInregistrari, sizeof(int), 1, f) > 0)
    {
        nrProbleme = 0;
        for (i = 0; i < nrInregistrari; i++)
        {
            fread(&senzor, sizeof(InregistrareSenzor), 1, f);
            if ((senzor.valoare < -1000) || (senzor.valoare > 1000))
            {
                nrProbleme++;
            }
        }
        if (nrProbleme == 0)
        {
            printf("Senzorul %d este functional\n", senzor.idx_senzor);
        }
        else
        {
            if (nrProbleme < nrInregistrari)
            {
                printf("Senzorul %d are probleme\n", senzor.idx_senzor);
            }
            else
            {
                printf("Senzorul %d este defect\n", senzor.idx_senzor);
            }
        }
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }
}

void afisareSenzori(uint16_t an, uint8_t luna, char *filePath)
{
    FILE *f;
    InregistrareSenzor senzor;
    int nrInregistrari, i, ok = 0;

    if ((f = fopen(filePath, "rb")) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    while (fread(&nrInregistrari, sizeof(int), 1, f) > 0)
    {
        for (i = 0; i < nrInregistrari; i++)
        {
            fread(&senzor, sizeof(InregistrareSenzor), 1, f);
            if (senzor.an == an && senzor.luna == luna)
            {
                ok = 1;
                printfSenzor(&senzor);
            }
        }
    }

    if(ok == 0)
    {
        printf("Nu avem niciun senzor care sa inregistreze\n");
    }

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-1);
    }
}

void p10()
{
    uint16_t an;
    uint8_t luna;
    creareSenzori();
    verificareSenzori("senzori.bin");
    printf("Introdu un an si o luna: ");
    scanf("%hd %hhd", &an, &luna);
    afisareSenzori(an, luna, "senzori.bin");
}

int main(void)
{
    srand(time(NULL));
    // p1();
    // p2();
    // p3();
    // p4();
    // p5();
    // p6();
    // p7();
    // p8("integers.bin", "out.bin");
    // p9();
    p10();
    return 0;
}