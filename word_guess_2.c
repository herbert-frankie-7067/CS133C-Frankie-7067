#include <stdio.h>
#include <stdlib.h>
/*Frankie Herbert
Project name: Word Guess in an Array
Help from: "https://nostarch.com.com/download/JS4K_ch7.pdf (hangman how to pdf)" Instuctor Jess Joseph for question and pointers
*/

int main()
{

   int num_tries, tries, i;  // Declare the of variables
   char guess;
   char secret_library [3][6] = {{'l','a','u','g','h','\0'},{'a','b','o','u','t','\0'},{'a','d','u','l','t','\0'}};  // Initialization the of variables
   char *secret_word = secret_library[0];
   char array [5] = {'-','-','-','-','-'};


   num_tries = 0;
   i=0;
   tries = 0; //number of tries

   printf("\nLet's play hangman. Please pick a letter: "); // asking player if they would like to play and to pick a letter
   scanf("%c", &guess);

   for (i = 0; i < 4; i++)
   {
       //maybe loop over the word in a second loop

      num_tries = num_tries +1;
      if (guess == secret_word [0]) // start of the array
      {
         printf("\n %c----", secret_word [0]); // gives first letter
         printf("\nNice guess!\n");
         printf("\nPlease guess another letter: "); // tells user to guess second letter
         scanf(" %c", &guess); // finds character in array
      }

      else if ( guess == secret_word [1] ) // starts second array
      {
         printf("\n-%c---", secret_word [1]); // gives second letter in array
         printf("\nKeep going!\n");
         printf("\nPlease guess another letter: "); // tells user to guess third letter
         scanf(" %c", &guess); // finds character in array
      }
      else if ( guess == secret_word [2] ) // starts third array
      {
         printf("\n--%c--", secret_word [2]); // gives the third letter in the array
         printf("\nPlease guess another letter: "); // tells user to guess fourth letter
         scanf(" %c", &guess);
      }

      else if ( guess == secret_word [3] ) // starts the fourth array
      {
         printf("\n---%c-", secret_word [3]); // give the fourth letter
         printf("\nPlease guess another letter: "); // asks user to guess the fifth array
         scanf(" %c", &guess);
      }

      else if ( guess == secret_word [4] ) // starts fifth array
      {
         printf("\n----%c", secret_word [4]); // asks user for the fifth letter
         printf("\nWay to go!\n");
         printf("\nPlease guess another letter: ");
         scanf(" %c", &guess);
         printf("\nCongrats! You guessed the secret word!\n", secret_word[4]);
         scanf("%c%c%c%c%c", &secret_word);
         break;
      }

      if ( guess != secret_word ) // if the secret_word does not match the guess then say no
      {
         printf("\nNope! Please keep trying...\n"); // tells the user that this is not a correct letter and asks user to keep going
         scanf(" %c", &guess);

      }
   }
   return 0;
}
