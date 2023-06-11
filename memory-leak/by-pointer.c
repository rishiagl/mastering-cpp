/*
-> when func goes out of scope still c points to location of d;
-> this address can now be picked by steal function.
-> this is just one of the implementation, there can be many
-> there are some statements which are commented, uncommenting them can produce unexpected result
    in the execution of the code, please check them out.*/
#include<stdio.h>
#include<stdlib.h>

int *c;
void func(int *a,int *b){
    int j = 5;
    int d = (*a) + (*b);
    c = &d;
    //*c =  (*a) + (*b);
}

void steal(){
    //printf("let's steal\n");
    int h =7;
    //printf("let's steal\n");
}

int main(){
    int a = 3,b = 9;
    //c = malloc(sizeof(int));
    func(&a, &b);
    steal();
    printf("%d\n", *c);
    return 0;
}