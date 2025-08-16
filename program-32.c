c
#include <stdio.h>

int main() {
    int depth = 2, rows = 3, cols = 4;
    int array3D[2][3][4];
    int value = 1;
    
    printf("Initializing 3D array [%d][%d][%d]:\n", depth, rows, cols);
    
    // Initialize 3D array
    for (int d = 0; d < depth; d++) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                array3D[d][r][c] = value++;
            }
        }
    }
    
    // Display 3D array
    for (int d = 0; d < depth; d++) {
        printf("\nLayer %d:\n", d + 1);
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                printf("%3d ", array3D[d][r][c]);
            }
            printf("\n");
        }
    }
    
    // Calculate sum of all elements
    int sum = 0;
    for (int d = 0; d < depth; d++) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                sum += array3D[d][r][c];
            }
        }
    }
    
    printf("\nArray Statistics:\n");
    printf("Total elements: %d\n", depth * rows * cols);
    printf("Sum of all elements: %d\n", sum);
    printf("Average: %.2f\n", (float)sum / (depth * rows * cols));
    
    // Find maximum and minimum
    int max = array3D[0][0][0];
    int min = array3D[0][0][0];
    
    for (int d = 0; d < depth; d++) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (array3D[d][r][c] > max) {
                    max = array3D[d][r][c];
                }
                if (array3D[d][r][c] < min) {
                    min = array3D[d][r][c];
                }
            }
        }
    }
    
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
    
    return 0;
}
