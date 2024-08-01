#ifndef CENTRAL_VAL_SOLVER_H
#define CENTRAL_VAL_SOLVER_H
    void **central_difference_x(double **in, double **out, int **node, double element_length, int boundary_type, int rows, int cols);
    void **central_difference_y(double **in, double **out, int **node, double element_length, int boundary_type, int rows, int cols);
    void **central_difference_laplace(double **in, double **out, int **node, double dx, double dy, int boundary_type, int rows, int cols);
    
#endif