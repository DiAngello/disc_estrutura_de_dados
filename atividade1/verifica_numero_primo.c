#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int n, i;

    n = atoi(argv[1]);

    if(n=1){
        printf("0");
    }else{
        for(i=3; i < n; i+=2){
            if(n%i==0){
                printf("0");
                break;
            }
        }
        if(i==n){
            printf("1");
        }
    }
    return 0;
}
