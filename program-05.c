c
#include <stdio.h>

int main() {
    int num, sum = 0, digit;
    
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    int originalNum = num;
    num = (num < 0) ? -num : num;  // Handle negative numbers
    
    while (num > 0) {
        digit = num % 10;
        sum += digit;
        num /= 10;
    }
    
    printf("Sum of digits of %d = %d\n", originalNum, sum);
    
    return 0;
}
