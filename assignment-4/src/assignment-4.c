/*
 ============================================================================
 Name        : assignment-4.c
 Author      : Chenggang(Crown) Wang
 Course/Term : CS 5001 Fall 2017 Northeastern University Silicon Valley

 Description : A Tic Tac Toe game (Naughts and Crosses)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define COL 3
#define ROW 3

typedef struct {
    unsigned char board[ROW][COL];
    int rows[ROW];
    int cols[COL];
    int dia;
    int antiDia;
} TTTBoard;

typedef enum {false, true} bool;

/**
 * initializes the 3x3 board array to space characters representing unmarked positions.
 *
 * @param board input board
 */
TTTBoard *initBoard() {
    TTTBoard* board = (TTTBoard *) malloc(sizeof(TTTBoard));
    board->dia = 0;
    board->antiDia = 0;
    for (int i = 0; i < ROW; i++) {
        board->rows[i] = 0;
        board->cols[i] = 0;
    }
    unsigned char *p = &board->board;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            *p++ = ' ';
        }
    }
}

/**
 * Displays the tic-tac-toe board with vertical and horizontal grid lines formed
 * with dashes and vertical bars, using the characters in the 3x3 board array.
 *
 * @param board the board to display
 */
void displayBoard(const TTTBoard *board) {
    if (board == NULL) return;
    unsigned char *bp = &board->board;
    printf("-------------\n");
    for (int i = 0; i < ROW; i++) {
        printf("|");
        for (int j = 0; j < COL; j++) {
            printf(" %c |", *bp++);
        }
        printf("\n-------------\n");
    }
}

/**
 * Marks the board based on the position (1-9) and marker character passed in.
 *
 * @param board     the 3x3 board array to mark
 * @param mark      the marker character of the player passed in
 * @param position  the position in the board to mark
 */
void markTheBoard(TTTBoard *board, const char mark, const int position) {
    assert(board != NULL);

    unsigned char* boardPointer = (unsigned char*)board;
    boardPointer += position - 1;
    *boardPointer = mark;
}

/**
 * whether the marker character of the player passed in as won the game
 * by examining the values in the 3x3 board array
 *
 * @param board the 3x3 board array
 * @param mark  the marker character of the player passed in
 * @return true if the marker character of the player passed in as won the game
 * by examining the values in the 3x3 board array and vice versa.
 */
bool hasWon(TTTBoard board, char mark) {
    assert(board != NULL);

    /** declare the pointer and check every row */
    unsigned char* boardPointer = (unsigned char*)board;
    for (int i = 0; i < ROW; i++, boardPointer += ROW) {
        if (*boardPointer == mark && *(boardPointer + 1) == mark && *(boardPointer + 2) == mark)
            return true;
    }

    /** initiate the pointer and check every column */
    boardPointer = (unsigned char*)board;
    for (int i = 0; i < COL; i++, boardPointer++) {
        if (*boardPointer == mark && *(boardPointer+ROW) == mark && *(boardPointer + ROW + ROW) == mark)
            return true;
    }

    /** initiate the pointer and check every diagonal */
    boardPointer = (unsigned char*)board;
    if (*boardPointer == mark && *(boardPointer + 4) == mark && *(boardPointer + 8) == mark)
        return true;
    if (*(boardPointer + 2) == mark && *(boardPointer + 4) == mark && *(boardPointer + 6) == mark)
        return true;

    return false;
}

/**
 * whether the marker character of the player passed in as won the game
 * by examining the values in the 3x3 board array
 *
 * @param board the 3x3 board array
 * @param mark  the marker character of the player passed in
 * @return true if the board is currently a tie and vice versa.
 */
bool isTie(TTTBoard board) {

    /** if the game is not over, it is not a tie */
    unsigned char* boardPointer = (unsigned char*)board;
    for (int i = 0; i < ROW * COL; i++)
        if (*boardPointer++ == ' ')
            return false;

    /** if the game has a winner, it is not a tie */
    return (!(hasWon(board, 'X') || hasWon(board, 'O')));
}

/**
 * Main program for an interactive game of tic-tac-toe.
 */
int main(void) {
    TTTBoard board;
    char turn = 'X';

    // initialize the board
    initBoard(board);

    printf("To play a position use the following map to enter a position.\n");
    printf("-------------\n");
    for (int boardPos = 1; boardPos <= 9; boardPos += 3) {
        printf("| %d | %d | %d |\n", boardPos, boardPos+1, boardPos+2);
            printf("-------------\n");
    }

    // play until there is a draw or a player has won
    while (!isTie(board) && !hasWon(board, 'X') && !hasWon(board, 'O')) {
        int boardPos = -1;
        bool validInput = false;

        // wait for valid input
        while(!validInput) {
            printf("Player %c, enter the position you want to play.\n", turn);
            int success = scanf("%d", &boardPos);
            if (success < 0 || boardPos < 0 || boardPos > 9 ||
                board[(boardPos-1) / 3][(boardPos-1) % 3] != ' ') {
                continue;
            }
            validInput = true;
        }

        // mark the position and display the updated board
        markTheBoard(board, turn, boardPos);

        // display the current board
        displayBoard(board);

        // other player's turn
        switch(turn) {
            case 'X':
                turn = 'O';
                break;
            case 'O':
                turn = 'X';
                break;
        }
    }

    // game over so report results
    if (isTie(board)) {
        printf("The game ends in a tie.\n");
    } else if (hasWon(board, 'X')) {
        printf("Player X has won.");
    } else {
        printf("Player O has won.");
    }

    return EXIT_SUCCESS;
}
