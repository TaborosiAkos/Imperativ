#include <stdio.h>
#include <string.h>
#include "util.h"

#define LEN 64

void count_str(){
    char str[LEN];
    fgets(str, LEN-1, stdin);
    printf("Betuk szama: %lld\n", strlen(str)-1);
    
    char prev = ' ';
    int words = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (prev == ' ' && str[i] != ' ')
        {
            ++words;
        }
        prev = str[i];
    }
    printf("Szavak szama: %d\n",words);
    
}

int strcmpSajat(char* lhs, char* rhs){
    
    while (*lhs == *rhs && *lhs != '\0')
    {
        ++lhs;
        ++rhs;
    }

    return *lhs-*rhs;
    
}

void file_print(char* fileName){
    FILE* f = fopen(fileName, "r");
    char buff[LEN];
    while (fgets(buff, LEN-1, f))
    {
        printf("%s", buff);
    }
    
}