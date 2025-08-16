c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int length, isPalindrome = 1;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline if present
    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
    
    length = strlen(str);
    
    // Convert to lowercase for case-insensitive comparison
    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
    
    // Check palindrome
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }
    
    if (isPalindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    return 0;
}
