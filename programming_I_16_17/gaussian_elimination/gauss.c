/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"
// =============================================================================
double **create_matrix(int r, int c)
{
    int i;
    double **m;

    m = (double **) malloc(r * sizeof(double *));
    for (i = 0; i < r; i++) {
        m[i] = (double *) malloc(c * sizeof(double));
    }

    return m;
}
// =============================================================================
void fill_matrix(double **m, int r, int c, char *file)
{
    int i, j;
    FILE *temp_file = fopen(file, "r");

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (!fscanf(temp_file, "%lf", &m[i][j])) {
                break;
            }
        }
    }

    fclose(temp_file);
}
// =============================================================================
void print_matrix(double **m, int r, int c, char *file)
{
    int i, j;
    FILE *temp_file = fopen(file, "a");

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            fprintf(temp_file, "\t%- 2.1lf", m[i][j]);
        }
        fprintf(temp_file, "\n");
    }
    fprintf(temp_file, "\n");

    fclose(temp_file);
}
// =============================================================================
void free_matrix(double **m, int r, int c)
{
    int i;

    if (m) {
        for (i = 0; i < r; i++) {
            free(m[i]);
        }
        free(m);
    }
}
// =============================================================================
void gauss_elimination(double **m, int r, int c, char *file)
{
    int i, j, k;
    double temp;
    FILE *temp_file = fopen(file, "a");

    for (i = 0; i < (r - 1); i++) {
        for (j = (i + 1); j < r; j++) {
            temp = m[j][i] / m[i][i];
            for (k = (i + 1); k <= r; k++) {
                m[j][k] -= m[i][k] * temp;
            }
            m[j][i] = 0;
        }
        print_matrix(m, r, c, file);
    }

    fclose(temp_file);
}
// =============================================================================
double *calculate_solution(double **m, int r)
{
    int i, j;
    double *temp = (double *) malloc(r * sizeof(double));

    for (i = (r - 1); i >= 0; i--) {
        temp[i] = m[i][r];
        for (j = (i + 1); j < r; j++) {
            temp[i] -= m[i][j] * temp[j];
        }
        temp[i] /= m[i][i];
    }

    return &temp[0];
}
