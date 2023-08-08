#include <stdio.h>

int verificaNumeroPrimo(int n) {
    int count = 3;

    if(n%2 == 0){
        return 0;
    }

    while(count <n){
        if(n%count == 0){
            return 0;
        }
        count += 2;
    }
}

int main (){
    int n = 3;
    printf("%d eh numero primo? %d", n, verificaNumeroPrimo);
}
