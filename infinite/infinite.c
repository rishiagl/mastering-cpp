#include <stdio.h>

int main(){
    printf("Infinite loop is running\n");
    for(int i = 0;;i++){
        printf("%s %d ", "Infinite ", i);
    }
}