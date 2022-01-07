/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"
// =============================================================================
int main(int argc, char *argv[])
{
    int rows, columns, i, j;
    double **matrix;
    double *solution;
    FILE *in_file;
    FILE *out_file;

    // Check if there are all the three parameters
    if (argc != 3) {
        fprintf(stderr, "Bad usage. ");
        fprintf(stderr, "Syntax ./gauss <input_file> <output_file>\n");
        exit(1);
    }

    // Check if exists the in_file
    in_file = fopen(argv[1], "r");
    if (in_file == 0) {
        fprintf(stderr, "Failed to open the input file. ");
        fprintf(stderr, "Syntax ./gauss <input_file> <output_file>\n");
        exit(1);
    }
    fclose(in_file);

    // Take the order matrix
    printf("Number of rows: ");
    scanf("%d", &rows);
    printf("Number of columns: ");
    scanf("%d", &columns);

    // Allocation of memory for matrix
    matrix = create_matrix(rows, columns);

    // Fill matrix with value on in_file
    fill_matrix(matrix, rows, columns, argv[1]);

    out_file = fopen(argv[2], "a");
    fprintf(out_file, "Input matrix: \n");
    fclose(out_file);

    // Print matrix on out_file
    print_matrix(matrix, rows, columns, argv[2]);

    // Gauss elimination
    gauss_elimination(matrix, rows, columns, argv[2]);

    // Calculate solution
    solution = calculate_solution(matrix, rows);

    // Print solution
    out_file = fopen(argv[2], "a");
    fprintf(out_file, "Solutions:\n");
    for (i = 0; i < rows; i++) {
        fprintf(out_file, "x[%d] = %.2lf\n", i, solution[i]);
    }
    fclose(out_file);

    // Free matrix
    free_matrix(matrix, rows, columns);
}
