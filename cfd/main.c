#include <stdio.h>
#include <math.h>
// #include </home/jason/.openmpi/include/mpi.h>

#include "node_init.h"
#include "prev_field_init.h"
#include "tent_field_init.h"
#include "next_field_init.h"
#include "central_val_init.h"
#include "other_field_init.h"
#include "solver.h"
#include "optimizer.h"
#include <time.h>

enum
{
    all,
    up_down
};
// different solver types
enum
{
    chorin_projection_method,
    guass_sieldle_method,
    PDE_method
};

struct data
{
    double init_u;
    double init_v;
    double init_p;
    double front_u;
    double front_v;
    double front_p;
    double DENSITY;
    int P_ITERATION;
    double KINEMATIC_VISCOSITY;
    double Re;
    double delta;
} data;
struct field
{
    // suppose u is the u_prev
    double **u;
    double **v;
    double **p;
    double **u_tent;
    double **v_tent;
    double **p_tent;
    double **u_next;
    double **v_next;
    double **p_next;
    double **central_difference_u_x;
    double **central_difference_u_y;
    double **central_difference_v_x;
    double **central_difference_v_y;
    double **central_difference_p_x;
    double **central_difference_p_y;
    double **central_difference_u_laplace;
    double **central_difference_v_laplace;
    double **central_difference_u_tent;
    double **central_difference_v_tent;
    double **central_difference_u_next;
    double **central_difference_v_next;
    double **central_difference_p_next_x;
    double **central_difference_p_next_y;
    double **rhs;
    double **m;
    double element_length;
    double field_length;
    double dx;
    double dy;
    double dt;
    int **node;
} field;

