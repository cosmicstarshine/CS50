#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

//Determine grade level using Coleman-Liau index.
//index = 0.0588 * L - 0.296 * S - 15.8, where:
//L is the average number of letters per 100 words in the text and
//S is the average number of sentences per 100 words.

//For the purposes of the assignment, ignore the fact that periods don't always end a sentence.
//Consider any punctuation marks to be the end of a sentence.
//Assume that a sentence will not have multiple spaces in a row.

//Flow:
//Get string input.
//Count the number of letters.
//Count the number of words.
//Count the number of sentences.


void getString(char **str);
int countLetters(char text[]);
int countWords(char text[]);
int countSentences(char text[]);
int calculateGradeIndex(int l, int w, int s);
void printGradeLevel(int index);

int main(void){
    //initializing a string
    char *string;
    //Read the input.
    getString(&string);
    int numLetters = countLetters(string);
    int numWords = countWords(string);
    int numSentences = countSentences(string);
    int gradeIndex = calculateGradeIndex(numLetters, numWords, numSentences);
    printGradeLevel(gradeIndex);
    return 0;
}

void getString(char **str){
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

int countLetters(char text[]){
    int counter = 0;
    for(int i = 0; text[i] != '\0'; i++){
        if(isalpha(text[i])){
            counter++;
        }
    }
    return counter;
}

int countWords(char text[]){
    int counter = 0;
    for(int i = 0; text[i] != '\0'; i++){
        if(text[i]== ' '){
            counter++;
        }
    }
    //Counter plus one due to break @ null char.
    return counter+1;
}
int countSentences(char text[]){
    int counter = 0;
    for(int i = 0; text[i]!='\0'; i++){
        if(text[i]=='.'|| text[i] == '!'|| text[i] == '?'){
            counter++;
        }
    }
    return counter;
}
int calculateGradeIndex(int l, int w, int s){
    float letterAvg = ((float)l / w)*100;
    
    float sentAvg = ((float)s / w) * 100;
    return (int)round(0.0588 * letterAvg - 0.296 * sentAvg-15.8);

}

void printGradeLevel(int index){
    if(index >=16){
        printf("Grade 16+");
    }else if(index <=0){
        printf("Before Grade 1");
    }else{
        printf("Grade %i", index);
    }
    return;
}


