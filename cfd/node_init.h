#ifndef NODE_INIT
#define NODE_INIT
    int** node_field_create(int rows, int cols);
    void** node_field_init(int **node, int rows, int cols, int boundary_type);
#endif