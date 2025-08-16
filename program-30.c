c
#include <stdio.h>

#define PI 3.14159
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SQUARE(x) ((x) * (x))

#ifdef DEBUG
    #define PRINT_DEBUG(x) printf("Debug: %s = %d\n", #x, x)
#else
    #define PRINT_DEBUG(x)
#endif

#define VERSION "1.0"
#define AUTHOR "Programming Guide"

int main() {
    printf("Program Information:\n");
    printf("Version: %s\n", VERSION);
    printf("Author: %s\n", AUTHOR);
    printf("Compiled on: %s at %s\n", __DATE__, __TIME__);
    printf("File: %s\n", __FILE__);
    printf("Line: %d\n\n", __LINE__);
    
    // Using defined macros
    double radius = 5.0;
    double area = PI * SQUARE(radius);
    
    printf("Circle with radius %.2f:\n", radius);
    printf("Area = %.2f\n\n", area);
    
    int a = 15, b = 20;
    printf("Numbers: a = %d, b = %d\n", a, b);
    printf("MAX(%d, %d) = %d\n", a, b, MAX(a, b));
    printf("MIN(%d, %d) = %d\n", a, b, MIN(a, b));
    
    PRINT_DEBUG(a);
    PRINT_DEBUG(b);
    
    return 0;
}
