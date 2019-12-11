#include <stdio.h>
#include <stdlib.h>
//Class: CS133c---- FRANKIE HERBERT
//INSTRUCTOR: JESS JOSEPH,
//HELPED WITH PROJECT: CLASS NOTES AND VIDEOS AND WEB

struct Pies //create the structure for the class
{
    char pie[30];  //set pies
    int price;  //initializes the price the pie
};

int main()  //main
{
    struct Pies *pstd;
    int n,i;

    printf("Enter number of Pies you would like: ");
    scanf("%d",&n);

    pstd=(struct Pies*)malloc(n*sizeof(struct Pies)); //dynamic memory for the pies

for(i=0; i<n; i++) //All set for the read and printing of information
    {
        printf("\nEnter detail of Pies [%2d]:\n",i+1);
        printf("The flavor of the Pie: ");
        scanf(" "); //clear
        gets((pstd+i)->pie);
        printf("The Price of the Pie is: ");
        scanf("%d",&(pstd+i)->price);
    }
    printf("\nPie details are:\n");  //Ready to pull together and set the details of the array to memory
    for(i=0; i<n; i++)
    {
        printf("%20s \t %2d \t\n",(pstd+i)->pie,(pstd+i)->price); // all information placed together from gathered data written.
    }

    return 0;
}
