#ifndef CENTRAL_VAL_INIT
#define CENTRAL_VAL_INIT

    double** central_difference_u_x_create(int rows, int cols);
    double** central_difference_u_y_create(int rows, int cols);
    double** central_difference_v_x_create(int rows, int cols);
    double** central_difference_v_y_create(int rows, int cols);
    double** central_difference_p_x_create(int rows, int cols);
    double** central_difference_p_y_create(int rows, int cols);
    double** central_difference_u_laplace_create(int rows, int cols);
    double** central_difference_v_laplace_create(int rows, int cols);
    double** central_difference_u_tent_create(int rows, int cols);
    double** central_difference_v_tent_create(int rows, int cols);
    double** central_difference_u_next_create(int rows, int cols);
    double** central_difference_v_next_create(int rows, int cols);
    double** central_difference_p_next_x_create(int rows, int cols);
    double** central_difference_p_next_y_create(int rows, int cols);

    void** central_difference_u_x_init(double **central_difference_u_x, int rows, int cols);
    void** central_difference_u_y_init(double **central_difference_u_y, int rows, int cols);
    void** central_difference_v_x_init(double **central_difference_v_x, int rows, int cols);
    void** central_difference_v_y_init(double **central_difference_v_y, int rows, int cols);
    void** central_difference_p_x_init(double **central_difference_p_x, int rows, int cols);
    void** central_difference_p_y_init(double **central_difference_p_y, int rows, int cols);
    void** central_difference_u_laplace_init(double **central_difference_u_laplace, int rows, int cols);
    void** central_difference_v_laplace_init(double **central_difference_v_laplace, int rows, int cols);
    void** central_difference_u_tent_init(double **central_difference_u_tent, int rows, int cols);
    void** central_difference_v_tent_init(double **central_difference_v_tent, int rows, int cols);
    void** central_difference_u_next_init(double **central_difference_u_next, int rows, int cols);
    void** central_difference_v_next_init(double **central_difference_v_next, int rows, int cols);
    void** central_difference_p_next_x_init(double **central_difference_p_next_x, int rows, int cols);
    void** central_difference_p_next_y_init(double **central_difference_p_next_y, int rows, int cols);

#endif