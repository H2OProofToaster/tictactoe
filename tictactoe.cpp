#include <iostream>
#include <cstring>

using namespace std;

int checkValid(char move[2], int player, char &board[3][3]);
bool checkWin(char board[3][3]);

char cleanBoard[3][3] = { {'\0', 'a', 'b', 'c'}
		          {'1', '\0', '\0', '\0'}
		          {'2', '\0', '\0', '\0'}
		          {'3'. '\0', '\0', '\0'} }

char board[3][3] = { {'\0', 'a', 'b', 'c'}
                     {'1', '\0', '\0', '\0'}
                     {'2', '\0', '\0', '\0'}
                     {'3'. '\0', '\0', '\0'} }
  
  
int main()
{
  playing = true;
  player = 1;
  
  while(playing)
    {
      cout << "What is your move? (form of rowcolumn, lowercase please)" << endl;

      char placeToPlay[2];
							       
      cin.get(2, placeToPlay);
      placeToPlay[2] = '\0';
							       
      //Invalid move
      if(checkValid(placeToPlay, player, board) == -1)
	{
	  cout << "Invalid" << endl;
	}

      //T/F win statement
      bool win = checkWin(board);
      if(win == true)
	{
	  cout << "Player " << player << " wins" << endl;

	  bool playAgain = true;
	  cout << "Play again? (0 or 1)" << endl;
	  cin >> playAgain;
	  
	  if(!playAgain)
	    {
	      playing = false;
	    }
	  else
	    {
	      resetBoard();
	      player = 1;
	    }
	}
    }
  
  return 0;
}

int checkValid(char move[2], int player, char &board[3][3])
{
  //Change move to something useful
  int betterFormattedMove[1];

  if(move[1] == 'a') {betterFormattedMove[1] = 1;}
  else if(move[1] == 'b') {betterFormattedMove[1] = 2;}
  else if(move[1] == 'c') {betterFormattedMove[1] = 3;}
  else {return -1;}
  
  betterFormattedMove[0] = move[0];

  //Put X or O
  if(board[betterFormattedMove[0]][betterFormattedMove[1]] == '\0')
    {
      if(player == 1) {board[betterFormattedMove[0]][betterFormattedMove[1]] = 'X';}
      else if(player == 2) {board[betterFormattedMove[0]][betterFormattedMove[1]] = 'O';}
    }
}

bool checkWin(char board[3][3])
{
  //Top left to bottom right
  if(board[1][1] == board[2][2] and board[1][1] == board[3][3] and board[1][1] != '\0') {return true;}

  //Top right to bottom left
  if(board[1][3] == board[2][2] and board[1][3] == board[3][1] and board[1][3] != '\0') {return true;}

  //Top row
  if(board[1][1] == board[1][2] and board[1][1] == board [1][3] and board[1][1] != '\0') {return true;}

  //Middle row
  if(board[2][1] == board[2][2] and board[2][1] == board [2][3] and board[2][1] != '\0') {return true;}

  //Bottom row
  if(board[3][1] == board[3][2] and board[3][1] == board [3][3] and board[3][1] != '\0') {return true;}

  //Left column
  if(board[1][1] == board[2][1] and board[1][1] == board [3][1] and board[1][1] != '\0') {return true;}

  //Middle column
  if(board[1][2] == board[2][2] and board[1][2] == board [3][2] and board[1][2] != '\0') {return true;}

  //Right column
  if(board[1][3] == board[2][3] and board[1][3] == board [3][3] and board[1][3] != '\0') {return true;}

  return false;
}
