#include <stdio.h>
#include "buszmeg.h"

#define MAX_LEN 100
int main(){

    printf("Ez egy buszmegallo cucc! \n"
           "Menu: \n");
    printf("1, Terkep \n 2, Lista \n 3, Uj megallo, \n 4, Megallo torlese \n 5, Mentes \n 6, Betoltes \n 7, Utvonal \n 8, Kilepes");
    int menu = 0;
    Megallo_t* megallok[MAX_LEN];
    int acLen = 0;
    while (menu != 8)
    {
        scanf("%d", &menu);
        getc( );
        switch (menu)
    {
    case 1:
        show_map(megallok, acLen);
        break;
    case 2:
        print_bus_stop(megallok, acLen);
        break;
    case 3:
        if (acLen < MAX_LEN)
        {
            megallok[acLen] = create_bus_stop();
            acLen++;
        }else{
            printf("Ez bizony tele van!");
        }
        
        break;
    case 4:
        
        break;
    case 5:
        
        break;
    case 6:
        
        break;
    case 7:
        
        break;
    case 8:
        
        break;
    default:
        printf("Hibas bemenet!");
        break;
    }
        
    }
    

    return 0;
}