#include <stdio.h>

char board[3][3];

// ?? Initialize Board
void initBoard() {
    char ch = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}

// ?? Display Board
void displayBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if(i < 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

// ?? Check Win
int checkWin() {
    // Rows & Columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }

    // Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

// ?? Check Draw
int checkDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }
    return 1;
}

int main() {
    int choice, player;
    char mark;
    char playAgain;

    do {
        initBoard();
        int gameOver = 0;

        while(!gameOver) {
            displayBoard();

            player = (player % 2) + 1;
            mark = (player == 1) ? 'X' : 'O';

            printf("Player %d (%c), enter position (1-9): ", player, mark);
            scanf("%d", &choice);

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            // Validate move
            if(choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
                printf("Invalid move! Try again.\n");
                continue;
            }

            board[row][col] = mark;

            // Check win
            if(checkWin()) {
                displayBoard();
                printf("?? Player %d wins!\n", player);
                gameOver = 1;
            }
            // Check draw
            else if(checkDraw()) {
                displayBoard();
                printf("It's a draw!\n");
                gameOver = 1;
            }
        }

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while(playAgain == 'y' || playAgain == 'Y');

    return 0;
}
