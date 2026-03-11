#include <iostream>

int main() {
    int a = 10;
    double b = 3.7;

    // C-style casts
    double d1 = (double)a;    // int to double
    int i1 = (int)b;          // double to int (truncates)

    // C++ static_cast
    double d2 = static_cast<double>(a);
    int i2 = static_cast<int>(b);

    std::cout << "C-style cast int to double: d1 = " << d1 << std::endl;
    std::cout << "C-style cast double to int: i1 = " << i1 << " (truncates)" << std::endl;
    std::cout << "static_cast int to double: d2 = " << d2 << std::endl;
    std::cout << "static_cast double to int: i2 = " << i2 << " (truncates)" << std::endl;

    /*
    static_cast is preferred over C-style casts because:
      - It's more explicit and searchable in code.
      - It disallows dangerous reinterpretation or narrowing conversions unless explicit.
      - C-style cast can perform several kinds of conversions (static, const, reinterpret) and is therefore riskier.
      - static_cast is easier to find in code review and refactoring.
    */
    return 0;
}
