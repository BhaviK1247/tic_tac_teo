#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char currentPlayer = 'X';

void initializeBoard() {
    char cell = '1';
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = cell++;
}

void displayBoard() {
    printf("\n");
    for (int row = 0; row < 3; row++) {
        printf(" ");
        for (int col = 0; col < 3; col++) {
            printf("%c", board[row][col]);
            if (col < 2) printf(" | ");
        }
        if (row < 2) printf("\n-----------\n");
    }
    printf("\n\n");
}

int makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') return 0;
    board[row][col] = currentPlayer;
    return 1;
}

int hasPlayerWon() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer))
            return 1;
    }
    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer))
        return 1;
    return 0;
}

int isGameDraw() {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (board[row][col] != 'X' && board[row][col] != 'O')
                return 0;
    return 1;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int chosenPosition;
    initializeBoard();

    while (1) {
        displayBoard();
        printf("Player %c, choose a position (1-9): ", currentPlayer);
        scanf("%d", &chosenPosition);

        if (chosenPosition < 1 || chosenPosition > 9 || !makeMove(chosenPosition)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (hasPlayerWon()) {
            displayBoard();
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (isGameDraw()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }

        switchPlayer();
    }

    return 0;
}
