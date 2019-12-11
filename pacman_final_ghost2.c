#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
//CLASS: CS133c ---- FRANKIE HERBERT
//COURSE PROJECT: FINAL PAC-MAN GAME
//HELPED WITH PROJECT: SNACK GAME (which is a separate c-file that was attached in the folder for this final), INSTRUCTOR: JESS JOSEPH, ADAM (CS FRIEND), GOOGLE ATTACHED FILES FOR MORE EXAMPLES


COORD(c) = {0, 0};
void coord_xy (int x, int y)                //To set coordinates threw game
{
 c.X = x; c.Y = y;                          //Setting x and y coordinates
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void boarder()                               //Game title and color
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    coord_xy(22,4);
    printf("PAC-MAN");
}
void display_border()                        //game boarder and color
{
 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

 int i, j;
 coord_xy(10,5);                            //Top border
 for(j=0; j<30; j++)
 printf("*", 223);

 coord_xy(10,15);                           //Bottom border
 for(j=0; j<=30; j++)
 printf("*", 223);

 for(j=0; j<10; j++)                        //Left and Right border
    {
    coord_xy(10,5+j);                       //left
    printf("*",223);

    coord_xy(40,5+j);                       //right
    printf("*",223);
    }
 printf("\n");
}
//read and write txt file for the player name.
// Use CTR + Z to end the writing for the txt file and save to txt file.
// The txt file is immediately used to display your name back to the player
 void playersname() {
        FILE * fp;
        char c;
        printf("Please enter your name?");
        //open a file
        fp = fopen("playr.txt", "w");
        //writing operation
        while ((c = getchar()) != EOF) {
            putc(c, fp);
        }
        //close file
        fclose(fp);
        printf("You have won the Game! Thank you, ");
        //reading
        fp = fopen("player.txt", "r");
        while ((c = getc(fp)) != EOF) {
            printf("%c", c);
        }
        fclose(fp);
        exit (1);
    }

int main()                                  //main game
{

 int pacmanx=15, pacmany=13, ghostx=25, ghosty=7;
 int x=25, y=10, ch1, ch2, b;

 system("cls");
 boarder();
 display_border();

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //to pull from the lib for color text
SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                                            //Create pacman character AND it's color
 coord_xy(pacmanx, pacmany);
 printf("<");

SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                                            //Create ghost character AND it's color
 coord_xy(ghostx, ghosty);
 printf("8");

 ch1 = getch();
 ch2 = 0;

 if (ch1==ch1)                               //border restriction for the game and text for game completion
 {
    while(ch2=getch())
    {
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                                            //only way to fix the color changing error
        if(ch2 == 75)                       //Left
        {
            if(pacmanx>11)                  //Restrict pacman on left side wall
            {
            coord_xy(--pacmanx,pacmany);
            printf("<");
            coord_xy(pacmanx+3,pacmany);    //Clear area for pac-man
            printf(" ");
            }
        }
        if(ch2 == 77)                       //Right
        {
            if(pacmanx<37)                  //Restrict pacman on right side wall
            {
            coord_xy(++pacmanx,pacmany);
            printf("<");
            coord_xy(pacmanx-1,pacmany);    //Clear pacman route
            printf(" ");
            }
        }
        if(ch2 == 72)                       //Up
        {
            if(pacmany>6)
            {
            coord_xy(pacmanx,--pacmany);
            printf("<");
            coord_xy(pacmanx,pacmany+1);
            printf("   ");
            }
        }
        if(ch2 == 80)                       //Down
        {
            if(pacmany<14)
            {
            coord_xy(pacmanx,++pacmany);
            printf("<");
            coord_xy(pacmanx,pacmany-1);
            printf(" ");
            }
        }
        if(pacmanx==ghostx-1 && pacmany==ghosty)  //congratulations text for eating the ghost
        {
        coord_xy(ghostx-4,ghosty+4);
        printf("Way to Go!");
        coord_xy(ghostx-9,ghosty+5);
        printf("You ate all the Ghost");
        coord_xy(ghostx-4,ghosty+6);
        printf("Game Over...");
        coord_xy(ghostx-25,ghosty+9);
        printf("");
        getch();
        playersname();                  //read and write for the players name at the end of the game
        exit(1);
        }
    }
 }
 getch();
 return 0;
}
