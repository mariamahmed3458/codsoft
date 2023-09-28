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

int main() {
    int board[ROWS][COLS] = {0};
    string players[2] = {"Player X", "Player O"};
    int player = 0;
    bool win = false;

    while (!win) {
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
    cout << players[player] << " wins!" << endl;
    return 0;
}
