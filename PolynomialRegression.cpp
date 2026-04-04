//Basic Code
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, degree;

    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n];

    // Input data
    for (int i = 0; i < n; i++) {
        cout << "Enter x[" << i+1 << "] and y[" << i+1 << "]: ";
        cin >> x[i] >> y[i];
    }

    cout << "Enter degree of polynomial: ";
    cin >> degree;

    int m = degree + 1;

    // Array for sum of powers of x
    double X[2 * m];

    for (int i = 0; i <= 2 * degree; i++) {
        X[i] = 0;
        for (int j = 0; j < n; j++) {
            X[i] += pow(x[j], i);
        }
    }

    // Array for sum of y*x^i
    double Y[m];

    for (int i = 0; i < m; i++) {
        Y[i] = 0;
        for (int j = 0; j < n; j++) {
            Y[i] += pow(x[j], i) * y[j];
        }
    }

    // Augmented matrix
    double A[m][m+1];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = X[i + j];
        }
        A[i][m] = Y[i];
    }

    // Gauss Elimination
    for (int i = 0; i < m; i++) {
        for (int k = i + 1; k < m; k++) {
            double t = A[k][i] / A[i][i];
            for (int j = 0; j <= m; j++) {
                A[k][j] -= t * A[i][j];
            }
        }
    }

    // Back Substitution
    double a[m];

    for (int i = m - 1; i >= 0; i--) {
        a[i] = A[i][m];
        for (int j = i + 1; j < m; j++) {
            a[i] -= A[i][j] * a[j];
        }
        a[i] /= A[i][i];
    }

    // Output
    cout << "\nPolynomial Equation:\n";
    cout << "y = ";

    for (int i = 0; i < m; i++) {
        cout << a[i];
        if (i > 0) cout << "x^" << i;
        if (i != m - 1) cout << " + ";
    }

    cout << endl;

    return 0;
}
