#include <stdio.h>

int main() {
    int n, sum = 0;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];  // Add each element to sum
    }
    
    printf("Sum of all elements = %d\n", sum);
    
    return 0;
}
