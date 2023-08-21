#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int board[3][3] = {0}; // this is the actual board that will be used
// 0 means empty, 1 means player1, and 2 means player2
// create a function to determine where to place the pin so the opponent does not win

int stateOfGame = 0; // 1 means player1 won, 2 means player2 won, 3 means stalemate
int Gcount = 0; // count the number of times tried. if 9, game is stalemate.

void check () {
    if (board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }
    if (board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }
    if (board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }

    if (board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }
    if (board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }
    if (board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }

    if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }
    if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }
    if (Gcount >= 9) cout << "Game Over.";
}

int checkOpponent () { // return false if the game is over
    srand((unsigned int)time(NULL));
    
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
            if (board[i][j] == 0) empty = j;
        }
        if (count == 3) {
            stateOfGame = 1;
            goto END;
        }
        if (count == 2 && empty != -1) {
            board[i][empty] = 2;
            Gcount++;
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
            if (board[j][i] == 0) {
                empty = i;
                rempty = j;
            }
        }
        if (count == 3) {
            stateOfGame = 1;
            goto END;
        }
        if (count == 2 && empty != -1) {
            board[rempty][empty] = 2;
            //cout << j << empty;
            Gcount++;
            placed = true;
            goto END;
        } 
    }

    // diagonal lines
    count = 0;
    int emptyCol;

    if (board[0][0] == 1) count++;
    if (board[0][0] == 0) {
        emptyRow = 0;
        emptyCol = 0;
    }
    if (board[1][1] == 1) count++;
    if (board[1][1] == 0) {
        emptyRow = 1;
        emptyCol = 1;
    }
    if (board[2][2] == 1) count++;
    if (board[2][2] == 0) {
        emptyRow = 2;
        emptyCol = 2;
    }

    if (count == 3) stateOfGame = 1;
    if (count == 2) {
        board[emptyRow][emptyCol] = 2;
        Gcount++;
        placed = true;
        goto END;
    }

    count = 0;

    if (board[0][2] == 1) count++;
    if (board[0][2] == 0) {
        emptyRow = 0;
        emptyCol = 2;
    }
    if (board[1][1] == 1) count++;
    if (board[1][1] == 0) {
        emptyRow = 1;
        emptyCol = 1;
    }
    if (board[2][0] == 1) count++;
    if (board[2][0] == 0) {
        emptyRow = 2;
        emptyCol = 0;
    }

    if (count == 3) stateOfGame = 1;
    if (count == 2) {
        board[emptyRow][emptyCol] = 2;
        Gcount++;
        placed = true;
        goto END;
    }

    /* col = 0;
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
        count++;
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
        count++;
        placed = true;
        goto END;
    } */

    
    END:
    if (stateOfGame == 1) {
        cout << "Player 1 wins!" << endl;
        return 0; // GAME OVER
    }
    else if (stateOfGame == 2) {
        cout << "Player 2 wins!" << endl;
        return 0;
    }
    else if (placed == true){
        cout << "Successfully placed down a pin." << endl;
        check();
        return 1; // PLACED DOWN
    }
    else if (count >= 9) {
        cout << "GAME OVER. STALEMATE." << endl;
        return 0;
    }
    else {
        cout << "Did not find a winning pattern." << endl;
        return 2; // DID NOT PLACE DOWN
    }

}

void placeDown () {
    srand((unsigned int)time(NULL));
    int rrow = 0;
    int rcol = 0;
    bool isPlacedDown = false;

    while (isPlacedDown == false) {
        srand((unsigned int)time(NULL));
        rrow = rand()%2;
        rcol = rand()%2;
        cout << "stuck";
        if (board[rrow][rcol] == 0) {
            board[rrow][rcol] = 2;
            isPlacedDown = true;
            cout << "Placed down at: " << rrow << ", " << rcol << endl;
        }
        if (Gcount == 9) {
            stateOfGame = 3;
            break;
        }
    }
    check();
}

void checkPlayer1 () {
    if (board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1) {
        stateOfGame = 1;
        cout << "Player 1 wins." << endl;
    }
    if (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1) {
        stateOfGame = 1;
        cout << "Player 1 wins." << endl;
    }
    if (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1) {
        stateOfGame = 1;
        cout << "Player 1 wins." << endl;
    }

    if (board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1) {
        stateOfGame = 1;
        cout << "Player 1 wins." << endl;
    }
    if (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1) {
        stateOfGame = 1;
        cout << "Player 1 wins." << endl;
    }
    if (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1) {
        stateOfGame = 1;
        cout << "Player 1 wins." << endl;
    }

    if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
        stateOfGame = 1;
        cout << "Player 1 wins." << endl;
    }
    if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) {
        stateOfGame = 1;
        cout << "Player 1 wins." << endl;
    }
    if (Gcount >= 9) cout << "Game Over. Draw.";
}

void checkPlayer2 () {
    if (board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }
    if (board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }
    if (board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }

    if (board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }
    if (board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }
    if (board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }

    if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }
    if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2) {
        stateOfGame = 2;
        cout << "Player 2 wins." << endl;
    }
    if (Gcount >= 9) cout << "Game Over. Draw.";
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
    srand((unsigned int)time(NULL));
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
                if (place == 0) {
                    printBoard();
                    break;
                }
                if (place == 2) placeDown(); 
                printBoard();
                cout << "Your turn Player 1. Type in your move." << endl;
                cout << "ROW: " << endl; cin >> row;
                cout << "COL: " << endl; cin >> col;
                board[row][col] = 1;
                Gcount++;
                printBoard();
            }
            // when the game finishes
            if (stateOfGame == 1) cout << "Player 1 wins." << endl;
            if (stateOfGame == 2) cout << "Player 2 wins." << endl;
            if (stateOfGame == 3) cout << "No winner." << endl;
            
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
                Gcount++;
                printBoard();
                place = checkOpponent();
                if (place == 0) {
                    printBoard();
                    break;
                }
                if (place == 2) placeDown(); 
                printBoard();
            }
        }
    }
    else if (numPlayers == 2) {
        int row;
        int col;
        while (stateOfGame == 0) {
            cout << "Player 1 type in your move." << endl;
            cout << "ROW: " << endl; cin >> row;
            cout << "COL: " << endl; cin >> col;
            board[row][col] = 1;
            printBoard();
            checkPlayer1();
            if (stateOfGame != 0) break;
            cout << "Player 2 type in your move." << endl;
            cout << "ROW: " << endl; cin >> row;
            cout << "COL: " << endl; cin >> col;
            board[row][col] = 2;
            printBoard();
            checkPlayer2();
        }
    }
    else {

    }

    return 0;
}