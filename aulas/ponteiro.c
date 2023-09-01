#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    int a = 3;
    int b = 7;
    int* p = &a;

    printf("a = %d\n", a);
    printf("a = %d\n", *p);
    
    int* p1;

    p1 = malloc(sizeof(int)*3);
    printf("p1 = %p\n", p1);
    printf("*p1 = %d\n", *p1);
    *p1 = 2;
    printf("*p1 = %d\n", *p1);

    p1++;
    *p1 = 5;
    printf("p1 = %p\n", p1);
    printf("*p1 = %d\n", *p1); 


    p1[1] = 7;
    printf("p1 = %p\n", &p1[1]);
    printf("*p1 = %d\n", p1[1]); 

    return 0;
}