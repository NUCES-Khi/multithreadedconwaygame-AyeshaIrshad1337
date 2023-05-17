#include <stdio.h>
#include <pthread.h>

#define N 4
#define NUM_THREADS 4

typedef struct {
    int start_row;
    int end_row;
    int (*grid)[N];
    int (*newGrid)[N];
} thread_data_t;

void print_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(int n, int m, int grid[N][N]) {
    int neighbors = 0;
    for (int c = m - 1; c <= m + 1; c++) {
        for (int r = n - 1; r <= n + 1; r++) {
            if (r >= 0 && r < N && c >= 0 && c < N && !(r == n && c == m) && grid[r][c] == 1) {
                neighbors++;
            }
        }
    }
    return neighbors;
}

void update_grid(int n, int m, int grid[N][N], int neighbors, int newGrid[N][N]) {
    // Update cell state based on neighbors
    if (grid[n][m] == 1) {
        if (neighbors == 2 || neighbors == 3) {
            newGrid[n][m] = 1;
        } else {
            newGrid[n][m] = 0;
        }
    } else {
        if (neighbors == 3) {
            newGrid[n][m] = 1;
        } else {
            newGrid[n][m] = 0;
        }
    }
}

void *grid_work(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    for (int i = data->start_row; i < data->end_row; i++) {
        for (int j = 0; j < N; j++) {
            int neighbors = count_neighbors(i, j, data->grid);
            update_grid(i, j, data->grid, neighbors, data->newGrid);
        }
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];

    int newGrid[N][N];
    int grid[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            newGrid[i][j] = 0;
        }
    }

    printf("Enter only 0 for no life and 1 for life\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int gen = 0;
    printf("Enter number of generations: ");
    scanf("%d", &gen);

    for (int g = 0; g < gen; g++) {

        // Create threads
        for (int t = 0; t < NUM_THREADS; t++) {
            thread_data[t].start_row = t * N / NUM_THREADS;
            thread_data[t].end_row = (t + 1) * N / NUM_THREADS;
            thread_data[t].grid = grid;
            thread_data[t].newGrid = newGrid;

            pthread_create(&threads[t], NULL, grid_work, &thread_data[t]);
        }

        // Wait for threads to finish
        for (int t = 0; t < NUM_THREADS; t++) {
            pthread_join(threads[t], NULL);
        }

        // Copy newGrid to grid
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }

        // Print current generation
        printf("Generation %d:\n", g + 1);
        print_grid(grid);
    }

    return 0;
}
