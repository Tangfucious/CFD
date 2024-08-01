#include "optimizer.h"
#include "solver.h"
#include <math.h>
#include <stdio.h>

void optimizer(double **u,
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
               double DENSITY,
               double KINEMATIC_VISCOSITY,
               double element_length,
               double field_length,
               double dt,
               int rows, int cols, int boundary_type,
               int P_ITERATION, int N_ITERATION)
{
    double prev_lift, next_lift;
    double thickness;
    double up_area, down_area;

    double y;
    double r = 0.5;                     // radius of the circle
    int ST = 1+((field_length - r) / 2)/element_length; //starting point of the circle (when boundary type is ALL)
    int ET = cols-ST;
    printf("ST: %d\n", ST);
    // initialize the circle
    for (int j = 0; j < ET; j++)
    {
        // j+1/2 is the center point of it, so the length must be odd
        y = (pow(r, 2) - pow(j-(rows+1)/2, 2)) + ((rows + 1) / 2);
        
        //printf("%lf ", y);
        // initialize the part above the center
        for (int i = 0; i < cols; i++)
        {
            for (int a = (rows + 1) / 2; a < ET; a++)
            {
                if (y - a * element_length > 0)
                {
                    node[a][j] = 1;
                }
            }
        }
        // initialize the negative part
        //  for (int a = j - 1; a > 0; a--)
        //  {
        //      if((j-1-y)<=0)
        //      {
        //          node[a][i] = 1;
        //      }
        //  }
    }

    // reduce nodes from the circle
    // testify weather it produce more lift than the previous one
    // in topology to testify they are in one shape

    // while (1)
    // {
    //     // run stimulation
    //     //for (int iter_time = 0; iter_time < N_ITERATION; iter_time++)
    //     {
    //         solver(
    //             u,
    //             v,
    //             p,
    //             u_tent,
    //             v_tent,
    //             p_tent,
    //             u_next,
    //             v_next,
    //             p_next,
    //             central_difference_u_x,
    //             central_difference_u_y,
    //             central_difference_v_x,
    //             central_difference_v_y,
    //             central_difference_p_x,
    //             central_difference_p_y,
    //             central_difference_u_laplace,
    //             central_difference_v_laplace,
    //             central_difference_u_tent,
    //             central_difference_v_tent,
    //             central_difference_u_next,
    //             central_difference_v_next,
    //             central_difference_p_next_x,
    //             central_difference_p_next_y,
    //             rhs,
    //             node,
    //             front_u,
    //             DENSITY,
    //             KINEMATIC_VISCOSITY,
    //             element_length,
    //             field_length,
    //             dt,
    //             rows, cols, boundary_type,
    //             P_ITERATION);
    //     }
    //     break;
    // }
}
