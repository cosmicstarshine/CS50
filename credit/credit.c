#include<stdio.h>
#include <stdbool.h>

long long GetCardNumber();
bool ValidateChecksum(long long card, int *lead, int *numDigits);
void PrintCard(bool valid, int card, int numDigits);

int main(void){
    int leadingDigits = 0;
    int ccNumDigits = 0;
    long long cardNumber = GetCardNumber();
    bool isValid = ValidateChecksum(cardNumber, &leadingDigits, &ccNumDigits);
    PrintCard(isValid, leadingDigits, ccNumDigits);
    return 0;
}
long long GetCardNumber(){
    //This doesn't handle invalid numbers yet.
    //Solution will use <cs50.h>, and I do not know
    //How to check for input type in C yet.
    long long cardNum;
    printf("Number: ");
    scanf("%lld", &cardNum);
    return cardNum;

}

bool ValidateChecksum(long long card, int *lead, int *numDigits){    
    long long n = card;
    int doubledSum = 0;
    int singlesSum = 0;
    bool isDoubled = false;
    int counter = 0;
    //Luhn Algo.
    do{
        int digit = n%10;
        
        if(isDoubled){
            int doubledDigit = digit*2;
            if(doubledDigit >= 10){
                do{
                    doubledSum += (doubledDigit % 10);
                    doubledDigit /= 10;
                }while(doubledDigit > 0);
            }else{
                doubledSum += doubledDigit;
            }
        }else{
            singlesSum += digit;
        }
        n /=10LL;
        isDoubled = !isDoubled;
        counter++;

        //Grabbing the leading digits.
        //Not all mastercards start with 5, but for this problem, ignoring.
        if(n < 57LL &&  n > 30LL){
            *lead = (int)n;
        }    
    }while(n > 0);
    int checkSum = doubledSum + singlesSum;
    *numDigits = counter;   
    if(checkSum % 10 == 0){
        
        return true;
    }
    return false;
}
void PrintCard(bool valid, int card, int numDigits){
    //If the card fails the checksum or the leading digits do not match,
    //guard clause to escape early & avoid extra conditions check.
    //Obviously foregoing the fact that some mastercards can start with 2.
    if(!valid || card < 30){
        printf("INVALID");
        return;
    }


    //Valid checksum & card has proper leading digits:
    //Compare leading with expected number of CC digits.

    //MC check
    if(card > 50 && card < 57 && numDigits == 16){
        printf("MASTERCARD");

    //Visa check

    }else if(card > 39 && card < 50 && (numDigits == 13 || numDigits == 16)){
        printf("VISA");

    //AMEX check

    }else if((card == 34 || card == 37) && numDigits == 15)
    {
        printf("AMEX");

    //If all of these fail, assume an invalid card.
    }else{
        printf("INVALID");
    }
    return;
}