#include <stdio.h>
#include <math.h>


int strLen(char* str){
    int size = 0;
    while (*str != '\0')
    {
        ++str;
        ++size;
    }

    return size;
    
}

int hex_to_dec(char* str)
{
    int size = strLen(str);
    int result = 0;
    int dec;
    for (int i = 0; i < size; i++)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            dec = str[i] - '0';    
        }
        else
        {
            dec = str[i] - 'a' + 10;
        }
        
         result += str[i] * pow(16, size - i - 1);
        
    }
    return result;
    
}


void SzorzoTabla(int t[5][7]){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            t[i][j] = i * j;
        }
        
    }
    
}

int Hatvany(int szam, int mennyi){
    int hatvany = 0;
    while (mennyi != 0)
    {
        hatvany = hatvany * mennyi;
        Hatvany(hatvany, mennyi-1);
    }
    return hatvany;
}

int main(int argc, char* argv[])
{
    //printf("A main fuggvenynek %d bemenete van.\n", argc);
    //for (int i = 0; i < argc; i++)
    //{
    //        printf("%s \n", argv[i]);
    //}
    
    /*char str[100];
    scanf("%s", str);
    printf("%s", str);
    */
    /*
    int tomb[5][7];
    SzorzoTabla(tomb, 5, 7);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("%d",tomb[i][j]);
        }
        printf("\n");
    }
    return 0;
    */
// szám hatványai
// db szám
int alap = argv[1][0] - '0';
int kitevo = argv[2][0] - '0';

printf("%d", Hatvany(alap, kitevo));

}
