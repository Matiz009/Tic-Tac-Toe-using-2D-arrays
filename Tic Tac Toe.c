
#include<stdio.h>		//header files
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>


char tac[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };//2D array 

void displayTable ();
bool moveFunction (int x, int y);         //functions decleration
bool winFunction (int x, int y);



int main ()                               //main method
{

  int x, y;
  int Num = 0;                            //variable decleration
  srand (time (0));
  bool condition = true;
  Sleep (1000);
  printf ("\t\t\t\t**Tic Tac Toe**\n");
  printf ("\t\t\t\tPlayer will play as:\tP\n");             //Menu Printing
  printf ("\t\t\t\tComputer will play as:\tC\t\n");
  Sleep (500);
  while (condition)                                         //checking condition
    {
      if (Num % 2 == 0)
	{
	  printf ("\t\t\t\tPlayer turn:\n\t\t\t\t");
	  printf("\t\t Player Playing as : P\n");
	  printf("\t\t\t\t\t\t Computer Playing as : C\n");
	  Sleep (450);                                             //<----- This will clear the screen
	  displayTable ();
	  printf ("Enter the move in 01-22-11-10 format:\t\a");               //player playing conditions
	  scanf ("%1d%1d", &x, &y);
	  Sleep (450);                                             //<---- This will pause the screen for few seconds
	  if (moveFunction (x, y))
	    {
	      tac[x][y] = 'P';
	      Num++;
	      if (winFunction (x, y))
		{
		  condition = false;
		  Sleep (450);
		  system ("cls");
		  printf ("\t\t\t\tPlayer won the game!!\n\t\t\t\t\a");
		  Sleep (450);
		  displayTable ();
		}
	      else
		{
		  printf ("\t");
		}
	    }
	  else
	    {
	      Sleep (450);
	      system ("cls");
	      printf ("Invalid move enter again:\n\a\a");
	      return 0;
	    }
	}
      else
	{
	  printf ("Computer Turn:");  
	  displayTable ();
	  x = rand () % 3;                                          
	  y = rand () % 3;
	  if (moveFunction (x, y))
	    {

	      tac[x][y] = 'C';
	      Num++;
	      if (winFunction (x, y))                                //computer playing conditions
		{
		  condition = false;
		  system ("cls");
		  printf ("Computer won the game!!\n\a");
		  displayTable ();
		}
	      else
		{
		  Sleep (450);
		  system ("cls");                           
		}
	    }
	}

    }

  Sleep (990);
  system ("pause");
  return 0;                                        //exiting the program
}

void displayTable ()                                //printing the table 
{
 
  printf ("\n\n");
  int i, j;
  for (i = 0; i < 3; i++)
    {

      printf ("        |     |\n");
      printf ("   ");
      for (j = 0; j < 3; j++)
	{
	  printf ("  %c  ", tac[i][j]);
	  if (j < 2)
	    {
	      printf ("|");
	    }
	}
      if (i < 2)
	{
	  printf ("\n   _____|_____|_____\n");
	}
      else
	{
	  printf ("\n        |     |     \n");
	}

    }

}

bool moveFunction (int x, int y)                                 //this function is will make the moves in game 
{
  bool status = false;
  if (tac[x][y] == '1', '2', '3', '4', '5', '6', '7', '8', '9')
    {
      status = true;                                               
    }
  return status;                                                 //returning the status
}


bool winFunction (int x, int y)                                  //this function will decide the win 
{
  bool wStatus = false;
  if (tac[x][0] == tac[x][1] && tac[x][1] == tac[x][2])            //possible win condions
    {
      wStatus = true;
      return wStatus;
    }
  else if (tac[0][y] == tac[1][y] && tac[1][y] == tac[2][y])                  //possible win condions
    {
      wStatus = true;
      return wStatus;
    }
  if ((x == 0 && y == 0) || (x == 2 && y == 2) || (x == y))                       //possible win condions
    {

      if (tac[0][0] == tac[1][1] && tac[1][1] == tac[2][2])                           //possible win condions
	{
	  wStatus = true;
	  return wStatus;
	}
    }
  else if ((x == 0 && y == 2) || (x == 2 && y == 0) || (x == y))                             //possible win condions
    {
      if (tac[0][2] == tac[1][1] && tac[1][1] == tac[2][0])
	{
	  wStatus = true;
	  return wStatus;
	}
    }

  return wStatus;                                            //returning the status
}


