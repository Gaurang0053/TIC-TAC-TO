#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin();
void board();

/****************************
THIS FUNCTION IS FOR THE LOADING PAGE
******************************/

void gotoxy(int x,int y)
  {
	COORD coord;
	coord.X=x;
	coord.Y=y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    }
    
int main()
{
	int r,q;
	gotoxy(50,10);
	printf("LOADING-----");
	gotoxy(50,11);
	for(r=1;r<=20;r++)
	{
		for(q=0;q<=100000000;q++);
		printf("%c",177);
		}
	
    int player = 1, i, choice;

    char mark;
    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, Enter your move number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
            
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
            
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
            
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
            
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
            
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
            
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
            
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
            
        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = checkwin();

        player++;
    }while (i ==  - 1);
        board();
    
    if (i == 1)
       {
		printf("==>\a\tPlayer %d win ", --player);
       printf("\n\n\t!!!! Congratulations Player For The Win!!!!");}
    else
        {
		printf("==>\a\tGame draw");
        printf("\n\n\t!!!!!Better Luck Next Time Players!!!!!");}   

    getch();

    return 0;
}

/***************

FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
 **************/

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
  
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
   else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}


/****************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ***************************/
void board()
{
    system("cls");
    
    printf("!!!WELCOME  PLAYERS!!! \n\n");
	printf("!!!!TO THE GAME OF TIC TAC TOE!!!!\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

/******END OF PROJECT********/

