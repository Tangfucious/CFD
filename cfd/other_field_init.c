#include "other_field_init.h"
#include <stdlib.h>

double **rhs_create(int rows, int cols)
{
    double **rhs = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        rhs[i] = malloc(cols * sizeof(double *));
    }
    return rhs;
}

void **rhs_init(double **rhs, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            rhs[i][j] = 0;
        }
    }
}
double **m_create(int rows, int cols)
{
    double **m = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        m[i] = malloc(cols * sizeof(double *));
    }
    return m;
}

void **m_init(double **m, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            m[i][j] = 0;
        }
    }
}