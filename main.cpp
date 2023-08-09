#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int board[3][3] = {0}; // this is the actual board that will be used
// 0 means empty, 1 means player1, and 2 means player2
// create a function to determine where to place the pin so the opponent does not win

int stateOfGame = 0; // 1 means player1 won, 2 means player2 won
void checkOpponent () {
    
    int col = 0;
    int count = 0;
    int empty = 0;
    int emptyRow = 0;

    // horizontal lines
    for (int i = 0; i < 3; i++) {
        count = 0; // this will count how many are in a line (0 to 3)
        empty = 0; // this will be used to know where to place the pin
        
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 1) count++;
            if (board[i][j] == 0) empty = j;
        }
        if (count == 3) {
            stateOfGame = 1;
        }
        if (count == 2) {
            board[i][empty] = 2;
            goto END;
        }
    }
 
    // vertical lines
    for (int i = 0; i < 3; i++) {
        count = 0; // this will count how many are in a line (0 to 3)
        empty = 0; // this will be used to know where to place the pin
        int j = 0;
        for (j = 0; j < 3; j++) {
            if (board[j][i] == 1) count++;
            if (board[j][i] == 0) empty = i;
        }
        if (count == 3) {
            stateOfGame = 1;
        }
        if (count == 2) {
            board[j][empty] = 2;
            goto END;
        } 
    }

    // horizontal lines
    col = 0;
    count = 0;
    empty = 0;
    emptyRow = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][col] == 1) count++;
        if (board[i][col] == 0) {
            empty = col;
            emptyRow = i;
        }
        col++;
    }
    if (count == 3) stateOfGame = 1;
    if (count == 2) {
        board[emptyRow][empty] = 2;
        cout << emptyRow << col;
        goto END;
    }

    
    col = 2;
    count = 0;
    empty = 0;
    emptyRow = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][col] == 1) count++;
        if (board[i][col] == 0) empty = i;
        col--;
    }
    if (count == 3) stateOfGame = 1;
    if (count == 2) {
        board[emptyRow][empty] = 2;
        goto END;
    }

    
    END:
    if (stateOfGame == 1) cout << "Player 1 wins." << endl;
    else {
        cout << "Successfully placed down a pin." << endl;
    }

}

void printBoard () {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main () {
    cout << "Welcome to Tic-Tac-Toe! Press 1 to play against the computer. Press 2 to play multiplayer." << endl;

    int numPlayers = 0;
    cin >> numPlayers;

    if (numPlayers == 1) {
        board[0][0] = 1;
        board[2][2] = 1;
        board[1][1] = 1;
        printBoard();
        checkOpponent();
        printBoard();
    }
    else if (numPlayers == 2) {

    }
    else {

    }

    return 0;
}