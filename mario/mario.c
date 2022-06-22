#include <stdio.h>
//This is just a local copy of my implementation for CS50's Problem Set 1 pt 1.
//Another implementation will be rewritten for the submission; This is exclusively for me to
//figure out the solution.

int GetHeight();
void PrintPyramid(int h);
void PrintElements(int n, char e);

int main(void){
    int height = GetHeight();
    PrintPyramid(height);
    return 0;
}


int GetHeight(){
    int h;
    do{
        printf("Height: ");
        scanf("%i", &h);
    }while(h <= 0 || h > 8);

    return h;
}

void PrintPyramid(int h){
    //Abstracting to avoid magic numbers.
    int maxSize = 8;
    const int GAP_SPACE = 2;
    const char BLOCK = '#';
    const char SPACE = ' ';
    int numBlocks;    
    for(int i = 0; i < h; i++){
        numBlocks = i+1;
        //Leading spaces;
        PrintElements(maxSize - numBlocks, SPACE);
        //Right-aligned blocks;
        PrintElements(numBlocks, BLOCK);
        //Print the gap
        PrintElements(GAP_SPACE, SPACE);
        //Left-Aligned blocks;
        PrintElements(numBlocks, SPACE);
        //Newline
        printf("\n");
    }
    
}
void PrintElements(int n, char e){
    for (int i = 0; i < n; i++){
        printf("%c", e);
    }
}

