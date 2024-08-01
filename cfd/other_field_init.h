#ifndef OTHER_FIELD_INIT
#define OTHER_FIELD_INIT
    double **rhs_create(int rows, int cols);
    void **rhs_init(double **rhs, int rows, int cols);
    double **m_create(int rows, int cols);
    void **m_init(double **rhs, int rows, int cols);
#endif