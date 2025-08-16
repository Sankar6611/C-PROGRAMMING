c
#include <stdio.h>

int main() {
    int num1, num2, gcd, lcm, temp;
    
    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);
    
    int a = num1, b = num2;
    
    // Find GCD using Euclidean algorithm
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    
    gcd = a;
    lcm = (num1 * num2) / gcd;
    
    printf("LCM of %d and %d = %d\n", num1, num2, lcm);
    
    return 0;
}
