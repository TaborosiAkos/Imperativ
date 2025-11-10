#include <stdio.h>
#include <string.h>
#include "util.h"

int main()
{
    int menu = -1;
    while (menu != 0)
    {
        printf("MENU\n\t1: KisZH\n\t2: Betu/szo szamlalo\n\t 0:Kilepes \n");
        scanf("%d\n", &menu);
        getchar();
        switch (menu)
    {
    case 1:
        printf("Hello\n");
        break;
    
    case 0:
        printf("Cso\n");
        break;
    case 2:
        count_str();
        break;
    case 3:
        printf("%d \n", strcmpSajat("alma", "korte"));
        break;
    case 4:
        file_print("input.txt");
        break;
    default:
        printf("Gatya\n");
        break;
    }
    }
    
}