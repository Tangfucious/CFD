#ifndef NEXT_FIELD_INIT
#define NEXT_FIELD_INIT
    double **u_next_field_create(int rows, int cols);
    void **u_next_field_init(double **u_next, int rows, int cols);
    double **v_next_field_create(int rows, int cols);
    void **v_next_field_init(double **v_next, int rows, int cols);
    double **p_next_field_create(int rows, int cols);
    void **p_next_field_init(double **p_next, int rows, int cols);
#endif