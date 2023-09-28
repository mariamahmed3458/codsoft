#include <iostream>
using namespace std ;
const int ROWS = 3;
const int COLS = 3;

void drawBoard(int board[][COLS]) {
    cout << " 1 2 3" <<endl;
    for (int i = 0; i < ROWS; i++) {
        
    cout << i + 1 << " ";
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1)
               cout << "X ";
            else if (board[i][j] == -1)
                cout << "O ";
            else
               cout << " ";
        }
        cout << endl;
    }
}

bool checkWin(int board[][COLS]) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        int sum = 0;
        for (int j = 0; j < COLS; j++) {
            sum += board[i][j];
        }
        if (sum == 3 || sum == -3)
            return true;
    }

    // Check columns
    for (int i = 0; i < COLS; i++) {
        int sum = 0;
        for (int j = 0; j < ROWS; j++) {
            sum += board[j][i];
        }
        if (sum == 3 || sum == -3)
            return true;
    }

    // Check diagonals
    int sum = board[0][0] + board[1][1] + board[2][2];
    if (sum == 3 || sum == -3)
        return true;

    sum = board[0][2] + board[1][1] + board[2][0];
    if (sum == 3 || sum == -3)
        return true;

    return false;
}

int main() {
    int board[ROWS][COLS] = {0};
    int currentPlayer = 1;
    bool gameOver = false;

    while (!gameOver) {
        drawBoard(board);

        int row, col;
        cout << "Player " << (currentPlayer == 1 ? "X" : "O") << ", enter your move (row column): ";
        cin >> row >> col;

        if (row < 1 || row > ROWS || col < 1 || col > COLS || board[row - 1][col - 1] != 0) {
            cout << "Invalid move. Try again." <<endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin(board)) {
            drawBoard(board);
            cout << "Player " << (currentPlayer == 1 ? "X" : "O") << " wins!" <<endl;
            gameOver = true;
        } else {
            bool isBoardFull = true;
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (board[i][j] == 0) {
                        isBoardFull = false;
                        break;
                    }
                }
                if (!isBoardFull)
                    break;
            }

            if (isBoardFull) {
                drawBoard(board);
                cout << "It's a draw!" <<endl;
                gameOver = true;
            } else {
                currentPlayer = -currentPlayer;
            }
        }
    }

    return 0;
}
