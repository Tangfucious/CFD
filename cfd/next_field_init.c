#include "next_field_init.h"
#include <stdlib.h>

//initialize u
double** u_next_field_create(int rows, int cols)
{
    double **u_next = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        u_next[i] = malloc(cols * sizeof(double *));
    }
    return u_next;
}
void** u_next_field_init(double **u_next, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            u_next[i][j] = 0;
        }
    }
}

//initialize v
double** v_next_field_create(int rows, int cols)
{
    double **v_next = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        v_next[i] = malloc(cols * sizeof(double *));
    }
    return v_next;
}
void** v_next_field_init(double **v_next, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            v_next[i][j] = 0;
        }
    }
}

//initialize p
double** p_next_field_create(int rows, int cols)
{
    double **p_next = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        p_next[i] = malloc(cols * sizeof(double *));
    }
    return p_next;
}
void** p_next_field_init(double **p_next, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            p_next[i][j] = 0;
        }
    }
}