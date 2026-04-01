//Basic Code
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n][n];

    // Input x and y
    for (int i = 0; i < n; i++) {
        cout << "Enter x[" << i << "] and y[" << i << "]: ";
        cin >> x[i] >> y[i][0];
    }

    double xp;
    cout << "Enter value of xp: ";
    cin >> xp;

    // Divided Difference Table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j+1][i-1] - y[j][i-1]) / (x[j+i] - x[j]);
        }
    }

    // Apply Newton Formula
    double yp = y[0][0];

    for (int i = 1; i < n; i++) {
        double product = 1;

        for (int j = 0; j < i; j++) {
            product *= (xp - x[j]);
        }

        yp += product * y[0][i];
    }

    // Output
    cout << "\nInterpolated value at x = " << xp << " is y = " << yp << endl;

    return 0;
}
