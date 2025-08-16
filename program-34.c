#include <stdio.h>

// Global variable (extern demonstration)
int globalVar = 10;

void demoFunction() {
    // auto variable (default in local scope)
    auto int autoVar = 5;

    // static variable (retains value between function calls)
    static int staticVar = 0;

    // register variable (request to store in CPU register)
    register int regVar = 15;

    printf("autoVar = %d\n", autoVar);
    printf("staticVar = %d\n", staticVar);
    printf("regVar = %d\n", regVar);
    printf("globalVar = %d\n", globalVar);

    // Modify variables
    autoVar++;
    staticVar++;
    globalVar++;
    regVar++;
}

int main() {
    printf("First call to demoFunction():\n");
    demoFunction();

    printf("\nSecond call to demoFunction():\n");
    demoFunction();

    printf("\nThird call to demoFunction():\n");
    demoFunction();

    return 0;
}
