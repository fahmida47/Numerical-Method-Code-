//-----------------------------------Secant Method---------------------------//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Define function
double f(double x) {
    return x*x - 4*x - 10;   // Example function
}

int main() {
    double x0, x1, x2;
    double e;
    int iter = 0;

    // Input
    cout << "Enter initial guesses x0 and x1: ";
    cin >> x0 >> x1;

    cout << "Enter tolerable error: ";
    cin >> e;

    cout << "\n------------------------------------------------------\n";
    cout << "Iter\t x0\t\t x1\t\t x2\t\t Error\n";
    cout << "------------------------------------------------------\n";

    do {
        iter++;

        x2 = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
        double error = fabs((x2 - x1) / x2);

        cout << fixed << setprecision(6);
        cout << iter << "\t "
             << x0 << "\t "
             << x1 << "\t "
             << x2 << "\t "
             << error << endl;

        x0 = x1;
        x1 = x2;

    } while (fabs((x2 - x0) / x2) > e);

    cout << "------------------------------------------------------\n";
    cout << "Required root = " << x2 << endl;
    cout << "Total iterations = " << iter << endl;

    return 0;
}
