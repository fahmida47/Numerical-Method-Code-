// With Partia Pivoting=> Row swap ache   1stly pivot Select 	numerical stability beshi

#include <iostream>
#include <vector>
#include <iomanip> // for setprecision
#include <cmath>
using namespace std;

// Function to perform Gauss Elimination with Partial Pivoting
int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n + 1)); // augmented matrix
    vector<double> x(n);

    cout << "Enter the augmented matrix coefficients row-wise:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Forward Elimination with Partial Pivoting
    for (int k = 0; k < n - 1; k++) {
        // Partial Pivoting: find max in column k from row k to n-1
        int maxRow = k;
        for (int i = k + 1; i < n; i++) {
            if (fabs(a[i][k]) > fabs(a[maxRow][k]))
                maxRow = i;
        }
        // Swap rows if needed
        if (maxRow != k)
            swap(a[k], a[maxRow]);

        // Eliminate below pivot
        for (int i = k + 1; i < n; i++) {
            double factor = a[i][k] / a[k][k];
            for (int j = k; j <= n; j++) {
                a[i][j] -= factor * a[k][j];
            }
        }
    }

    // Print Upper Triangular Matrix
    cout << "\nUpper Triangular Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << fixed << setprecision(3) << a[i][j] << "\t";
        }
        cout << endl;
    }

    // Back Substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }

    // Print solution
    cout << "\nSolution Vector:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(3) << x[i] << endl;
    }

    return 0;
}
