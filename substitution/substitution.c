#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool CheckKey(char *str, int numArgs);
//I could just include this, but I am lazy and will have to re-implement using
//CS50 header anyway.
void GetString(char **str);
void PrintCipher(char *str, char *alpha, char *key);

int main(int argc, char *argv[])
{
    //Validate key argument
    bool keyCheckValid = CheckKey(argv[1], argc);
    char alphaText[] = {'a', 'b', 'c', 'd', 'e',
                        'f', 'g', 'h', 'i', 'j',
                        'k', 'l', 'm', 'n', 'o', 
                        'p', 'q', 'r', 's', 't',
                        'u', 'v', 'w', 'x', 'y', 'z'};
    //error handling - escape the program if the key is invalid.
    if(!keyCheckValid)
    {
        return 1;
    }
    //initialize input
    char *string;
    //get input
    GetString(&string);
    //print according to the supplied key
    PrintCipher(string, alphaText, argv[1]);
    return 0;
    
}

bool CheckKey(char *str, int numArgs)
{
    //using a counter to check the number of letters in the key.
    //Argument array is of fixed length, so cannot calculate.
    int counter = 0;
    //Too few/many args.
    if (numArgs <= 1 || numArgs > 2)
    {
        printf("Usage: ./substitution key. \n");
        return false;
    }
    else
    {
        //Loop through the string, counting the numbers,
        //Checking for all alphanumeric
        //Then a nexted loop to check for duplicates.
        for (int i = 0; str[i] != '\0'; i++)
        {
            counter ++;
            if (isalpha(str[i]) == 0)
                {
                    printf("Usage: Key must be alphanumeric\n");
                    return false;
                }
            for (int j = 0; str[j] != '\0'; j++)
            {
                if (i == j)
                {
                    //If the same index, continue onto the next iteration.
                    continue;
                }
                
                if (str[i] == str[j])
                {
                    printf("Error: Duplicate letters in key.\n");
                    return false;
                }
            }
        }
        if (counter != 26)
        {
            printf("Error: Key must contain 26 characters\n");
            return false;
        }
    }

    //If the key is valid, return true to continue with the program.
    return true;
}
void GetString(char **str){
    char tmp[500];
    int arrSize = 1;
    printf("plaintext: ");
    fgets(tmp, sizeof tmp, stdin);
    for (int i = 0; tmp[i]!= '\0'; i++)
    {
        arrSize ++;
    }
    *str = (char *) malloc(arrSize * sizeof(char));
     //This should copy over the null character.
    strncpy(*str, tmp, arrSize);
}

void PrintCipher(char *str, char *alpha, char *key)
{
    //This is according to CS50 requests
    printf("ciphertext: ");
    //loop through input string, checking the character against
    //the alphakey (a poor man's dictionary);
    //Set the index when the character is matched.
    int index = 0;
    //Controlling for letter case.
    bool upperCase = false;
    for (int i = 0; str[i] != '\0'; i++)
    {
        //Initial conditions check to only proceed with alpha chars.
        if (isalpha(str[i]))
        {
            //Set the casing flag.
            if (isupper(str[i]))
            {
                upperCase = true;
            }
            else
            {
                upperCase = false;
            }
            //Grab the index.
            for (int j = 0; alpha[j] != '\0'; j++)
            {
                if (tolower(str[i]) == alpha[j])
                {
                    index = j;
                }
            }
            //If upper/lower, use the index to print from the key
            //at the cipher's index.
            if (upperCase)
            {
                printf("%c", toupper(key[index]));
            }
            else
            {
                printf("%c", tolower(key[index]));
            }
        }
        else 
        {
            printf("%c", str[i]);
        }
    }
    //End with a newline.
    printf("\n");
}