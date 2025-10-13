#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void Random(int* t, int size){
    srand(time(NULL));

    for (size_t i = 0; i < size; i++)
    {
        int random_variable = rand();
        t[i] = random_variable % 10 + 1;
    }
    
}

int Sum(int* t, int size){
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += t[i];
    }
    return sum;
}

int Sum2(int* t, int size){
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(t+ i);
    }
    return sum;
}

int Sum3(int* first, int* last){
    int sum = 0;
    while (first != last)
    {
       sum += *first;
       ++first;
    }

    return sum;
    
}

void Str_kiir(char* str){
    while (*str != '\0')
    {
        printf("%c", *(str++));
    }
    
}

int* Legnagyobb(int* t, int size){

    int* max = t; 
    for (int i = 1; i < size; i++)
    {
        if (t[i] > * max)
        {
            max = &t[i];
        }
        
    }
    return max;
}

int main()
{
    /*
    int tomb[5] = {4, 5, 2, 3, 2};
    int sum;
    for (int i = 0; i <= 5; i++)
    {
        sum = sum + tomb[i];
    }
    printf("%d fegyverunk van!", sum);
    */
/*
    int a = 7;
    int b = 15;
    int* p = &a;
    int** pp = &p;
    printf("cim: %p, ertek: %d\n", p, *p);
    *pp = &b;
    printf("p cim: %p, ertek: %d\n", p, *p);
    *p = 9;
    printf("a: %d\n", a);
    printf("b: %d\n", b);
*/
    srand(time(NULL));
    const int size = 5;
    int t[5];
    Random(t, 5);
    for (size_t i = 0; i < size; i++)
    {
        printf("%d\n",t[i]);
    }
    printf("Sum: %d, sum3: %d \n", Sum(t, size), Sum3(t, t + size));
    Str_kiir("alma");

    int* p = NULL;
    int a = 7;
    p = &a;
    if (p != NULL)
    {
        printf("\n%d\n", *p);
    }
    int *max = Legnagyobb(t, size);
    printf("Max cime: %p erteke: %d \n", max, *max);
    
    return 0;
}