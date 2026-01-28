#include <stdio.h>
#include <limits.h>

/* Arithmetic operation functions */

/* Addition */
int add(int a, int b) {
    return a + b;
}

/* Subtraction */
int subtract(int a, int b) {
    return a - b;
}

/* Multiplication */
int multiply(int a, int b) {
    return a * b;
}

/* Division with error handling */
int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return INT_MIN;   // predefined error value
    }
    return a / b;
}

/*
   Generic calculate function (callback-style)
   - Takes two operands
   - Takes a function pointer to an arithmetic operation
*/
int calculate(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);   // callback invocation
}

int main() {
    int x = 20, y = 5;
    int result;

    /* Addition */
    result = calculate(x, y, add);
    printf("Addition (%d + %d) = %d\n", x, y, result);

    /* Subtraction */
    result = calculate(x, y, subtract);
    printf("Subtraction (%d - %d) = %d\n", x, y, result);

    /* Multiplication */
    result = calculate(x, y, multiply);
    printf("Multiplication (%d * %d) = %d\n", x, y, result);

    /* Division */
    result = calculate(x, y, divide);
    if (result != INT_MIN) {
        printf("Division (%d / %d) = %d\n", x, y, result);
    }

    /* Division by zero test */
    result = calculate(x, 0, divide);
    if (result != INT_MIN) {
        printf("Division (%d / 0) = %d\n", x, result);
    }

    return 0;
}
