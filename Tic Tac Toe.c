#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];
const char PLAYER = 'x';
const char COMPUTER = 'o';
int i,j;


void resetboard()
{
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
        
    }
    
}
void printboard()
{
    printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[2][0],board[2][1],board[2][2]);
    printf("\n");
}
int checkfreespace()
{
    int freespace = 9;

    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            if (board[i][j]!=' ')
            {
                freespace--;
            }
            
        }
        
    }
   return freespace; 
}
void playermove()
{
    int x;
    int y;

   do
   {
    printf("enter row (0-2): ");
    scanf("%d",&x);
    printf("enter collom (0-2): ");
    scanf("%d",&y);
    if (board[x][y]!=' ')
    {
        printf("invalid move\n");
    }
    else
    {
        board[x][y] = PLAYER;
        break;
    }
    
    
   } while (board[x][y]!=' ');
   


}
void computermove()
{
    srand(time(0));
    int x;
    int y;
     if (checkfreespace()>0)
     {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y]!=' ');
        
        board[x][y] = COMPUTER;
        
     }
     else
     {
        printwinner(' ');
     }

     
}
char checkwinner()
{
    //check rows
    for (i = 0; i < 3; i++)
    {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2])
        {
           return board[i][0];
        }       
    }
    for (i = 0; i < 3; i++)
    {
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i])
        {
           return board[0][i]; 
        }
    }
    // check diagnose
    
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        return board[0][0]; 
    }
    
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0])
    {
       return board[0][2]; 
    }

  return ' ';
    
}
void printwinner(char winner)
{
  if (winner == PLAYER)
  {
    printf("you win!");
  }
  else if (winner == COMPUTER)
  {
    printf("you lode!");
  }
  else
  {
    printf("its a tie");
  }
  
  
  
}


int main()
{
  char winner = ' ';
  resetboard();
  while (winner == ' ' && checkfreespace() != 0)
  {
    printboard();
    playermove();
    winner = checkwinner();
    if (winner != ' ' || checkfreespace()==0)
    {
        break;
    }
    computermove();
    winner = checkwinner();
    if (winner != ' ' || checkfreespace()==0)
    {
        break;
    }
    
  }
  printboard();
  printwinner(winner);
 
return 0;
}




