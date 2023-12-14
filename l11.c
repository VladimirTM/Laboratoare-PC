#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define CHUNK 100

typedef struct
{
    int real;
    int imaginar;
} Complex;

void scanfComplex(Complex *c)
{
    scanf("%d %d", &c->real, &c->imaginar);
}

void printfComplex(Complex *c)
{
    if (c->real != 0)
    {
        printf("%d", c->real);
        if (c->imaginar > 0)
        {
            printf("+%di", c->imaginar);
        }
        else
        {
            if (c->imaginar < 0)
            {
                printf("%di", c->imaginar);
            }
        }
        printf("\n");
    }
    else
    {
        if (c->imaginar > 0)
        {
            printf("+%di", c->imaginar);
        }
        else
        {
            if (c->imaginar < 0)
            {
                printf("%di", c->imaginar);
            }
        }
        if (c->imaginar == 0)
        {
            printf("0");
        }
        printf("\n");
    }
}

Complex adunare(Complex *c1, Complex *c2)
{
    Complex c;
    c.real = c1->real + c2->real;
    c.imaginar = c1->imaginar + c2->imaginar;
    return c;
}

Complex scadere(Complex *c1, Complex *c2)
{
    Complex c;
    c.real = c1->real - c2->real;
    c.imaginar = c1->imaginar - c2->imaginar;
    return c;
}

Complex inmultire(Complex *c1, Complex *c2)
{
    Complex c;
    c.real = c1->real * c2->real - c1->imaginar * c2->imaginar;
    c.imaginar = c1->real * c2->imaginar + c1->imaginar * c2->real;
    return c;
}

float modul(Complex *c)
{
    float modul;
    modul = sqrt(c->real * c->real + c->imaginar * c->imaginar);
    return modul;
}

void p1()
{
    Complex c1, c2, a, s, i;
    scanfComplex(&c1);
    scanfComplex(&c2);
    printfComplex(&c1);
    printfComplex(&c2);
    a = adunare(&c1, &c2);
    s = scadere(&c1, &c2);
    i = inmultire(&c1, &c2);
    printfComplex(&a);
    printfComplex(&s);
    printfComplex(&i);
    printf("%.2f\n", modul(&c1));
    printf("%.2f\n", modul(&c2));
}

typedef struct
{
    uint8_t secunda;
    uint8_t minut;
    uint8_t ora;
} Ora;

void scanfOra(Ora *o)
{
    scanf("%hhd %hhd %hhd", &o->ora, &o->minut, &o->secunda);
}

void printfOra(Ora *o)
{
    printf("%d:%d:%d\n", o->ora, o->minut, o->secunda);
}

typedef struct
{
    Ora ora;
    float temperatura;
} Temperatura;

void scanfTemperatura(Temperatura *t)
{
    scanfOra(&t->ora);
    scanf("%f", &t->temperatura);
}

void printfTemperatura(Temperatura *t)
{
    printf("S-a inregistrat temeperatura de %.2f C la ora ", t->temperatura);
    printfOra(&t->ora);
}

