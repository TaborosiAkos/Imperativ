#include <stdlib.h>
#include "head.h"
int main(){
    PageT page = ebook_create_page_from_file("piszkos_fred_elso_fejezet.ebook1", 1);
    ebook_print_page(page, 60);
    free(page.str);
    return 0;
}