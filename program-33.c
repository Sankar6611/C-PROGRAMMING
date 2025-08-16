c
#include <stdio.h>

// Custom string copy function
char* my_strcpy(char* destination, const char* source) {
    char* start = destination;
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return start;
}

// Custom string concatenation function
char* my_strcat(char* destination, const char* source) {
    char* start = destination;
    
    // Move to end of destination string
    while (*destination != '\0') {
        destination++;
    }
    
    // Append source string
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return start;
}

// Custom string comparison function
int my_strcmp(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        }
        str1++;
        str2++;
    }
    
    if (*str1 == '\0' && *str2 == '\0') {
        return 0;   // Equal
    } else if (*str1 == '\0') {
        return -1;  // str1 is shorter
    } else {
        return 1;   // str2 is shorter
    }
}

int main() {
    char str1[100] = "Hello";
    char str2[100] = "World";
    char str3[100];
    char str4[100] = "Hello";
    
    printf("Original strings:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str4: %s\n", str4);
    
    // Test custom strcpy
    my_strcpy(str3, str1);
    printf("\nAfter my_strcpy(str3, str1):\n");
    printf("str3: %s\n", str3);
    
    // Test custom strcat
    my_strcat(str1, " ");
    my_strcat(str1, str2);
    printf("\nAfter my_strcat(str1, \" \") and my_strcat(str1, str2):\n");
    printf("str1: %s\n", str1);
    
    // Test custom strcmp
    printf("\nString comparison results:\n");
    printf("my_strcmp(str3, str4): %d\n", my_strcmp(str3, str4));
    printf("my_strcmp(str3, str2): %d\n", my_strcmp(str3, str2));
    printf("my_strcmp(str2, str3): %d\n", my_strcmp(str2, str3));
    
    return 0;
}
