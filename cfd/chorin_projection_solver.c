#include "solver.h"
#include "central_val_solver.h"
#include "math.h"

void chorin_projection_solver(
    double **u,
    double **v,
    double **p,
    double **u_tent,
    double **v_tent,
    double **p_tent,
    double **u_next,
    double **v_next,
    double **p_next,
    double **central_difference_u_x,
    double **central_difference_u_y,
    double **central_difference_v_x,
    double **central_difference_v_y,
    double **central_difference_p_x,
    double **central_difference_p_y,
    double **central_difference_u_laplace,
    double **central_difference_v_laplace,
    double **central_difference_u_tent,
    double **central_difference_v_tent,
    double **central_difference_u_next,
    double **central_difference_v_next,
    double **central_difference_p_next_x,
    double **central_difference_p_next_y,
    double **rhs,
    int **node,
    double front_u,
    double front_p,
    double DENSITY,
    double KINEMATIC_VISCOSITY,
    double dx,
    double dy,
    double field_length,
    double dt,
    int rows, int cols, int boundary_type,
    int P_ITERATION)
{
    central_difference_x(u, central_difference_u_x, node, dx, boundary_type, rows, cols);
    central_difference_y(u, central_difference_u_y, node, dy, boundary_type, rows, cols);
    central_difference_x(v, central_difference_v_x, node, dx, boundary_type, rows, cols);
    central_difference_y(v, central_difference_v_y, node, dy, boundary_type, rows, cols);
    central_difference_laplace(u, central_difference_u_laplace, node, dx, dy, boundary_type, rows, cols);
    central_difference_laplace(v, central_difference_v_laplace, node, dx, dy, boundary_type, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (node[i][j] != 0)
            {
                u_tent[i][j] = u[i][j] + dt * (-(u[i][j] * central_difference_u_x[i][j] + v[i][j] * central_difference_u_y[i][j]) + KINEMATIC_VISCOSITY * central_difference_u_laplace[i][j]);
                v_tent[i][j] = v[i][j] + dt * (-(u[i][j] * central_difference_v_x[i][j] + v[i][j] * central_difference_v_y[i][j]) + KINEMATIC_VISCOSITY * central_difference_v_laplace[i][j]);
            }
        }
    }
    // maintain boundary conditions
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (node[i][j] == 0)
            {
                u_next[i][j] = 0;
                v_next[i][j] = 0;
            }
        }
    }
    // from the front
    for (int i = 0; i < rows; i++)
    {
        if (node[i][1] == 1)
        {
            u_next[i][1] = front_u;
            p_next[i][1] = front_p;
        }
    }
    // solve central difference for u_tent and v_tent
    central_difference_x(u_tent, central_difference_u_tent, node, dx, boundary_type, rows, cols);
    central_difference_y(v_tent, central_difference_v_tent, node, dy, boundary_type, rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (node[i][j] != 0)
            {
                rhs[i][j] = DENSITY / dt * (central_difference_u_tent[i][j] + central_difference_v_tent[i][j]);
            }
        }
    }
    for (int a = 0; a < P_ITERATION; a++)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (node[i][j] != 0)
                {
                    p_next[i][j] = (1.0 / 4) * (p[i][j - 1] + p[i - 1][j] + p[i][j + 1] + p[i + 1][j] - (dx*dy) * rhs[i][j]);
                }
                else
                {
                    p_next[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                p[i][j] = p_next[i][j];
            }
        }
    }
    central_difference_x(p_next, central_difference_p_next_x, node, dx, boundary_type, rows, cols);
    central_difference_y(p_next, central_difference_p_next_y, node, dy, boundary_type, rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            u_next[i][j] = u_tent[i][j] - dt / DENSITY * central_difference_p_next_x[i][j];
            v_next[i][j] = v_tent[i][j] - dt / DENSITY * central_difference_p_next_y[i][j];
        }
    }
    // maintain boundary conditions
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (node[i][j] == 0)
            {
                u_next[i][j] = 0;
                v_next[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        if (node[i][1] == 1)
        {
            u_next[i][1] = front_u;
        }
    }
    // iterate the value
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (node[i][j] == 1)
            {
                u[i][j] = u_next[i][j];
                v[i][j] = v_next[i][j];
                p[i][j] = p_next[i][j];
            }
        }
    }
}