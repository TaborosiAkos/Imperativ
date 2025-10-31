#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 7
#define COLS 10
#define CHANCE 15

void dwarf_init(){
    srand(time(NULL));
}


void map_init(char terkep[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int r = rand() % 100 + 1;
            if ( r <= CHANCE )
            {
                terkep[i][j] = 'X';
            }else{
               terkep[i][j] = '-';
            }
        }
        
    }
    
}

void map_print(char terkep[ROWS][COLS]){
    char borderRow[COLS + 2];

    // Keret feltöltése
    for (int i = 0; i < COLS + 2; i++)
    {
        borderRow[i] = '*';
    }

    // Felső keret kiírása
    for (int i = 0; i < COLS + 2; i++)
    {
        printf("%c ", borderRow[i]);
    }
    printf("\n");

    // Térkép kiírása
    for (int i = 0; i < ROWS; i++)
    {
        
        for (int j = 0; j < COLS + 2; j++)
        {
            if (j == 0 || j == COLS + 1)
                printf("%c ", '*');
            else
                printf("%c ", terkep[i][j - 1]);
        }
        printf("\n");
    }
    // Alsó keret kiírása
    for (int i = 0; i < COLS + 2; i++)
    {
        printf("%c ", borderRow[i]);
    }
    printf("\n");
}

int main() {
    char terkep[ROWS][COLS];
    dwarf_init();
    map_init(terkep);
    map_print(terkep);
    return 0;
}