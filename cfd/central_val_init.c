#include "central_val_init.h"
#include <stdlib.h>

double **central_difference_u_x_create(int rows, int cols)
{
    double **central_difference_u_x = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        central_difference_u_x[i] = malloc(cols * sizeof(double *));
    }
    return central_difference_u_x;
}
double **central_difference_u_y_create(int rows, int cols)
{
    double **central_difference_u_y = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        central_difference_u_y[i] = malloc(cols * sizeof(double *));
    }
    return central_difference_u_y;
}
double **central_difference_v_x_create(int rows, int cols)
{
    double **central_difference_v_x = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        central_difference_v_x[i] = malloc(cols * sizeof(double *));
    }
    return central_difference_v_x;
}
double **central_difference_v_y_create(int rows, int cols)
{
    double **central_difference_v_y = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        central_difference_v_y[i] = malloc(cols * sizeof(double *));
    }
    return central_difference_v_y;
}
double **central_difference_p_x_create(int rows, int cols)
{
    double **central_difference_p_x = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        central_difference_p_x[i] = malloc(cols * sizeof(double *));
    }
    return central_difference_p_x;
}
double **central_difference_p_y_create(int rows, int cols)
{
    double **central_difference_p_y = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        central_difference_p_y[i] = malloc(cols * sizeof(double *));
    }
    return central_difference_p_y;
}
double **central_difference_u_laplace_create(int rows, int cols)
{
    double **central_difference_u_laplace = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        central_difference_u_laplace[i] = malloc(cols * sizeof(double *));
    }
    return central_difference_u_laplace;
}
double **central_difference_v_laplace_create(int rows, int cols)
{
    double **central_difference_v_laplace = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        central_difference_v_laplace[i] = malloc(cols * sizeof(double *));
    }
    return central_difference_v_laplace;
}
double **central_difference_u_tent_create(int rows, int cols)
{
    double **central_difference_u_tent = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        central_difference_u_tent[i] = malloc(cols * sizeof(double *));
    }
    return central_difference_u_tent;
}
double **central_difference_v_tent_create(int rows, int cols)
{
    double **central_difference_v_tent = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        central_difference_v_tent[i] = malloc(cols * sizeof(double *));
    }
    return central_difference_v_tent;
}
double **central_difference_u_next_create(int rows, int cols)
{
    double **central_difference_u_next = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        central_difference_u_next[i] = malloc(cols * sizeof(double *));
    }
    return central_difference_u_next;
}
double **central_difference_v_next_create(int rows, int cols)
{
    double **central_difference_v_next = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        central_difference_v_next[i] = malloc(cols * sizeof(double *));
    }
    return central_difference_v_next;
}
double **central_difference_p_next_x_create(int rows, int cols)
{
    double **central_difference_p_next_x = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        central_difference_p_next_x[i] = malloc(cols * sizeof(double *));
    }
    return central_difference_p_next_x;
}
double **central_difference_p_next_y_create(int rows, int cols)
{
    double **central_difference_p_next_y = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        central_difference_p_next_y[i] = malloc(cols * sizeof(double *));
    }
    return central_difference_p_next_y;
}

void **central_difference_u_x_init(double **central_difference_u_x, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            central_difference_u_x[i][j] = 0;
        }
    }
}
void **central_difference_u_y_init(double **central_difference_u_y, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            central_difference_u_y[i][j] = 0;
        }
    }
}
void **central_difference_v_x_init(double **central_difference_v_x, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            central_difference_v_x[i][j] = 0;
        }
    }
}
void **central_difference_v_y_init(double **central_difference_v_y, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            central_difference_v_y[i][j] = 0;
        }
    }
}
void **central_difference_p_x_init(double **central_difference_p_x, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            central_difference_p_x[i][j] = 0;
        }
    }
}
void **central_difference_p_y_init(double **central_difference_p_y, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            central_difference_p_y[i][j] = 0;
        }
    }
}
void **central_difference_u_laplace_init(double **central_difference_u_laplace, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            central_difference_u_laplace[i][j] = 0;
        }
    }
}
void **central_difference_v_laplace_init(double **central_difference_v_laplace, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            central_difference_v_laplace[i][j] = 0;
        }
    }
}
void **central_difference_u_tent_init(double **central_difference_u_tent, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            central_difference_u_tent[i][j] = 0;
        }
    }
}
void **central_difference_v_tent_init(double **central_difference_v_tent, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            central_difference_v_tent[i][j] = 0;
        }
    }
}
void **central_difference_u_next_init(double **central_difference_u_next, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            central_difference_u_next[i][j] = 0;
        }
    }
}
void **central_difference_v_next_init(double **central_difference_v_next, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            central_difference_v_next[i][j] = 0;
        }
    }
}
void **central_difference_p_next_x_init(double **central_difference_p_next_x, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            central_difference_p_next_x[i][j] = 0;
        }
    }
}
void **central_difference_p_next_y_init(double **central_difference_p_next_y, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            central_difference_p_next_y[i][j] = 0;
        }
    }
}
