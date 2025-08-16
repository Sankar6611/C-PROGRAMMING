c
#include <stdio.h>

void printBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

int main() {
    int a, b;
    
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    
    printf("\nNumbers in binary:\n");
    printf("a = %d: ", a);
    printBinary(a);
    printf("b = %d: ", b);
    printBinary(b);
    
    printf("\nBitwise Operations:\n");
    
    // AND operation
    printf("a & b = %d: ", a & b);
    printBinary(a & b);
    
    // OR operation
    printf("a | b = %d: ", a | b);
    printBinary(a | b);
    
    // XOR operation
    printf("a ^ b = %d: ", a ^ b);
    printBinary(a ^ b);
    
    // NOT operation
    printf("~a = %d: ", ~a);
    printBinary(~a);
    
    // Left shift
    printf("a << 2 = %d: ", a << 2);
    printBinary(a << 2);
    
    // Right shift
    printf("a >> 2 = %d: ", a >> 2);
    printBinary(a >> 2);
    
    return 0;
}
