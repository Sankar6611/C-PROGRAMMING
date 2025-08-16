c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr, sum = 0;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // Allocate memory dynamically
    arr = (int*)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    printf("Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Sum of elements: %d\n", sum);
    printf("Average: %.2f\n", (float)sum / n);
    
    // Free allocated memory
    free(arr);
    
    printf("Memory freed successfully.\n");
    
    return 0;
}
