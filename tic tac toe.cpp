 #include <iostream>
using namespace std;
const int ROWS = 3;
const int COLS = 3;

void drawBoard(int board[][COLS]) {
    cout << endl;
    for (int j = 1; j <= COLS; j++) {
        cout << j << " ";
    }
    cout << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                cout << "X ";
            } else if (board[i][j] == -1) {
                cout << "O ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool checkWin(int board[][COLS]) {
    // check rows
    for (int i = 0; i < ROWS; i++) {
        int sum = 0;
        for (int j = 0; j < COLS; j++) {
            sum += board[i][j];
        }
        if (sum == 3 || sum == -3) {
            return true;
        }
    }

    // check columns
    for (int i = 0; i < COLS; i++) {
        int sum = 0;
        for (int j = 0; j < ROWS; j++) {
            sum += board[j][i];
        }
        if (sum == 3 || sum == -3) {
            return true;
        }
    }

    // check diagonals
    int sum = board[0][0] + board[1][1] + board[2][2];
    if (sum == 3 || sum == -3) {
        return true;
    }

    sum = board[0][2] + board[1][1] + board[2][0];
    if (sum == 3 || sum == -3) {
        return true;
    }

    return false;
}
bool checkTie(int board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int board[ROWS][COLS] = {0};
    string players[2] = {"Player X", "Player O"};
    int player = 0;
    bool win = false;

    while (!win && !checkTie(board)) {
        drawBoard(board);
        cout << players[player] << ", enter row (1-3): ";
        int row;
        cin >> row;

        while (row < 1 || row > 3) {
            cout << "Invalid row number. Please enter row (1-3): ";
            cin >> row;
        }

        cout << players[player] << ", enter column (1-3): ";
        int col;
        cin >> col;

        while (col < 1 || col > 3) {
            cout << "Invalid column number. Please enter column (1-3): ";
            cin >> col;
        }

        if (board[row - 1][col - 1] != 0) {
            cout << "That spot is already taken. Please try again." << endl;
            continue;
        }

        if (player == 0) {
            board[row - 1][col - 1] = 1;
          player = 1;
         
        } else {
            board[row - 1][col - 1] = -1;
          player = 0;
        }

        win = checkWin(board);
    }

    drawBoard(board);
   if (win) {
        cout << players[(player+1)%2] << " wins!" << endl;

    } else {
        cout << "It's a tie!" << endl;
    }
    
    return 0;
}
//Task 3 : tic tac toe 
//I choose to make the board 3×3 ,so the code 
//starts by declaring two constant variables for the rows and the columns then I draw the board using
//the function void drawBoard(int board[][]), this function takes a 2D array as its parameter this array
//represents the 3x3 grid, then to make the board 
//distinguishable the array is initialized using a nested loop by “-“, and at the beginning of each row
//and column i print its number.
//Also, this function transfers the inputs which is integer to their assigned sign 
//(X or O), If the players enter 1 in any place on the board it changes to “X” and if he 
//enters -1 it changes to “O”.
//After making a function to draw the board another function is made to check for winners called bool 
//checkWin(int board[][]), the parameter for this function is also the 2D array which represents the 
//grid to collect data from each element in it and returns true if a winner is found.
//The CheckWin function consists of three sections:
//First is the check row, where the software determines whether a row's sum is 3 or -3 by a nested loop which adds the sum of the elements in
//each row individually since a player may only enter 1 or -1; hence, if the sum is 3 or -3, a player has won the game.
//The second step is to examine the columns, which is done in a similar manner to how i checked 
//the rows using the same nested loop but with reversing the coordinates of the elements added. 
//The third step is the diagonal check, in which i examine the total of the places that form a 
//diagonal which are board[0][0], board[1][1], board[2][2] for the main diagonal, and board[0][2], 
//board[1][1], board[2][0] for the anti-diagonal and determine if it is 3 or -3, in which case one of the
//players won the round.
//In the last function int main()function, i initialize every element in the board[][] to the value 0, 
// and also define the two players, and a while loop is created so that the game keeps going until one of the two players wins the game.
// In this loop, we have the drawboard() function, which sets the shape of the board and changes as each player enters the coordinates of the required place in the array.
//The program asks the players to enter the place they choose by selecting the number of rows 
//and columns and in case they choose number less than 1 or greater than 3 the program asks them to 
//re-enter their input, also if the place the player chose is already taken the program give him a 
//message that the spot is taken and to try again. Also, we have the CheckWin() function which 
//checks if one of players won the game or the game ends with a draw. Finally, the program tells 
//which player won the game.
//In this task , I have learned about arrays and how to use them as function parameters and I have got more experience in implementation of functions.
