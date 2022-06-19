#include<stdio.h>
#include <stdbool.h>

// finish later.
// Get user input for a long.
//Verify with checksum: n%10, n/=10 loop. LUHN's ALGO.
//If invalid, return.
//Else:
//FIGURE out how to get the first digits of a long.
//Check for VISA/AMEX/MC
//Return.
//Print info to console.
long GetCardNumber();
bool validateChecksum(long card);
void PrintCard(bool valid, long card);

int main(void){
    int cardNumber = GetCardNumber();
    bool isValid = validateChecksum(cardNumber);
    printCard(isValid);
    return 0;
}
long GetCardNumber(){
    //This doesn't handle invalid numbers yet.
    //Solution will use <cs50.h>, and I do not know
    //How to check for type in C yet.
    long cardNum;
    printf("Number: ");
    scanf("%li", & cardNum);
    return cardNum;

}

bool validateChecksum(long card){    
    long n = card;
    int doubledSum = 0;
    int singlesSum = 0;
    bool isDoubled = false;
    //Luhn Algo.
    do{
        int digit = n%10;
        if(isDoubled){
            doubledSum += (digit*2);
        }else{
            singlesSum += digit;
        }
        n /=10;
        isDoubled = !isDoubled;

    }while(n > 0);
    int checkSum = doubledSum + singlesSum;
    if(checkSum % 10 == 0){
        return true;
    }
    return false;
}
void PrintCard(bool valid, long card){
    if(!valid){
        printf("INVALID");
        return 0;
    }else{
        printf("VALID CARD");
    }
    //FIGURE OUT THIS PART.
}