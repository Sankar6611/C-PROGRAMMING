c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Program name: %s\n", argv[0]);
    printf("Number of arguments: %d\n", argc);
    
    if (argc < 2) {
        printf("Usage: %s <numbers>\n", argv[0]);
        printf("Example: %s 10 20 30\n", argv[0]);
        return 1;
    }
    
    printf("Arguments provided:\n");
    for (int i = 1; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    
    // Calculate sum if all arguments are numbers
    int sum = 0;
    printf("\nCalculating sum of numeric arguments:\n");
    for (int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        printf("%s -> %d\n", argv[i], num);
        sum += num;
    }
    
    printf("Sum: %d\n", sum);
    
    return 0;
}
