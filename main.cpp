#include <iostream>
#include <string>

using namespace std;

int board[3][3] = {0}; // this is the actual board that will be used
// 0 means empty, 1 means player1, and 2 means player2
// create a function to determine where to place the pin so the opponent does not win

int stateOfGame = 0; // 1 means player1 won, 2 means player2 won
int checkOpponent () { // return false if the game is over
    
    int col = 0;
    int count = 0;
    int empty = -1;
    int emptyRow = 0;
    int rempty;
    int countME = 0;
    bool placed = false; // did i place it or no
    // horizontal lines
    for (int i = 0; i < 3; i++) {
        count = 0; // this will count how many are in a line (0 to 3)
        empty = -1; // this will be used to know where to place the pin
        countME = 0;

        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 1) count++;
            if (board[i][j] == 2) countME++;
            if (board[i][j] == 0) empty = j;
        }
        if (count == 3) {
            stateOfGame = 1;
            goto END;
        }
        if (countME == 3) {
            stateOfGame = 2;
            goto END;
        }
        if (count == 2 && empty != -1) {
            board[i][empty] = 2;
            placed = true;
            goto END;
        }
    }
 
    // vertical lines
    for (int i = 0; i < 3; i++) {
        count = 0; // this will count how many are in a line (0 to 3)
        empty = -1; // this will be used to know where to place the pin
        countME = 0;
        for (int j = 0; j < 3; j++) {
            if (board[j][i] == 1) count++;
            if (board[j][i] == 2) countME++;
            if (board[j][i] == 0) {
                empty = i;
                rempty = j;
            }
        }
        if (count == 3) {
            stateOfGame = 1;
            goto END;
        }
        if (countME == 3) {
            stateOfGame == 2;
            goto END;
        }
        if (count == 2 && empty != -1) {
            board[rempty][empty] = 2;
            //cout << j << empty;
            placed = true;
            goto END;
        } 
    }

    // diagonal lines
    col = 0;
    count = 0;
    empty = -1;
    emptyRow = 0;
    countME = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][col] == 1) count++;
        if (board[i][col] == 2) countME++;
        if (board[i][col] == 0) {
            empty = col;
            emptyRow = i;
        }
        col++;
    }
    if (count == 3) stateOfGame = 1;
    if (countME == 3) stateOfGame = 2;
    if (count == 2 && empty != -1) {
        board[emptyRow][empty] = 2;
        placed = true;
        goto END;
    }

    
    col = 2;
    count = 0;
    empty = -1;
    emptyRow = 0;
    countME = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][col] == 1) count++;
        if (board[i][col] == 2) countME++;
        if (board[i][col] == 0) empty = i;
        col--;
    }
    if (count == 3) stateOfGame = 1;
    if (countME == 3) stateOfGame = 2;
    if (count == 2 && empty != -1) {
        board[emptyRow][empty] = 2;
        placed = true;
        goto END;
    }

    
    END:
    if (stateOfGame == 1) {
        cout << "Player 1 wins." << endl;
        return 0; // GAME OVER
    }
    else if (stateOfGame == 2) {
        cout << "Player 2 wins." << endl;
        return 0;
    }
    else if (placed == true){
        cout << "Successfully placed down a pin." << endl;
        return 1; // PLACED DOWN
    }
    else {
        return 2; // DID NOT PLACE DOWN
    }

}

void placeDown () {
    int rrow = 0;
    int rcol = 0;
    bool isPlacedDown = false;
    while (isPlacedDown == false) {
        rrow = rand()%2;
        rcol = rand()%2;
        if (board[rrow][rcol] == 0) {
            board[rrow][rcol] = 2;
            isPlacedDown = true;
            cout << "Placed down at: " << rrow << ", " << rcol << endl;
        }
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
        cout << "Randomly choosing which player will go first..." << endl;
        int starter = rand()%2;
        int row = 0;
        int col = 0;
        int place;
        if (starter == 1) {
            cout << "Player 1 goes first. Type in your move." << endl;
            cout << "ROW: " << endl; cin >> row;
            cout << "COL: " << endl; cin >> col;
            board[row][col] = 1;
            printBoard();
            
            while (stateOfGame == 0) {
                place = checkOpponent();
                if (place == 0) break;
                if (place == 2) placeDown(); 
                printBoard();
                cout << "Your turn Player 1. Type in your move." << endl;
                cout << "ROW: " << endl; cin >> row;
                cout << "COL: " << endl; cin >> col;
                board[row][col] = 1;
                printBoard();
            }
        }
        else {
            int rrow = rand()%2;
            int rcol = rand()%2;
            board[rrow][rcol] = 2;
            printBoard();
            
            while (stateOfGame == 0) {
                cout << "Your turn Player 1. Type in your move." << endl;
                cout << "ROW: " << endl; cin >> row;
                cout << "COL: " << endl; cin >> col;
                board[row][col] = 1;
                printBoard();
                place = checkOpponent();
                if (place == 0) break;
                if (place == 2) placeDown(); 
                printBoard();
            }
        }
/*         board[0][1] = 1;
        board[1][1] = 1;
        //board[2][0] = 1;
        printBoard();
        checkOpponent();
        printBoard(); */
    }
    else if (numPlayers == 2) {

    }
    else {

    }

    return 0;
}