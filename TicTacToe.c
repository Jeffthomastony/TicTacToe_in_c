// TicTacToe Game
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char Board[3][3]={}; // To print the board
const char PLAYER = 'X'; // To select player preferred character
const char COMP = 'O'; // To select the character for the computer

// Declare the functions
void ResetBoard(); // To set and reset the board
void PrintBoard(); // To print the board
int CheckfreeSpace(); // To check if a space is free
void PlayerMove(); // For when it's players turn
void ComputerMove(); // For when it's computers turn
char CheckWinner(); // To check if someone has won
void PrintWinner(char); // To declare the winner

int main() {

    char winner=' ';
    char response = ' '; 

    do
    {
        winner = ' ';
        response = ' ';

        ResetBoard();

        while(winner == ' ' && CheckfreeSpace != 0)
        {
            PrintBoard();

            PlayerMove();
            winner = CheckWinner();
            if(winner != ' ' || CheckfreeSpace() == 0)
            {
               break; 
            }

            ComputerMove();
            winner = CheckWinner();
            if(winner!=' ' || CheckfreeSpace() == 0)
            {
               break; 
            }
        }   

        PrintBoard();
        PrintWinner(winner);

        printf("\nWould you like to play again? (Y/N): ");
        // scanf("%c");
        scanf(" %c", &response);
        response = toupper(response);

    }while(response=='Y'); // To continue the game if the player wishes to

    return 0;
}

void ResetBoard() 
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            Board[i][j]=' ';
        }
    }
}
void PrintBoard()
{
        printf(" %c | %c | %c", Board[0][0],Board[0][1],Board[0][2]);
        printf("\n---|---|---");
        printf("\n %c | %c | %c", Board[1][0],Board[1][1],Board[1][2]);
        printf("\n---|---|---");
        printf("\n %c | %c | %c", Board[2][0],Board[2][1],Board[2][2]);
        printf("\n");
}
int CheckfreeSpace() // Checks for free space after each move, whether by player or computer
{
    int freespace = 9;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(Board[i][j]!=' ')
            {
                freespace--;
            }
        }
    }
    return freespace; 
}
void PlayerMove() // Executes player's choice, unless the space is already occupied
{
    int x;
    int y;

    do{
        printf("\nEnter row #(1-3): ");
        scanf("%d",&x);
        x--;
        printf("Enter column #(1-3): ");
        scanf("%d",&y);
        y--;

        if(Board[x][y]!=' ')
        {
            printf("Invalid Move!");
        }
        else
        {
            Board[x][y]=PLAYER;
            break;
        }
    }while(Board[x][y]!=' '); 
}

void ComputerMove() // Executes computer's choice, unless the space is already occupied
{
    // Creates a random number between 0 and 3 
    srand(time(0));
    int x;
    int y;
    if(CheckfreeSpace > 0)
    {
        do{
            x = rand() % 3;
            y = rand() % 3;
        }while(Board[x][y] != ' ');

        Board[x][y]=COMP;
    }
    else
    {
        PrintWinner(' ');
    }
}

char CheckWinner()
{
    // Checks row
    for(int i=0; i<3; i++)
    {
        if(Board[i][0]==Board[i][1] && Board[i][0]==Board[i][2])
        {
            return Board[i][0];   
        }
    }
    // Check column
    for(int i=0; i<3; i++)
    {
        if(Board[0][i]==Board[1][i] && Board[0][i]==Board[2][i])
        {
            return Board[0][i];   
        }
    }
    // Check Diagonally
    if(Board[0][0]==Board[1][1] && Board[0][0]==Board[2][2])
    {
        return Board[0][0];   
    }
    if(Board[0][2]==Board[1][1] && Board[0][2]==Board[2][0])
    {
        return Board[0][2];   
    }

    return ' ';
}

void PrintWinner(char winner) 
{
    if(winner==PLAYER)
    {
        printf("YOU WIN!");
    }
    else if(winner==COMP)
    {
        printf("YOU LOSE!") ;  
    }
    else
    {
        printf("IT'S A TIE!");
    }
}
