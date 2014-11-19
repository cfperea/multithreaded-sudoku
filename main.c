/**
 * Name: main.c
 * Description: Sudoku puzzle solver using threads. (pthread library)
 * Date: November 19th, 2014.
 * 
 * ==============================================================================
 * 
 * Copyright (C) 2014  Carlos Perea
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/**
 * Structure that holds the parameters passed to a thread.
 * This specifies where the thread should start verifying.
 */
typedef struct 
{
    // The starting row.
    int row;
    // The starting column.
    int col;
    // The pointer to the board.
    int (* board)[9];
} parameters;

// Prototype for the walk_rows function.
void * walk_rows(void * params);

// Prototype for the walk_cols function.
void * walk_cols(void * params);

// Prototype for 3x3 square function.
void * check_square(void * params);

/***************
 * ENTRY POINT
 **************/
int main(void) 
{
    // ====== Create the board =======
    int board[9][9] = {  
            {6, 2, 4, 5, 3, 9, 1, 8, 7},
            {5, 1, 9, 7, 2, 8, 6, 3, 4},
            {8, 3, 7, 6, 1, 4, 2, 9, 5},
            {1, 4, 3, 8, 6, 5, 7, 2, 9},
            {9, 5, 8, 2, 4, 7, 3, 6, 1},
            {7, 6, 2, 3, 9, 1, 4, 5, 8},
            {3, 7, 1, 9, 5, 6, 8, 4, 2},
            {4, 9, 6, 1, 8, 2, 5, 7, 3},
            {2, 8, 5, 4, 7, 3, 9, 1, 6}
        };
    
    // ====== Create the parameter for the columns and rows check =======
    parameters * param0 = (parameters *) malloc(sizeof(parameters));
    param0->row = 0;
    param0->col = 0;
    param0->board = board;
    
    // ====== Create the parameters for the 3x3 threads ======
    
    // First 3x3
    parameters * param1 = (parameters *) malloc(sizeof(parameters));
    param1->row = 0;
    param1->col = 0;
    param1->board = board;
    
    // Second 3x3
    parameters * param2 = (parameters *) malloc(sizeof(parameters));
    param2->row = 0;
    param2->col = 3;
    param2->board = board;
    
    // Third 3x3
    parameters * param3 = (parameters *) malloc(sizeof(parameters));
    param3->row = 0;
    param3->col = 6;
    param3->board = board;
    
    // Fourth 3x3
    parameters * param4 = (parameters *) malloc(sizeof(parameters));
    param4->row = 3;
    param4->col = 0;
    param4->board = board;
    
    // Fifth 3x3
    parameters * param5 = (parameters *) malloc(sizeof(parameters));
    param5->row = 3;
    param5->col = 3;
    param5->board = board;
    
    // Sixth 3x3
    parameters * param6 = (parameters *) malloc(sizeof(parameters));
    param6->row = 3;
    param6->col = 6;
    param6->board = board;
    
    // Seventh 3x3
    parameters * param7 = (parameters *) malloc(sizeof(parameters));
    param7->row = 6;
    param7->col = 0;
    param7->board = board;
    
    // Eighth 3x3
    parameters * param8 = (parameters *) malloc(sizeof(parameters));
    param8->row = 6;
    param8->col = 3;
    param8->board = board;
    
    // Ninth 3x3
    parameters * param9 = (parameters *) malloc(sizeof(parameters));
    param9->row = 6;
    param9->col = 6;
    param9->board = board;
    
    // ====== Create the threads ======
    pthread_t thread_rows, thread_cols, thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8, thread9;
    
    // ====== Create the return values for the threads ======
    void * all_rows;
    void * all_cols;
    void * square1;
    void * square2;
    void * square3;
    void * square4;
    void * square5;
    void * square6;
    void * square7;
    void * square8;
    void * square9;
    
    // ====== Initialize the threads ======
    pthread_create(&thread_rows, NULL, walk_rows, (void *) param0);
    pthread_create(&thread_cols, NULL, walk_cols, (void *) param0);
    pthread_create(&thread1, NULL, check_square, (void *) param1);
    pthread_create(&thread2, NULL, check_square, (void *) param2);
    pthread_create(&thread3, NULL, check_square, (void *) param3);
    pthread_create(&thread4, NULL, check_square, (void *) param4);
    pthread_create(&thread5, NULL, check_square, (void *) param5);
    pthread_create(&thread6, NULL, check_square, (void *) param6);
    pthread_create(&thread7, NULL, check_square, (void *) param7);
    pthread_create(&thread8, NULL, check_square, (void *) param8);
    pthread_create(&thread9, NULL, check_square, (void *) param9);

    // ======= Wait for all threads to finish their tasks =======
    pthread_join(thread_rows, &all_rows);
    pthread_join(thread_cols, &all_cols);
    pthread_join(thread1, &square1);
    pthread_join(thread2, &square2);
    pthread_join(thread3, &square3);
    pthread_join(thread4, &square4);
    pthread_join(thread5, &square5);
    pthread_join(thread6, &square6);
    pthread_join(thread7, &square7);
    pthread_join(thread8, &square8);
    pthread_join(thread9, &square9);
    
    // ====== Check whether the Sudoku Puzzle was solved ======
    if (    (int) all_rows == 1 &&
            (int) all_cols == 1 &&
            (int) square1 == 1 &&
            (int) square2 == 1 &&
            (int) square3 == 1 &&
            (int) square4 == 1 &&
            (int) square5 == 1 &&
            (int) square6 == 1 &&
            (int) square7 == 1 &&
            (int) square8 == 1 &&
            (int) square9 == 1 ) {
        printf("The Sudoku Puzzle is solved!\n");
    }
    else {
        printf("The Sudoku Puzzle is NOT solved.\n");
    }
    
    return 0;
}

/**
 * Checks each row if it contains all digits 1-9.
 * @param   void *      The parameters (pointer).
 * @return  void *      1 if all rows contain all digits from 1-9, 0 otherwise.
 */
void * walk_rows(void * params) {
    parameters * data = (parameters *) params;
    int startRow = data->row;
    int startCol = data->col;
    for (int i = startRow; i < 9; ++i) {
        int row[10] = {0};
        for (int j = startCol; j < 9; ++j) {
            int val = data->board[i][j];
            if (row[val] != 0) {
                return (void *) 0;
            }
            else{
                row[val] = 1;
            }
        }
    }
    return (void *) 1;
}

/**
 * Checks each column if it contains all digits 1-9.
 * @param   void *      The parameters (pointer).
 * @return  void *      1 if all rows contain all digits from 1-9, 0 otherwise.
 */
void * walk_cols(void * params) {
    parameters * data = (parameters *) params;
    int startRow = data->row;
    int startCol = data->col;
    for (int i = startCol; i < 9; ++i) {
        int col[10] = {0};
        for (int j = startRow; j < 9; ++j) {
            int val = data->board[j][i];
            if (col[val] != 0) {
                return (void *) 0;
            }
            else{
                col[val] = 1;
            }
        }
    }
    return (void *) 1;
}

/**
 * Checks if a square of size 3x3 contains all numbers from 1-9.
 * @param   void *      The parameters (pointer).
 * @return  void *      1 if all rows contain all digits from 1-9, 0 otherwise.
 */
void * check_square(void * params) {
    parameters * data = (parameters *) params;
    int startRow = data->row;
    int startCol = data->col;
    int saved[10] = {0};
    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            int val = data->board[i][j];
            if (saved[val] != 0) {
                return (void *) 0;
            }
            else{
                saved[val] = 1;
            }
        }
    }
    return (void *) 1;
}