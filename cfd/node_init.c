#include "node_init.h"
#include <stdio.h>
#include <stdlib.h>

enum
{
    all,
    up_down
};

int **node_field_create(int rows, int cols)
{
    int **node = malloc(rows * sizeof(double *));
    for (size_t i = 0; i < rows; i++)
    {
        node[i] = malloc(cols * sizeof(double *));
    }
    return node;
}

void **node_field_init(int **node, int rows, int cols, int boundary_type)
{
    if (boundary_type == all)
    {
        for (int i = 1; i < rows - 1; i++)
        {
            for (int j = 1; j < cols - 1; j++)
            {
                node[i][j] = 1;
            }
        }
        for (int i = 0; i < cols; i++)
        {
            node[0][i] = 0;
            node[rows - 1][i] = 0;
        }
        for (int i = 0; i < rows; i++)
        {
            node[i][0] = 0;
            node[i][cols - 1] = 0;
        }
    }
    if (boundary_type == up_down)
    {
        for (int i = 1; i < rows - 1; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                node[i][j] = 1;
            }
        }
        for (int i = 0; i < cols; i++)
        {
            node[0][i] = 0;
            // row-1 because in arry it starts with 0
            node[rows - 1][i] = 0;
        }
    }
}