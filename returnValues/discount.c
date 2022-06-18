#include <stdio.h>

float DiscountPrice(float price, float discount);

int main(void){
    float regPrice;
    int percentOff;
    printf("What is the regular price?: $");
    scanf("%f", &regPrice);
    printf("What's the percent off?: ");
    scanf("%i", &percentOff);

    float salePrice = DiscountPrice(regPrice, percentOff);
    printf("The sale price is: $%.2f", salePrice);
    return 0;
}
float DiscountPrice(float price, float discount){
    return price * (100-discount)/100;
}