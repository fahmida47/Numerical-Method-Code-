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

    double xp;
    cout << "Enter value of xp: ";
    cin >> xp;

    double yp = 0;

    // Lagrange Interpolation
    for (int i = 0; i < n; i++) {
        double p = 1;

        for (int j = 0; j < n; j++) {
            if (i != j) {
                p *= (xp - x[j]) / (x[i] - x[j]);
            }
        }

        yp += p * y[i];
    }

    // Output
    cout << "\nInterpolated value at x = " << xp << " is y = " << yp << endl;

    return 0;
}
