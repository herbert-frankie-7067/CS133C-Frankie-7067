#include<stdio.h>
#include<time.h>
#include<stdlib.h>
// help with project: c++ for beginners google
// instructor Joseph Jess, Adam Collins (intel worker and friend) and a ton of projects that was worked on but deleted...
/*
This calls the main function
sets for a range of numbers between 1 and 20
asks user if they would like to play a game guessing a number between that range
tell the user when their guess is to high
tell the user when their guess is to low
if the user got the number right on the dot then the game will stop.
*/
int main()
{
    int number;
    int guess;
    int tries = 0;
    char try_again;


    srand(time(0));
    number = rand() %20 + 1;

    printf("I am thinking of a number between 1 and 20: \n\n");
    do
    {
        printf("what will your guess be? ");
        scanf("%d", &guess);
        tries ++;


        if (guess > number)
        printf("That was to high. please pick again: \n\n");

        else if (guess < number)
        printf("That was to low. please pick again: \n\n");

        else
            printf("\nThat was right on the dot");
    }while (guess != number);




    return 0;
}


