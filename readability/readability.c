#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



void GetString(char **str);
int CountLetters(char text[]);
int CountWords(char text[]);
int CoundSentences(char text[]);
int CalculateGradeIndex(int l, int w, int s);
void PrintGradeLevel(int index);

int main(void){
    //initializing a string
    char *string;
    //Read the input.
    GetString(&string);
    int numLetters = CountLetters(string);
    int numWords = CountWords(string);
    int numSentences = CoundSentences(string);
    int gradeIndex = CalculateGradeIndex(numLetters, numWords, numSentences);
    PrintGradeLevel(gradeIndex);
    return 0;
}

void GetString(char **str){
    char tmp[500];
    int arrSize = 1;
    printf("Text: ");
    fgets(tmp, sizeof tmp, stdin);
    for(int i = 0; tmp[i]!= '\0'; i++){
        arrSize ++;
    }
    *str = (char *) malloc(arrSize * sizeof(char));
     //This should copy over the null character.
    strncpy(*str, tmp, arrSize);
}

int CountLetters(char text[]){
    int counter = 0;
    for(int i = 0; text[i] != '\0'; i++){
        if(isalpha(text[i])){
            counter++;
        }
    }
    return counter;
}

int CountWords(char text[]){
    int counter = 0;
    for(int i = 0; text[i] != '\0'; i++){
        if(text[i]== ' '){
            counter++;
        }
    }
    //Counter plus one due to break @ null char.
    return counter+1;
}
int CoundSentences(char text[]){
    int counter = 0;
    for(int i = 0; text[i]!='\0'; i++){
        if(text[i]=='.'|| text[i] == '!'|| text[i] == '?'){
            counter++;
        }
    }
    return counter;
}
int CalculateGradeIndex(int l, int w, int s){
    float letterAvg = ((float)l / w)*100;
    
    float sentAvg = ((float)s / w) * 100;
    return (int)round(0.0588 * letterAvg - 0.296 * sentAvg-15.8);

}

void PrintGradeLevel(int index){
    if(index >=16){
        printf("Grade 16+");
    }else if(index <=0){
        printf("Before Grade 1");
    }else{
        printf("Grade %i", index);
    }
    return;
}


