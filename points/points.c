#include <stdio.h>
int main(void)
{
    int points;
    const int MYPOINTS = 2;
    printf("How many points did you lose?: ");
    scanf("%i", &points);
    if(points < MYPOINTS)
    {
        printf("You lost fewer points than I did. \n");
    }
    else if(points > MYPOINTS){
        printf("You lost more points than I did. \n");
    }
    else{
        printf("You lost the same number of points that I did");
    }
    return 0;
}