#include <iostream>
#include <cmath>
#include <iomanip> // for output formatting
using namespace std;

/* Function to compute factorial iteratively using previous factorial */
long long factorial(int n, long long prevFact) {
     if(n==0) return 1; // handle base case
    return prevFact * n;
}

/* Function to compute power iteratively using previous power */
float power(float x, int n, float prevPower) {
     if(n==0) return 1.0;
    return prevPower * x;
}

/* Function to compute exp(x) using Taylor series with optimized term calculation */
float expTaylor(float x, int terms) {
    float sum = 1.0;      // first term = 1
    float prevPower = 1.0; // x^0
    long long prevFact = 1; // 0!

    for (int n = 1; n < terms; n++) {
        prevPower = power(x, n, prevPower);    // x^n
        prevFact = factorial(n, prevFact);     // n!
        sum += prevPower / prevFact;
    }

    return sum;
}

int main() {
    float x;
    int terms;

    /* Input */
    cout << "Enter value of x: ";
    cin >> x;

    /* Input validation */
    do {
        cout << "Enter number of terms (positive integer): ";
        cin >> terms;

        if (terms <= 0)
            cout << "Invalid input. Number of terms must be greater than 0.\n";
    } while (terms <= 0);

    /* Compute exp(x) */
    float approxValue = expTaylor(x, terms);
    float actualValue = exp(x);

    /* Output with fixed precision for clarity */
    cout << "\nUsing Taylor Series Approximation:\n";
    cout << "exp(" << x << ") ≈ " << approxValue << endl;

    cout << "\nUsing built-in exp() function:\n";
    cout << "exp(" << x << ") = " << actualValue << endl;

    cout << "\nAbsolute Error:\n";
    cout << fabs(actualValue - approxValue) << endl;

    return 0;
}
