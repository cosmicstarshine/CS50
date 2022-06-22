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
    const int maxSize = 8;
    const int gapSpace = 2;
    const char block = '#';
    const char space = ' ';
    int numBlocks;    
    for(int i = 0; i < h; i++){
        numBlocks = i+1;
        //Leading spaces;
        PrintElements(maxSize - numBlocks, space);
        //Right-aligned blocks;
        PrintElements(numBlocks, block);
        //Print the gap
        PrintElements(gapSpace, space);
        //Left-Aligned blocks;
        PrintElements(numBlocks, block);
        //Newline
        printf("\n");
    }
    
}
void PrintElements(int n, char e){
    for (int i = 0; i < n; i++){
        printf("%c", e);
    }
}

