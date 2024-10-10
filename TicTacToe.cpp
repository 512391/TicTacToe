/*
  Author: Jay Williamson
  Date: 9/5/2024
  This program plays tictactoe with 2 people and once the game has ended you can choose to play again and it will keep track of your scores
 */
#include <iostream>

using namespace std;

//Checks whether there is a three in a row with a certain character
bool has3InARow(char board[3][3], char c)
{
  //checks horizontals and verticals
  for(int i = 0; i < 3; i++)
    {
      //checks verticals
      if(board[0][i] == c && board[1][i] == c && board[2][i] == c)
        {
          return true;
        }
      //checks horizontals
      if(board[i][0] == c && board[i][1] == c && board[i][2] == c)
        {
          return true;
        }
    }
  //checks upper left to bottom right diagonal
  if(board[0][0] == c && board[1][1] == c && board[2][2] == c)
    {
      return true;
    }
  //checks upper right to lower left diagonal
   if(board[2][0] == c && board[1][1] == c && board[0][2] == c)
    {
      return true;
    }

   return false;
}

//Checks which character has won
char hasWon(char board[3][3])
{
  //checks for xs
  if(has3InARow(board, 'X'))
    {
      return 'X';
    }
  //checks for os
  if(has3InARow(board, 'O'))
    {
      return 'O';
    }

  
  return 'A';
}

//prints board
void printBoard(char board[3][3])
{
  cout << "\n" << "\n";
  cout << " 123 \n";
  cout <<"A" << board[0][0] << board[0][1] << board[0][2] << "\n";
  cout <<"B" << board[1][0] << board[1][1] << board[1][2] << "\n";
  cout <<"C" << board[2][0] << board[2][1] << board[2][2] << "\n";
}

//This is in charge of the general game flow
int gameLoop(int xwins, int owins)
{
  //prints initial wins and losses
  cout << "\n" << "\n";
  cout << "Enter a capital Z at any time to end the program \n";
  cout << "X wins: " << xwins << " O wins: " << owins << "\n";
  
  char board[3][3];

  int turns = 0;

  //clears the board and makes sure everything is just an underscore
  for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
        {
	  board[i][j] = '_';
        }

    }
  board[0][0] = '_';
  
  char whoWon;
  char currentPlayer = 'X';

  //while loop that controls turns
  while((whoWon = hasWon(board)) == 'A' && turns < 9)
    { 
      printBoard(board);
      
      cout << "play a move \n";

      char position[3];

      cin >> position;

      // if it is a Z it allows you to exit the game
      if(position[0] == 'Z')
	{
	  return 0;
	}

      //gets the indicies from the input
      int indexA = (int)tolower(position[0])-97;
      int indexB = (int)position[1]-49;

      //checks if the indicies are in range
      if(indexA < 3 && indexB < 3 && indexA > -1 && indexB > -1)
	{
	  //checks if the place you are putting a character is open
	  if(board[indexA][indexB] == '_')
	    {
	      //places the character
	      board[indexA][indexB] = currentPlayer;

	      //changes whose turn it is
	      if(currentPlayer == 'X')
                {
                   currentPlayer = 'O';
                }
              else
                {
                   currentPlayer = 'X';
                }
	      //adds to the turns to check for ties
                  turns++;
	    }
	  else
	    {
	      cout << "invalid input";
	    }
	}
      else
	{
	  cout << "invalid input";
	}
    }

  printBoard(board);
  
  //check who won and who to give the point to
  if(whoWon == 'X')
    {
      xwins++;
      cout << whoWon << " won \n";
    }
  else if(whoWon == 'O')
    {
      owins++;
      cout << whoWon << " won \n";
    }//checks if it is a tie
  else if(whoWon == 'A')
    {
      cout << "tie \n";
    }
  //prints wins
  cout << "X wins: " << xwins << " O wins: " << owins << "\n";

  //checks if you want to play again
  cout << "play again?(y/n)";

  char ans = ' ';

  cin >> ans;

  //check to see if you want to play again
  if(ans == 'y')
    {
      gameLoop(xwins, owins);
    }
  
  return 0;
}

//starts the game loop
int main()
{
  gameLoop(0,0);

  return 0;
}
