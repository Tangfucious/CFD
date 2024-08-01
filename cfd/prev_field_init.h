#ifndef PREV_FIELD_INIT_H
#define PREV_FIELD_INIT_H
    double **u_field_create(int rows, int cols);
    void **u_field_init(double **u, int **node, int rows, int cols, double init_val, double front_u);
    double **v_field_create(int rows, int cols);
    void **v_field_init(double **v, int **node, int rows, int cols, double init_val);
    double **p_field_create(int rows, int cols);
    void **p_field_init(double **p, int **node, int rows, int cols, double init_val);
#endif