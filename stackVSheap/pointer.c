#include <stdlib.h>
#include <stdio.h>

int* x(){
    int* arr;
    arr = (int*)malloc(5*sizeof(int));
    for(int i=0;i<5;i++){
        arr[i]=i;
    }
    return arr;
}

int main() {
    // Write C code here
    int* arr = x();
    for(int i=0;i<5;i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}