#ifndef TENT_FIELD_INIT_H
#define TENT_FIELD_INIT_H
    double **u_tent_field_create(int rows, int cols);
    void **u_tent_field_init(double **u_tent, int rows, int cols);
    double **v_tent_field_create(int rows, int cols);
    void **v_tent_field_init(double **v_tent, int rows, int cols);
    double **p_tent_field_create(int rows, int cols);
    void **p_tent_field_init(double **p_tent, int rows, int cols);
#endif