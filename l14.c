#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFERSIZE 100

void lowercaseFile(const char *filepath)
{
    FILE *f;
    int i, r;
    char buffer[BUFFERSIZE];
    if ((f = fopen(filepath, "rb")) == NULL)
    {
        perror(filepath);
        exit(-2);
    }

    while ((r = fread(buffer, sizeof(char), BUFFERSIZE, f)) > 0)
    {
        for (i = 0; i < r; i++)
        {
            printf("%c", tolower(buffer[i]));
        }
    }

    printf("\n");

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-2);
    }
}

void uppercaseFile(const char *filepath)
{
    FILE *f;
    int i, r;
    char buffer[BUFFERSIZE];
    if ((f = fopen(filepath, "rb")) == NULL)
    {
        perror(filepath);
        exit(-2);
    }

    while ((r = fread(buffer, sizeof(char), BUFFERSIZE, f)) > 0)
    {
        for (i = 0; i < r; i++)
        {
            printf("%c", toupper(buffer[i]));
        }
    }

    printf("\n");

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-2);
    }
}

void originalFile(const char *filepath)
{
    FILE *f;
    int i, r;
    char buffer[BUFFERSIZE];
    if ((f = fopen(filepath, "rb")) == NULL)
    {
        perror(filepath);
        exit(-2);
    }

    while ((r = fread(buffer, sizeof(char), BUFFERSIZE, f)) > 0)
    {
        for(i = 0; i < r; i++)
        {
            printf("%c", buffer[i]);
        }
    }

    printf("\n");

    if (fclose(f) != 0)
    {
        perror(NULL);
        exit(-2);
    }
}

int main(int argc, char **argv)
{
    int i;
    if (argc < 2)
    {
        fprintf(stderr, "Eroare la argumente\n");
        exit(-1);
    }

    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-l") == 0)
        {
            i += 1;
            lowercaseFile(argv[i]);
        }
        else
        {
            if (strcmp(argv[i], "-u") == 0)
            {
                i += 1;
                uppercaseFile(argv[i]);
            }
            else
            {
                if (strcmp(argv[i], "-o") == 0)
                {
                    i += 1;
                }
                originalFile(argv[i]);
            }
        }
    }
}