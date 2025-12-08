#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "head.h"

#define LEN 100
#define TERMINAL_CLEAR "\033[2J"
#define TERMINAL_HOME "\033[2H"
#define LINE_LEN 40


PageT ebook_create_page_from_file(char* fileName, int pageNumber){
    FILE* file = fopen(fileName, "r");
    PageT result;
    result.pageNum = pageNumber;
    result.str = NULL;

    char buff[LEN];

    while (fgets(buff, LEN, file) != NULL)
    {
        
        realloc(result.str, (strnlen_s(result.str, 100000) * sizeof(char)) + strlen(buff) + sizeof(char));
        strcat(result.str, buff);
    }
    
    char* newLine;
    while (newLine = strchr(newLine, '\n') != NULL)
    {
        *newLine = ' ';
    }
    return result;
}

void ebook_print_page(PageT page, int lineLen){
    printf("%s%s", TERMINAL_CLEAR, TERMINAL_HOME);
    int counter = 0;
    while (page.str != '\0')
    {
        if (counter >= lineLen && *page.str == ' ')
        {
            fputc(*page.str, stdout);
            counter = 0;
        }else{
            fputc(*page.str, stdout);
            counter++;
        }
        ++page.str;

    }
    
}

EbookT ebook_create_from_file(char* fileName, int pageNumber){
    char fname[LEN];
    EbookT res;
    res.lastPage = pageNumber;
    res.pages = malloc(sizeof(PageT) * pageNumber);
    res.currentPage = 0;
    res.lineLen = LINE_LEN;
    for (int i = 0; i < pageNumber; i++)
    {
        sprintf(fname, "%s.ebook%d", fileName, i);
        res.pages[i] = ebook_create_page_from_file(fname, i);
    }
    return res;
}