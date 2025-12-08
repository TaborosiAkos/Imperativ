#include "buszmeg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

void show_map(Megallo_t* tomb, int size){
    char terkep[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            terkep[i][j] = ' ';
        }
        
    }

    for (int i = 0; i < size; i++)
    {
        terkep[tomb[i].x][tomb[i].y] = "B";
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            putc(terkep[i][j], stdout);
        }
        putc("\n", stdout);
    }
    
}

void print_bus_stop(Megallo_t* tomb, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d: %s (%d, %d)", i+1, tomb[i].nev, tomb[i].x, tomb[i].y);
    }
    
}

Megallo_t* create_bus_stop(){
    Megallo_t* ujMegallo = malloc(sizeof(Megallo_t));
    char buff[SIZE];
    printf("Add meg a nevet: \n");
    fgets(buff, SIZE, stdin);
    ujMegallo->nev = malloc(strlen(buff) * sizeof(char));
    strcpy(ujMegallo->nev, buff);
    ujMegallo->x = 11;
    ujMegallo->y = 11;
    while (ujMegallo->x < 0 || 9 < ujMegallo->x)
    {
        printf("Add meg az x koordinatat\n");
        scanf("%d", &ujMegallo->x);
    }

    while (ujMegallo->x < 0 || 9 < ujMegallo->x)
    {
        printf("Add meg az y koordinatat\n");
        scanf("%d", &ujMegallo->y);
    }
}


void delete_bus_stop(Megallo_t* tomb, int size){
    print_bus_stop(tomb, size);
    printf("Melyiket toroljuk? \n");

    int sorszam;
    scanf("%d", sorszam);

    free(tomb[sorszam].nev);
    free(tomb[sorszam]);

    for (int i = sorszam; i < size-1; i++)
    {
        tomb[i] = tomb[i+1];
    }
    
}

void save_list(Megallo_t* tomb, int size){

    if (size == 0)
    {
        printf("A lista uraes!");
    }

    printf("Adj meg egy fajlnevet \n");
    char filename[SIZE];
    fgets(filename, SIZE, stdin);
    FILE* f = fopen(filename, "w");
    for (int i = 0; i < size; i++)
    {
        fputs(tomb[i].nev, f);
        fprintf(f, "% %\n", tomb[i])
    }
    
    
}