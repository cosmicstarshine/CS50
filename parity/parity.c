#include<stdio.h>

int main(void){
    int numberToTest;
    printf("Enter a number and I'll tell you if it's even or odd: ");
    scanf("%i", &numberToTest);

    if(numberToTest % 2 == 0)
    {
        printf("%i, is an even number", numberToTest);
    }
    else
    {
        printf("%i, is an odd number", numberToTest);
    }
    return 0;
}