#include <stdio.h>

int fib(int n){
    if(n < 2){
        return n;
    }else{
        return fib(n - 2) + fib(n - 1);
    }
}

void elore(int *t, int meret){
    if(meret == 0){
        return;
    }else{
        printf("%d, ", t[meret - 1]);
        elore(t, meret - 1);
        return;
    }
}

void hatra(int *t, int meret){
    if(meret == 0){
        return;
    }else{
        elore(t, meret - 1);
        printf("%d, ", t[meret - 1]);
        return;
    }
}

void szamrendszer(int a, int r){

}

int main()
{
    printf("%d\n", fib(45));
    int t[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    elore(t, 10);
    printf("\n");
    hatra(t, 10);
}
