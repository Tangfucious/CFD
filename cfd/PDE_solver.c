#include "solver.h"
#include "central_val_solver.h"
#include <stdio.h>
#include <math.h>

void PDE_solver(
    int **node,
    double **u,
    double **v,
    double **p,
    double **u_next,
    double **v_next,
    double **p_next,
    double **m,
    double dx,
    double dy,
    double VISCOSITY,
    double DENSITY,
    double dt,
    double front_u,
    double front_p,
    int rows, int cols)
{
    double error = 1;
    int step = 0;
    while (1)
    {
        if(error < 0.00000001)
        {
            break;
        }
        for(int i = 0; i<rows-1; i++)
        {
            if (node[i][1] == 1)
            {
                u_next[i][1] = front_u;
                p_next[i][1] = front_p;
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(node[i][j] == 0) {
                    u_next[i][j] = 0;
                }
                else if (j == 1 && node[i][1] == 1)
                {
                    u_next[i][1] = front_u;
                }
                else//if(node[i][j] == 1)
                {
                    u_next[i][j] = u[i][j]
                    -(dt*u[i][j]*(u[i][j+1]-u[i][j-1])/(2*pow(dx, 2)))
                    -(dt*v[i][j]*(u[i-1][j]-u[i+1][j])/(2*pow(dy, 2)))
                    -1/(DENSITY)*dt*((p[i][j+1]-p[i][j-1])/(2*pow(dx, 2)))
                    +dt*VISCOSITY*(((u[i][j+1]-2*u[i][j]+u[i][j-1])/(pow(dx, 2)))+((u[i+1][j]-2*u[i][j]+u[i-1][j])/pow(dy, 2)));
                }
                //printf("%lf\n", u_next[i][j]);
            }
        }
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j< cols; j++)
            {
                if(node[i][j] == 0)
                {
                    v_next[i][j] = 0;
                }
                if(node[i][j] == 1)
                {
                    v_next[i][j] = v[i][j]
                    -(dt*u[i][j]*((v[i][j+1]-v[i][j-1])/(2*pow(dx, 2))))
                    -(dt*v[i][j]*((v[i-1][j]-v[i+1][j])/(2*pow(dy, 2))))
                    -(1/DENSITY)*dt*(((v[i][j+1]-2*v[i][j]+v[i][j-1])/(pow(dx, 2)))+((v[i+1][j]-2*v[i][j]+v[i-1][j])/pow(dy, 2)));
                }
            }
        }
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                if(node[i][j] == 0)
                {
                    p[i][j] = 0;
                }
                else
                {
                    p[i][j] = (1.0/4)*(p[i+1][j]+p[i-1][j]+p[i][j+1]+p[i][j-1]
                    -pow(dx, 2)*pow(dy, 2)*(DENSITY/dt)*
                    ((u[i][j+1]-u[i][j-1])/(2*dx))+((v[i-1][j]-v[i+1][j])/(2*dy)));
                }
            }
        }
        step = step + 1;
        error = 0;
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                if(node[i][j] == 0)
                {
                    m[i][j] = 0;
                    error = error+fabs(m[i][j]);
                }
                else
                {
                    m[i][j] = (u[i][j+1]-u[i][j-1])/(2*dx)+((v[i-1][j]-v[i+1][j])/(2*dy));
                    error = error+fabs(m[i][j]);
                }
            }
        }
        if (step%1000 ==1)
        {
            printf("Error is %5.8lf for the step %d\n", error, step);
        }
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                u[i][j] = u_next[i][j];
                v[i][j] = v_next[i][j];
                p[i][j] = p_next[i][j];
            }
        }
    }
}