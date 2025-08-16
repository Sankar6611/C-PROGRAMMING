c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Division by zero!\n");
        return 0;
    }
}

int main() {
    int (*operation)(int, int);  // Function pointer declaration
    int num1, num2, choice, result;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("\nSelect operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    // Assign function to pointer based on choice
    switch (choice) {
        case 1:
            operation = add;
            break;
        case 2:
            operation = subtract;
            break;
        case 3:
            operation = multiply;
            break;
        case 4:
            operation = divide;
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    
    // Call function through pointer
    result = operation(num1, num2);
    
    printf("Result: %d\n", result);
    
    return 0;
}
