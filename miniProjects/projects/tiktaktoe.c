#include <stdio.h>

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    printf("Tic-Tac-Toe\n");
    printf("-----------\n");
    for (int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-----------\n");
    }
}

// Function to check if the game is over (win or draw)
int isGameOver(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }

    // Check if the board is full (draw)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    // If none of the above conditions is met, the game is a draw
    return -1;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row, col;
    int currentPlayer = 0; // Player 0 starts

    int gameOver = 0;
    int moves = 0;

    while (!gameOver) {
        // Display the board
        displayBoard(board);

        // Get current player's move
        printf("Player %d, enter your move (row [0-2] and column [0-2]): ", currentPlayer + 1);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            // Update the board
            board[row][col] = currentPlayer == 0 ? 'X' : 'O';
            moves++;

            // Check if the game is over
            gameOver = isGameOver(board);

            // Switch to the other player
            currentPlayer = 1 - currentPlayer;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    // Display the final board and result
    displayBoard(board);
    if (gameOver == 1) {
        printf("Player %d wins!\n", currentPlayer + 1);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
