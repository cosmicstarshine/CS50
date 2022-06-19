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

    return 0;
}

bool validateChecksum(long card){
    const int COMPAREVALUE = 20;
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
    if(checkSum == COMPAREVALUE){
        return true;
    }
    return false;
}
void PrintCard(bool valid, long card){
    if(!valid){
        printf("INVALID");
        return 0;
    }

    //FIGURE OUT THIS PART.
}