#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void GetString(char ** str);
int ComputeScore(char *word);
void DisplayWinner(int s1, int s2);

const int POINTS[] ={1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const char KEY[] = {'a','b', 'c', 'd', 'e', 
                    'f', 'g', 'h', 'i', 'j', 
                    'k', 'l', 'm', 'n', 'o', 
                    'p', 'q', 'r', 's', 't', 
                    'u', 'v', 'w', 'x', 'y', 'z'};

int main(void){

    char *word1;
    char *word2;
    //Not the most ideal & could be abstracted into a function
    //This is mostly just to replicate the functionality of CS50's
    //get_string function included in cs50.h.
    printf("Player 1: ");
    GetString(&word1);
    printf("\n");
    printf("Player2: ");
    GetString(&word2);
    printf("\n");

    int score1 = ComputeScore(word1);
    int score2 = ComputeScore(word2);

    DisplayWinner(score1, score2);

    return 0;
}



void GetString(char **str){
    char tmp[500];
    int arrSize = 1;
    fgets(tmp, sizeof tmp, stdin);
    for(int i = 0; tmp[i]!= '\0'; i++){
        arrSize ++;
    }
    *str = (char *) malloc(arrSize * sizeof(char));
    strncpy(*str, tmp, arrSize);
}
//Not the most ideal for time complexity, but this is a working solution.
//Compare the word against the character key.
//If a match, use the index of the key to add the appropriate amount of points to
//the score.
int ComputeScore(char *word){
    int score = 0;
    for(int i = 0; word[i] != '\0'; i++){
        for(int j = 0; KEY[j] != '\0'; j++){
            if(tolower(word[i]) == KEY[j]){
                score += POINTS[j];
            }
        }
    }
    return score;

}

void DisplayWinner(int s1, int s2){
    if(s1 == s2){
        printf("TIE!\n");
    }
    else if(s1 > s2){
        printf("Player 1 wins!");
    }else{
        printf("Player 2 wins!");
    }
    return;
}

