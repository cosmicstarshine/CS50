#include <stdio.h>

void Meow(int n);
int main(void){
    int num;
    printf("How many times should the cat meow?: ");
    scanf("%i", &num);
    Meow(num);
    return 0;
}

void Meow(int n){
    for(int i  = 0; i < n; i++){
        printf("Meow!\n");
    }
}