int main(int argc, char *argv[])
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    // int process_Rank, size_Of_Cluster;
    // MPI_Init(&argc, &argv);
    // MPI_Comm_size(MPI_COMM_WORLD, &size_Of_Cluster);
    // MPI_Comm_rank(MPI_COMM_WORLD, &process_Rank);

    int count = 0;
    char *mesh_file = NULL;
    int total_node;
    int rows, cols;
    int x = 100, y = 100;
    int solver_type;
    int boundary_type;
    int N_ITERATION = 10000; // 1e7;

    double t = 0;
    double run_time = 0.05;

    data.init_u = 100;
    data.init_v = 0;
    data.init_p = 101325; // 101325;
    data.front_u = 100;
    data.front_v = 0;
    data.front_p = 101325;               // 101325;
    data.KINEMATIC_VISCOSITY = 0.1; // 0.00001;
    data.DENSITY = 1;
    data.P_ITERATION = 50;
    field.field_length = 1;
    field.element_length = field.field_length / x;
    field.dx = field.dy = field.element_length;
    field.dt = 0.00001;

    boundary_type = all;
    solver_type = chorin_projection_method;

    // chorin projection method
    if (solver_type == chorin_projection_method)
    {
        double MAX_dt = 0.5 * pow(field.element_length, 2) / data.KINEMATIC_VISCOSITY;
        printf("Max Time Step: %lf\n", MAX_dt);
        printf("Element Length: %lf\n", field.element_length);
        if (boundary_type == all)
        {
            total_node = x * y + 2 * x + 2 * y;
            rows = y + 2, cols = x + 2;
        }
        if (boundary_type == up_down)
        {
            total_node = x * y + 2 * y;
            rows = y + 2, cols = x;
        }
        // initializations
        field.node = node_field_create(rows, cols);
        node_field_init(field.node, rows, cols, boundary_type);
        field.u = u_field_create(rows, cols);
        u_field_init(field.u, field.node, rows, cols, data.init_u, data.front_u);
        field.v = v_field_create(rows, cols);
        v_field_init(field.v, field.node, rows, cols, data.init_v);
        field.p = p_field_create(rows, cols);
        p_field_init(field.p, field.node, rows, cols, data.init_p);
        field.u_tent = u_tent_field_create(rows, cols);
        u_tent_field_init(field.u_tent, rows, cols);
        field.v_tent = v_tent_field_create(rows, cols);
        v_tent_field_init(field.v_tent, rows, cols);
        field.p_tent = p_tent_field_create(rows, cols);
        p_tent_field_init(field.p_tent, rows, cols);
        field.u_next = u_next_field_create(rows, cols);
        u_next_field_init(field.u_next, rows, cols);
        field.v_next = v_next_field_create(rows, cols);
        v_next_field_init(field.v_next, rows, cols);
        field.p_next = p_next_field_create(rows, cols);
        p_next_field_init(field.p_next, rows, cols);
        field.central_difference_u_x = central_difference_u_x_create(rows, cols);
        central_difference_u_x_init(field.central_difference_u_x, rows, cols);
        field.central_difference_u_y = central_difference_u_y_create(rows, cols);
        central_difference_u_y_init(field.central_difference_u_y, rows, cols);
        field.central_difference_v_x = central_difference_v_x_create(rows, cols);
        central_difference_v_x_init(field.central_difference_v_x, rows, cols);
        field.central_difference_v_y = central_difference_v_y_create(rows, cols);
        central_difference_v_y_init(field.central_difference_v_y, rows, cols);
        field.central_difference_p_x = central_difference_p_x_create(rows, cols);
        central_difference_p_x_init(field.central_difference_p_x, rows, cols);
        field.central_difference_p_y = central_difference_p_y_create(rows, cols);
        central_difference_p_y_init(field.central_difference_p_y, rows, cols);
        field.central_difference_u_laplace = central_difference_u_laplace_create(rows, cols);
        central_difference_u_laplace_init(field.central_difference_u_laplace, rows, cols);
        field.central_difference_v_laplace = central_difference_v_laplace_create(rows, cols);
        central_difference_v_laplace_init(field.central_difference_v_laplace, rows, cols);
        field.central_difference_u_tent = central_difference_u_tent_create(rows, cols);
        central_difference_u_tent_init(field.central_difference_u_tent, rows, cols);
        field.central_difference_v_tent = central_difference_v_tent_create(rows, cols);
        central_difference_v_tent_init(field.central_difference_u_tent, rows, cols);
        field.central_difference_u_next = central_difference_u_next_create(rows, cols);
        central_difference_u_next_init(field.central_difference_u_next, rows, cols);
        field.central_difference_v_next = central_difference_v_next_create(rows, cols);
        central_difference_v_next_init(field.central_difference_v_next, rows, cols);
        field.central_difference_p_next_x = central_difference_p_next_x_create(rows, cols);
        central_difference_p_next_x_init(field.central_difference_p_next_x, rows, cols);
        field.central_difference_p_next_y = central_difference_p_next_y_create(rows, cols);
        central_difference_p_next_y_init(field.central_difference_p_next_y, rows, cols);
        field.rhs = rhs_create(rows, cols);
        rhs_init(field.rhs, rows, cols);
        field.m = m_create(rows, cols);
        m_init(field.m, rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if ((j) % cols == 0)
                {
                    printf("\n");
                }
                printf("%d ", field.node[i][j]);
            }
        }

        printf("\n");

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if ((j) % cols == 0)
                {
                    printf("\n");
                }
                printf("%lf ", field.u[i][j]);
            }
        }

        for (int iter_time = 0; iter_time < N_ITERATION; iter_time++)
        {
            chorin_projection_solver(
                field.u,
                field.v,
                field.p,
                field.u_tent,
                field.v_tent,
                field.p_tent,
                field.u_next,
                field.v_next,
                field.p_next,
                field.central_difference_u_x,
                field.central_difference_u_y,
                field.central_difference_v_x,
                field.central_difference_v_y,
                field.central_difference_p_x,
                field.central_difference_p_y,
                field.central_difference_u_laplace,
                field.central_difference_v_laplace,
                field.central_difference_u_tent,
                field.central_difference_v_tent,
                field.central_difference_u_next,
                field.central_difference_v_next,
                field.central_difference_p_next_x,
                field.central_difference_p_next_y,
                field.rhs,
                field.node,
                data.front_u,
                data.front_p,
                data.DENSITY,
                data.KINEMATIC_VISCOSITY,
                field.dx,
                field.dy,
                field.field_length,
                field.dt,
                rows, cols, boundary_type,
                data.P_ITERATION);
        }
        FILE *outfile;
        outfile = fopen("./outfile.plt", "w+");
        if (outfile == NULL)
        {
            printf("file does not exist");
        }
        else
        {
            fprintf(outfile, "VARIABLES=\"X\",\"Y\",\"U\",\"V\",\"P\"\n");
            fprintf(outfile, "ZONE  F=POINT\n");
            fprintf(outfile, "I=%d, J=%d\n", x, y);

            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    double xpos, ypos;
                    xpos = j * field.element_length;
                    ypos = i * field.element_length;

                    fprintf(outfile, "%5.8lf\t%5.8lf\t%5.8lf\t%5.8lf\t%5.8lf\n", xpos, ypos, field.u[i][j], field.v[i][j], field.p[i][j]);
                }
            }
        }
        // MPI_Finalize();
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time: %lf\n", cpu_time_used);
    }
    if (solver_type == PDE_method)
    {
        data.Re = 100;
        data.delta = 4.5;
        double MAX_dt = 0.5 * pow(field.element_length, 2) / data.KINEMATIC_VISCOSITY;
        printf("Max Time Step: %lf\n", MAX_dt);
        printf("Element Length: %lf\n", field.element_length);
        if (boundary_type == all)
        {
            total_node = x * y + 2 * x + 2 * y;
            rows = y + 2, cols = x + 2;
        }
        if (boundary_type == up_down)
        {
            total_node = x * y + 2 * y;
            rows = y + 2, cols = x;
        }
        printf("rows: %d, cols: %d\n", rows, cols);

        // initializations
        field.node = node_field_create(rows, cols);
        node_field_init(field.node, rows, cols, boundary_type);
        field.u = u_field_create(rows, cols);
        u_field_init(field.u, field.node, rows, cols, data.init_u, data.front_u);
        field.v = v_field_create(rows, cols);
        v_field_init(field.v, field.node, rows, cols, data.init_v);
        field.p = p_field_create(rows, cols);
        p_field_init(field.p, field.node, rows, cols, data.init_p);
        field.u_next = u_next_field_create(rows, cols);
        u_next_field_init(field.u_next, rows, cols);
        field.v_next = v_next_field_create(rows, cols);
        v_next_field_init(field.v_next, rows, cols);
        field.p_next = p_next_field_create(rows, cols);
        p_next_field_init(field.p_next, rows, cols);
        field.m = m_create(rows, cols);
        m_init(field.m, rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if ((j) % cols == 0)
                {
                    printf("\n");
                }
                printf("%lf ", field.u[i][j]);
            }
        }
        printf("\n\n%lf\n", field.dy);

        PDE_solver(
            field.node,
            field.u,
            field.v,
            field.p,
            field.u_next,
            field.v_next,
            field.p_next,
            field.m,
            field.dx,
            field.dy,
            data.KINEMATIC_VISCOSITY,
            data.DENSITY,
            field.dt,
            data.front_u,
            data.front_p,
            rows, cols);

        FILE *outfile;
        outfile = fopen("./outfile.plt", "w+");
        if (outfile == NULL)
        {
            printf("file does not exist");
        }
        else
        {
            fprintf(outfile, "VARIABLES=\"X\",\"Y\",\"U\",\"V\",\"P\"\n");
            fprintf(outfile, "ZONE  F=POINT\n");
            fprintf(outfile, "I=%d, J=%d\n", x, y);

            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    double xpos, ypos;
                    xpos = j * field.element_length;
                    ypos = i * field.element_length;

                    fprintf(outfile, "%5.8lf\t%5.8lf\t%5.8lf\t%5.8lf\t%5.8lf\n", xpos, ypos, field.u[i][j], field.v[i][j], field.p[i][j]);
                }
            }
        }
        // MPI_Finalize();
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time: %lf\n", cpu_time_used);
    }

    return 0;
}
