#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

int checkValid(char move[2], int player, char board[4][4]);
int checkWin(char board[4][4]);
void resetBoard(char cleanBoard[4][4], char board[4][4]);
void printBoard(char board[4][4]);

char cleanBoard[4][4] = { {'\0', 'a', 'b', 'c'},
		          {'1', '\0', '\0', '\0'},
		          {'2', '\0', '\0', '\0'},
		          {'3', '\0', '\0', '\0'} };

char board[4][4] = { {'\0', 'a', 'b', 'c'},
		     {'1', '\0', '\0', '\0'},
		     {'2', '\0', '\0', '\0'},
		     {'3', '\0', '\0', '\0'} };
  
  
int main()
{
  bool playing = true;
  int player = 1;
  int player1Wins = 0;
  int player2Wins = 0;
  
  while(playing)
    {
      //Get player input
      cout << endl;
      printBoard(board);
      cout << "What is your move? (form of columnrow, lowercase please)" << endl;

      char placeToPlay[2];

      //Clear buffer
      cin.get(placeToPlay, 3);
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      
      //Check move
      int valid = checkValid(placeToPlay, player, board);

      //Bad input
      if(valid == -1)
	{
	  cout << "That's not a move" << endl;
	  if(player == 1) { player = 2; }
          else if(player == 2) { player = 1; }
	}
      else if(valid == -2)
	{
	  cout << "You can't play there" << endl;
	  if(player == 1) { player = 2; }
          else if(player == 2) { player = 1; }
	}
      
      //Deal with win/tie
      int win = checkWin(board);
      if(win == -1)
	{
	  cout << "Tie" << endl;
	}
      else if(win == 1)
	{
	  cout << "Player " << player << " wins" << endl;

	  //Increment win counter
	  if(player == 1) { player1Wins++; }
	  else if(player == 2) { player2Wins++; }

	  //Print wins
	  cout << "Player 1 wins: " << player1Wins << endl;
	  cout << "Player 2 wins: " << player2Wins << endl;
	}

      //Play again
      if(win != 0)
	{
	  //Ask to play again
	  bool playAgain = true;
	  cout << "Play again? (0 or 1)" << endl;
	  cin >> playAgain;

	  //Stop playing
	  if(!playAgain)
	    {
	      playing = false;
	    }

	  //Reset and play again
	  else
	    {
	      resetBoard(cleanBoard, board);
	      player = 2;
	    }
	}
      
      //Switch players
      if(player == 1) { player = 2; }
      else if(player == 2) { player = 1; }
      
    }
  
  return 0;
}

int checkValid(char move[2], int player, char board[4][4])
{
  //Change move to something useful
  int indexedMove[2];

  if(move[0] == 'a') { indexedMove[1] = 1; }
  else if(move[0] == 'b') { indexedMove[1] = 2; }
  else if(move[0] == 'c') { indexedMove[1] = 3; }
  else { return -1; }
  
  if(move[1] == '1') { indexedMove[0] = 1; }
  else if(move[1] == '2') { indexedMove[0] = 2; }
  else if(move[1] == '3') { indexedMove[0] = 3; }
  else { return -1; }

  //Put X or O
  if(board[indexedMove[0]][indexedMove[1]] == '\0')
    {
      if(player == 1) {board[indexedMove[0]][indexedMove[1]] = 'X';}
      else if(player == 2) {board[indexedMove[0]][indexedMove[1]] = 'O';}
    }
  else { return -2; }

  return 0;
}

int checkWin(char board[4][4])
{
  //Tie
  bool tie = true;
  for(int i = 1; i < 4; i++)
    {
      for(int j = 1; j < 4; j++)
	{
	  if(board[i][j] == '\0') { tie = false; }
	}
    }
  if(tie == true) { return -1; }
  
  //Top left to bottom right
  if(board[1][1] == board[2][2] and board[1][1] == board[3][3] and board[1][1] != '\0') {return 1;}

  //Top right to bottom left
  if(board[1][3] == board[2][2] and board[1][3] == board[3][1] and board[1][3] != '\0') {return 1;}

  //Top row
  if(board[1][1] == board[1][2] and board[1][1] == board [1][3] and board[1][1] != '\0') {return 1;}

  //Middle row
  if(board[2][1] == board[2][2] and board[2][1] == board [2][3] and board[2][1] != '\0') {return 1;}

  //Bottom row
  if(board[3][1] == board[3][2] and board[3][1] == board [3][3] and board[3][1] != '\0') {return 1;}

  //Left column
  if(board[1][1] == board[2][1] and board[1][1] == board [3][1] and board[1][1] != '\0') {return 1;}

  //Middle column
  if(board[1][2] == board[2][2] and board[1][2] == board [3][2] and board[1][2] != '\0') {return 1;}

  //Right column
  if(board[1][3] == board[2][3] and board[1][3] == board [3][3] and board[1][3] != '\0') {return 1;}

  return 0;
}

void resetBoard(char cleanBoard[4][4], char board[4][4])
{
  //Copies clean board to second one
  for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
	{
	  board[i][j] = cleanBoard[i][j];
	}
    }
}

void printBoard(char board[4][4])
{
  //Makes printing the board actually useful
  cout << "Board" << endl;
  for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
	{
	  if(board[i][j] == '\0') { cout << '_'; }
	  else { cout << board[i][j]; }
	}
      cout << endl;
    }
}
