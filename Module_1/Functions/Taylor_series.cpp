#include <iostream>
#include <cmath>
using namespace std;

/* Function to compute factorial iteratively */
long long factorial(int n) {
    if (n == 0) return 1;  // base case
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

/* Function to compute nth term of sine series:
   term(x, n) = (-1)^(n+1) * x^(2n-1) / (2n-1)! */
float term(float x, int n) {
    int powerExp = 2 * n - 1;
    float power = 1.0;

    // Compute x^(2n-1) iteratively
    for (int i = 1; i <= powerExp; i++)
        power *= x;

    long long fact = factorial(powerExp);

    // Alternating sign
    int sign = (n % 2 == 0) ? -1 : 1;

    return sign * power / fact;
}

/* Function to compute sin(x) using Taylor series */
float sinTaylor(float x, int terms) {
    float result = 0.0;

    for (int n = 1; n <= terms; n++) {
        result += term(x, n);
    }

    return result;
}

int main() {
    float X;       // angle in degrees
    int terms;     // number of terms for approximation

    // Input
    cout << "Enter angle in degrees: ";
    cin >> X;

    // Input validation
    do {
        cout << "Enter number of terms (positive integer): ";
        cin >> terms;

        if (terms <= 0)
            cout << "Invalid input. Number of terms must be greater than 0.\n";
    } while (terms <= 0);

    // Convert degrees to radians
    float x = X * M_PI / 180.0;

    // Compute sine using Taylor series
    float approxSin = sinTaylor(x, terms);
    float actualSin = sin(x);  // built-in sin for comparison

    // Output
   
    cout << "\nAngle: " << X << " degrees = " << x << " radians\n";
    cout << "Sin(" << X << ") using Taylor series (" << terms << " terms): " << approxSin << endl;
    cout << "Sin(" << X << ") using built-in sin(): " << actualSin << endl;
    cout << "Absolute Error: " << fabs(actualSin - approxSin) << endl;

    return 0;
}