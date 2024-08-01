#include "central_val_solver.h"
#include <math.h>

//for chorin projection method

void **central_difference_x(double **in, double **out, int **node, double dx, int boundary_type, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (node[i][j] == 1)
            {
                out[i][j] = (in[i][j + 1] - in[i][j - 1]) / (2 * dx);
            }
        }
    }
}
void **central_difference_y(double **in, double **out, int **node, double dy, int boundary_type, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (node[i][j] == 1)
            {
                out[i][j] = (in[i - 1][j] - in[i + 1][j]) / (2 * dy);
            }
        }
    }
}
void **central_difference_laplace(double **in, double **out, int **node, double dx, double dy, int boundary_type, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (node[i][j] == 1)
            {
                out[i][j] = ((in[i][j+1]-2*in[i][j]+in[i][j-1])/pow(dx, 2))+((in[i+1][j]-2*in[i][j]+in[i-1][j])/pow(dy, 2));
            }
        }
    }
}

//for pde method
