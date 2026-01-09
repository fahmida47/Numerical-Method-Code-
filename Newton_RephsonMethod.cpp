//-----------------------------------Newton Raphson Method--------------------------------//

#include <bits/stdc++.h>
using namespace std;

// Function f(x)
double f(double x) {
    return x*x -3*x +2;
}

// Derivative f'(x)
double f_der(double x) {
    return  2*x-3;
}

int main() {
    double x0, x1, f1, e;
    int iteration = 0;

    // Input
    cout << "Enter initial guess x0: ";
    cin >> x0;

    cout << "Enter tolerable error: ";
    cin >> e;

    // Table header
    cout << fixed << setprecision(6);
    cout << "\nIteration\t x_n\t\t f(x_n)\t\t f'(x_n)\t x_{n+1}\n";
    cout << "---------------------------------------------------------------------\n";

    do {
        double fx = f(x0);
        double fdx = f_der(x0);

        if (fdx == 0.0) {
            cout << "Mathematical Error (Derivative = 0)" << endl;
            return 0;
        }

        x1 = x0 - fx / fdx;
        f1 = fabs(f(x1));

        iteration++;
        cout << iteration << "\t\t" << x0 << "\t " << fx << "\t " << fdx << "\t " << x1 << endl;

        x0 = x1;

    } while (f1 > e);

    cout << "\nRoot = " << x1 << endl;
    cout << "Total Iterations = " << iteration << endl;

    return 0;
}
