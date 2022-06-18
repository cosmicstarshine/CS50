#include <stdio.h>
//The CS50 example did not include ctype for the tolower method
//Instead, used c == Y || c == y
#include <ctype.h>

int main(void){
    char c;

    printf("QUESTION TO AGREE WITH? Y/N: ");
    scanf("%c", &c);
    c = tolower(c);

    while(c != 'y' && c != 'n'){
        printf("Please enter Y/N\n QUESTION TO AGREE WITH? Y/N: ");
        scanf(" %c", &c);
        c = tolower(c);
    }
    if(c == 'y'){
        printf("Agreed");
    }else{
        printf("Disagreed");
    }
    return 0;

    //Not sure yet how to declare functions within the module, lol. This could be refactored to repeatedly call a function.
}