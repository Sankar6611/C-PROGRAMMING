c
#include <stdio.h>
#include <string.h>

int main() {
    char str[100], reversed[100];
    int length, j = 0;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    length = strlen(str);
    
    // Reverse the string
    for (int i = length - 1; i >= 0; i--) {
        reversed[j] = str[i];
        j++;
    }
    reversed[j] = '\0';  // Null terminate
    
    printf("Original string: %s\n", str);
    printf("Reversed string: %s\n", reversed);
    
    return 0;
}
