#ifndef HEAD_H
#define HEAD_H

typedef struct Page
{
    int pageNum;
    char* str;

} PageT;

typedef struct Ebook
{
    PageT* pages;
    unsigned int lastPage;
    unsigned int currentPage;
    int lineLen;
} EbookT;


PageT ebook_create_page_from_file(char* fileName, int pageNumber);
void ebook_print_page(PageT page, int lineLen);
EbookT ebook_create_from_file(char* fileName, int pageNumber);

#endif