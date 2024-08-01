#include "tent_field_init.h"
#include <stdlib.h>

//initialize u
double** u_tent_field_create(int rows, int cols)
{
    double **u_tent = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        u_tent[i] = malloc(cols * sizeof(double *));
    }
    return u_tent;
}
void** u_tent_field_init(double **u_tent, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            u_tent[i][j] = 0;
        }
    }
}

//initialize v

double **v_tent_field_create(int rows, int cols)
{
    double **v_tent = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        v_tent[i] = malloc(cols * sizeof(double *));
    }
    return v_tent;
}

void **v_tent_field_init(double **v_tent, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            v_tent[i][j] = 0;
        }
    }
}

//initialize p

double** p_tent_field_create(int rows, int cols)
{
    double **p_tent = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        p_tent[i] = malloc(cols * sizeof(double *));
    }
    return p_tent;
}
void** p_tent_field_init(double **p_tent, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            p_tent[i][j] = 0;
        }
    }
}