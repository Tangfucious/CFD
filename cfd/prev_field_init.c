#include "prev_field_init.h"
#include <stdlib.h>


//initialize u field
double** u_field_create(int rows, int cols)
{
    double **u = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        u[i] = malloc(cols * sizeof(double *));
    }
    return u;
}
void** u_field_init(double **u, int **node, int rows, int cols, double init_val, double front_u)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (node[i][j] == 0)
            {
                u[i][j] = 0;
            }
            else
            {
                u[i][j] = init_val;
                if (j == 1)
                {
                    u[i][j] = front_u;
                }
            }
        }
    }
}

//initialize v field

double** v_field_create(int rows, int cols)
{
    double **v = malloc(rows * sizeof(double *));
    for (size_t i = 0; i < rows; i++)
    {
        v[i] = malloc(cols * sizeof(double *));
    }
    return v;
}
void** v_field_init(double **v, int **node, int rows, int cols, double init_val)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (node[i][j] == 0)
            {
                v[i][j] = 0;
            }
            else
            {
                v[i][j] = init_val;
            }
        }
    }
}


//initialize p field

double** p_field_create(int rows, int cols){
    double** p = malloc(rows * sizeof(double*));
    for (size_t i = 0; i < rows; i++) {
        p[i] = malloc(cols * sizeof(double*));
    }
    return p;
}
void** p_field_init(double ** p, int **node, int rows, int cols, double init_val)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (node[i][j] == 0)
            {
                p[i][j] = 0;
            }
            else
            {
                p[i][j] = init_val;
            }
        }
    }
}