c
#include <stdio.h>

int main() {
    int num, reversed = 0, remainder;
    
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    int originalNum = num;
    int isNegative = (num < 0) ? 1 : 0;
    num = (num < 0) ? -num : num;
    
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    
    if (isNegative) {
        reversed = -reversed;
    }
    
    printf("Reverse of %d = %d\n", originalNum, reversed);
    
    return 0;
}