void p2()
{
    int n, i, count = 0;
    Temperatura t[10];
    Ora inceput, final;
    float medie = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanfTemperatura(&t[i]);
        printfTemperatura(&t[i]);
    }
    scanfOra(&inceput);
    scanfOra(&final);
    printfOra(&inceput);
    printfOra(&final);
    for (i = 0; i < n; i++)
    {
        if (inceput.ora < t[i].ora.ora && t[i].ora.ora < final.ora)
        {
            medie = medie + t[i].temperatura;
            count++;
        }
        else
        {
            if (inceput.ora == t[i].ora.ora)
            {
                if (inceput.minut < t[i].ora.minut)
                {
                    medie = medie + t[i].temperatura;
                    count++;
                }
                else
                {
                    if (inceput.minut == t[i].ora.minut)
                    {
                        if (inceput.secunda < t[i].ora.secunda)
                        {
                            medie = medie + t[i].temperatura;
                            count++;
                        }
                        else
                        {
                            if (inceput.secunda == t[i].ora.secunda)
                            {
                                medie = medie + t[i].temperatura;
                                count++;
                            }
                        }
                    }
                }
            }
            else
            {
                if (final.ora == t[i].ora.ora)
                {
                    if (final.minut > t[i].ora.minut)
                    {
                        medie = medie + t[i].temperatura;
                        count++;
                    }
                    else
                    {
                        if (inceput.minut == t[i].ora.minut)
                        {
                            if (final.secunda > t[i].ora.secunda)
                            {
                                medie = medie + t[i].temperatura;
                                count++;
                            }
                            else
                            {
                                if (final.secunda == t[i].ora.secunda)
                                {
                                    medie = medie + t[i].temperatura;
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    medie = medie / count;
    printf("Media temperaturii in intervalul orar este %.2f C\n", medie);
}

typedef struct
{
    char nume[50];
    uint8_t varsta;
} Persoana;

void scanfPersona(Persoana *p)
{
    fgets(p->nume, 100, stdin);
    p->nume[strcspn(p->nume, "\n")] = '\0';
    scanf("%hhd", &p->varsta);
}

void printfPersoana(Persoana *p)
{
    printf("%s are %hhd ani\n", p->nume, p->varsta);
}

void p3()
{
    int i;
    Persoana p;
    scanfPersona(&p);
    p.nume[0] = toupper(p.nume[0]);
    for (i = 1; i < strlen(p.nume); i++)
    {
        p.nume[i] = tolower(p.nume[i]);
    }
    printfPersoana(&p);
}

typedef struct
{
    int x;
    int y;
} Punct;

void scanfPunct(Punct *p)
{
    scanf("%d %d", &p->x, &p->y);
}

void printfPunct(Punct *p)
{
    printf("(%d,%d)", p->x, p->y);
}

void p4()
{
    int n, i, current_size = 0, index = 0, max = -999999999, min = 999999999, j, ok;
    Punct *puncte = NULL, punct;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        if (index == current_size)
        {
            current_size = current_size + CHUNK;
            if ((puncte = realloc(puncte, current_size * sizeof(Punct))) == NULL)
            {
                perror(NULL);
                exit(-1);
            }
        }
        scanfPunct(&punct);
        if (punct.y < min)
        {
            min = punct.y;
        }
        if (punct.y > max)
        {
            max = punct.y;
        }
        puncte[index++] = punct;
    }
    for (i = min; i <= max; i++)
    {
        ok = 0;
        for (j = 0; j < index; j++)
        {
            if (puncte[j].y == i)
            {
                ok = 1;
                printfPunct(&puncte[j]);
                printf(" ");
            }
        }
        if (ok == 1)
        {
            printf("\n");
        }
    }
    free(puncte);
}

typedef enum
{
    insecte,
    pasari,
    mamifere,
    pesti
} Tip_Animal;

typedef struct
{
    int nr_picioare;
    int durata_viata;
} Caracteristica_Insecta;

typedef struct
{
    int viteza_zbor;
    int lungime_aripa;
} Caracteristica_Pasare;

typedef enum
{
    carnivor,
    ierbivor,
    omnivor
} Tip_Mancare;

typedef struct
{
    int greutate;
    int inaltime;
    Tip_Mancare tip_mancare;
} Caracteristica_Mamifer;

typedef struct
{
    int greutate;
    int adancime_innot;
    int salinitate;
} Caracteristica_Peste;

typedef union
{
    Caracteristica_Insecta caracteristica_insecta;
    Caracteristica_Pasare caracteristica_pasare;
    Caracteristica_Mamifer caracteristica_mamifer;
    Caracteristica_Peste caracteristica_peste;
} Caracteristica_Animal;

typedef struct
{
    char nume_animal[50];
    Tip_Animal tip_animal;
    Caracteristica_Animal caracteristica;
} Animal;

void scanfAnimal(Animal *a)
{
    scanf("%49s %d", a->nume_animal, &a->tip_animal);
    switch (a->tip_animal)
    {
    case insecte:
    {
        scanf("%d %d", &a->caracteristica.caracteristica_insecta.nr_picioare, &a->caracteristica.caracteristica_insecta.durata_viata);
        break;
    }
    case pasari:
    {
        scanf("%d %d", &a->caracteristica.caracteristica_pasare.viteza_zbor, &a->caracteristica.caracteristica_pasare.lungime_aripa);
        break;
    }
    case mamifere:
    {
        scanf("%d %d %d", &a->caracteristica.caracteristica_mamifer.greutate, &a->caracteristica.caracteristica_mamifer.inaltime, &a->caracteristica.caracteristica_mamifer.tip_mancare);
        break;
    }
    case pesti:
    {
        scanf("%d %d %d", &a->caracteristica.caracteristica_peste.greutate, &a->caracteristica.caracteristica_peste.adancime_innot, &a->caracteristica.caracteristica_peste.salinitate);
        break;
    }
    }
}

void printfAnimal(Animal *a)
{
    printf("%s este ", a->nume_animal);
    switch (a->tip_animal)
    {
    case insecte:
    {
        printf("o insecta cu %d picioare, care traieste %d zile\n", a->caracteristica.caracteristica_insecta.nr_picioare, a->caracteristica.caracteristica_insecta.durata_viata);
        break;
    }
    case pasari:
    {
        printf("o pasare, care zboara cu %d m/s, avanda lungimea aripilor de %d cm\n", a->caracteristica.caracteristica_pasare.viteza_zbor, a->caracteristica.caracteristica_pasare.lungime_aripa);
        break;
    }
    case mamifere:
    {
        printf("un mamifer de %d kg, %d m inaltime, ", a->caracteristica.caracteristica_mamifer.greutate, a->caracteristica.caracteristica_mamifer.inaltime);
        switch (a->caracteristica.caracteristica_mamifer.tip_mancare)
        {
        case carnivor:
        {
            printf("carnivor\n");
            break;
        }
        case ierbivor:
        {
            printf("ierbivor\n");
            break;
        }
        case omnivor:
        {
            printf("omnivor\n");
            break;
        }
        }
        break;
    }
    case pesti:
    {
        printf("un peste, care are %d g, innoata la %d m adancime, la o apa de %d%% salinitate\n", a->caracteristica.caracteristica_peste.greutate, a->caracteristica.caracteristica_peste.adancime_innot, a->caracteristica.caracteristica_peste.salinitate);
        break;
    }
    }
}

void deleteAnimal(Animal *a, char nume[50], int *size)
{
    int i, j;
    for (i = 0; i < *size; i++)
    {
        if (strcmp(nume, a[i].nume_animal) == 0)
        {
            for (j = i; j < *size - 1; j++)
            {
                a[j] = a[j + 1];
            }
            *size = *size - 1;
            i--;
        }
    }
}

void p5()
{
    int i, n;
    char animal[50];
    Animal a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanfAnimal(&a[i]);
    }
    for (i = 0; i < n; i++)
    {
        printfAnimal(&a[i]);
    }
    printf("\n");
    scanf("%49s", animal);
    deleteAnimal(a, animal, &n);
    for (i = 0; i < n; i++)
    {
        printfAnimal(&a[i]);
    }
}

void p6()
{
    int index = 0, current_size = 0;
    Punct *puncte = NULL, punct, punctMinim;
    float distanta, minim = 999999999;
    while (scanf("%d.%d", &punct.x, &punct.y) == 2)
    {
        if (index == current_size)
        {
            current_size = current_size + CHUNK;
            if ((puncte = realloc(puncte, current_size * sizeof(Punct))) == NULL)
            {
                perror(NULL);
                exit(-1);
            }
        }
        distanta = sqrt((punct.x * punct.x) + (punct.y * punct.y));
        if (distanta < minim)
        {
            minim = distanta;
            punctMinim.x = punct.x;
            punctMinim.y = punct.y;
        }
        puncte[index++] = punct;
    }
    printfPunct(&punctMinim);
    printf("\n");
    free(puncte);
}

typedef enum
{
    stickUSB,
    baterie
} Tip_Produs;

typedef enum
{
    A,
    C
} Tip_Interfata;

typedef struct
{
    Tip_Interfata tip_interfata;
    int capacitate;
} Caracteristica_USB;

typedef union
{
    Caracteristica_USB caracteristica_USB;
    int voltaj;
} Caracteristica_Produs;

typedef struct
{
    int cod_unic;
    int pret;
    int stoc;
    Tip_Produs tip_produs;
    Caracteristica_Produs caracteristica_produs;
} Produs;

void introducere(Produs **produse, int *index, int *size)
{
    int i, ok = 1;
    Produs produsNou, *produseAux = *produse;
    scanf("%d %d %d", &produsNou.cod_unic, &produsNou.pret, &produsNou.tip_produs);
    produsNou.stoc = 1;
    switch (produsNou.tip_produs)
    {
    case stickUSB:
    {
        scanf("%d %d", &produsNou.caracteristica_produs.caracteristica_USB.tip_interfata, &produsNou.caracteristica_produs.caracteristica_USB.capacitate);
        break;
    }
    case baterie:
    {
        scanf("%d", &produsNou.caracteristica_produs.voltaj);
    }
    }
    for (i = 0; i < *size; i++)
    {
        if (produseAux[i].cod_unic == produsNou.cod_unic)
        {
            ok = 0;
            produseAux[i].stoc += 1;
        }
    }
    if (ok == 1)
    {
        if (*index == *size)
        {
            *size = *size + CHUNK;
            if ((produseAux = realloc(produseAux, *size * sizeof(Produs))) == NULL)
            {
                perror(NULL);
                exit(-1);
            }
        }
        produseAux[*index] = produsNou;
        *index += 1;
    }
    *produse = produseAux;
}

void listare(Produs *p, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (p[i].stoc != 0)
        {
            printf("Avem %d produs(e) cu codul unic %d, cu pretul de %d ron, ce sunt ", p[i].stoc, p[i].cod_unic, p[i].pret);
            switch (p[i].tip_produs)
            {
            case stickUSB:
            {
                printf("stick-uri USB-");
                switch (p[i].caracteristica_produs.caracteristica_USB.tip_interfata)
                {
                case A:
                {
                    printf("A ");
                    break;
                }
                case C:
                {
                    printf("C ");
                    break;
                }
                }
                printf("cu o capacitate de %d GB\n", p[i].caracteristica_produs.caracteristica_USB.capacitate);
                break;
            }
            case baterie:
            {
                printf("baterii cu un voltaj de %d V\n", p[i].caracteristica_produs.voltaj);
                break;
            }
            }
        }
    }
}

void stergere(Produs *produse, int size)
{
    int cod, i;
    scanf("%d", &cod);
    for (i = 0; i < size; i++)
    {
        if (produse[i].cod_unic == cod)
        {
            if (produse[i].stoc != 0)
            {
                produse[i].stoc -= 1;
            }
            else
            {
                printf("Stocul produsului cu codul unic %d este deja 0 !\n", cod);
            }
        }
    }
}

void p7()
{
    int optiune = 1, index = 0, size = 0;
    Produs *produse = NULL;
    while (optiune != 0)
    {
        printf("1-introducere\n");
        printf("2-listare\n");
        printf("3-stergere\n");
        printf("0-exit\n");
        printf("Introdu optiunea: ");
        scanf("%d", &optiune);
        switch (optiune)
        {
        case 1:
        {
            introducere(&produse, &index, &size);
            break;
        }
        case 2:
        {
            listare(produse, size);
            break;
        }
        case 3:
        {
            stergere(produse, size);
            break;
        }
        }
    }
    free(produse);
}

int main(void)
{
    // p1();
    // p2();
    // p3();
    // p4();
    // p5();
    // p6();
    p7();
    return 0;
}