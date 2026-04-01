//Basic Code
#include <iostream>
#include <cmath>
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

    // Calculate sums using log
    for (int i = 0; i < n; i++) {
        double lx = log(x[i]);
        double ly = log(y[i]);

        sumX += lx;
        sumX2 += lx * lx;
        sumY += ly;
        sumXY += lx * ly;
    }

    // Calculate b and a (in log form)
    double b_log = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a_log = (sumY - b_log * sumX) / n;

    // Convert back from log
    double a = exp(a_log);
    double b = exp(b_log);

    // Output
    cout << "\nCurve Fitting Equation: y = a * b^x\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
