#ifndef SOLVER
#define SOLVER
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
    int P_ITERATION);
void gausee_seildel_solver(
    double **u,
    double **v,
    double **p,
    double DENSITY,
    double element_lengthint,
    double dt, int rows, int cols);
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
    int rows, int cols);
#endif