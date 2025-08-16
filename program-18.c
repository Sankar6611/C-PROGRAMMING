c
#include <stdio.h>

union Data {
    int integer;
    float floating;
    char character;
};

int main() {
    union Data data;
    
    printf("Size of union: %lu bytes\n\n", sizeof(data));
    
    // Store integer
    data.integer = 42;
    printf("Storing integer 42:\n");
    printf("Integer: %d\n", data.integer);
    printf("Float: %f\n", data.floating);
    printf("Character: %c\n\n", data.character);
    
    // Store float
    data.floating = 3.14f;
    printf("Storing float 3.14:\n");
    printf("Integer: %d\n", data.integer);
    printf("Float: %f\n", data.floating);
    printf("Character: %c\n\n", data.character);
    
    // Store character
    data.character = 'A';
    printf("Storing character 'A':\n");
    printf("Integer: %d\n", data.integer);
    printf("Float: %f\n", data.floating);
    printf("Character: %c\n", data.character);
    
    return 0;
}
