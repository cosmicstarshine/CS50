#include<stdio.h>
void DrawBlocks(int n);


int main(void){
    int size;
    do{
        printf("Size of square block: ");
        scanf("%i", &size);
    }while(size < 1);
    DrawBlocks(size);
    return 0;
}

void DrawBlocks(int n){
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("#");
        }
        printf("\n");
    }
}