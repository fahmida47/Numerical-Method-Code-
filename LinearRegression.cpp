//Basic Code
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n];

    // Input data
    for (int i = 0; i < n; i++) {
        cout << "Enter x[" << i+1 << "] and y[" << i+1 << "]: ";
        cin >> x[i] >> y[i];
    }

    // Initialize sums
    double sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0;

    // Calculate sums
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
    }

    // Calculate slope (b) and intercept (a)
    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a = (sumY - b * sumX) / n;

    // Output result
    cout << "\nLinear Regression Equation: y = a + bx\n";
    cout << "a (Intercept) = " << a << endl;
    cout << "b (Slope) = " << b << endl;

    return 0;
}
