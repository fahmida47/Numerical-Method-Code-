//--------------------------------Fixed Point Method----------------------------------------//

#include <iostream>
#include <cmath>
#include <iomanip>   // for setw and setprecision

using namespace std;

// Define the function f(x)
double f(double x) {
    return x*x - 4;   // Example: f(x) = x^2 - 4
}

// Define the convergent form g(x)
double g(double x) {
    return 0.5 * (x + 4/x);  // Example: x = sqrt(4) iteration form
}

int main() {
    double x0, x1, e;
    int N;

    // Input initial guess, tolerable error, and max iterations
    cout << "Enter initial guess x0: ";
    cin >> x0;
    cout << "Enter tolerable error e: ";
    cin >> e;
    cout << "Enter maximum iterations N: ";
    cin >> N;

    int step = 1;

    // Print table header
    cout << setw(10) << "Iteration"
         << setw(15) << "x"
         << setw(20) << "f(x)" << endl;
    cout << "----------------------------------------" << endl;

    while (true) {
        x1 = g(x0);  // Fixed point iteration

        // Print current iteration
        cout << setw(10) << step
             << setw(15) << fixed << setprecision(6) << x1
             << setw(20) << fixed << setprecision(6) << f(x1) << endl;

        if (fabs(f(x1)) <= e) {  // Check convergence
            cout << "\nThe root is approximately: " << x1 << endl;
            break;
        }

        step++;
        if (step > N) {
            cout << "\nNot Convergent after " << N << " iterations." << endl;
            break;
        }

        x0 = x1;  // Update for next iteration
    }

    return 0;
}

