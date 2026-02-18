//----------------------------Basic Horner's Method-----------------------------------//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double x;

    cout << "Enter degree of polynomial: ";
    cin >> n;

    vector<double> a(n + 1);

    cout << "Enter coefficients (from highest degree to constant term):\n";
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    cout << "Enter value of x: ";
    cin >> x;

    // Horner's Method
    double result = a[0];
    for (int i = 1; i <= n; i++) {
        result = result * x + a[i];
    }

    cout << "Polynomial value = " << result << endl;

    return 0;
}

///Online Ques
//An engineer is working on an underground water pipe system for a chemical plant, where the pressure at a certain point in the pipe depends on the depth of the water, denoted by h (in meters).
//Through modeling and experiments, the pressure is described by the equation $f(h) = 2h^3 - 7h^2 + 4h + 1$, where $f(h)$ represents the net gauge pressure in kilopascals (kPa).
//To keep the pressure sensor safe, the engineer needs to find the depth h at which the pressure becomes two.
//Write a C/C++ program to approximate the depth using Newton Raphson Method. Consider the stopping criteria of $E_a < 0.000001$, where $E_a$ is the absolute relative error of two successive
//iteration roots and initial guess using the formula of the largest possible root.
//For a polynomial equation, $a_nx^n + a_{n-1}x^{n-1} + a_{n-2}x^{n-2} + \dots + a_0 = 0$, the formula will be:$$x_1 = -\frac{a_{n-1}}{a_n}$$
//Your output should match the format of sample output.Evaluate the original function with Horner’s Method
//Sample Output:Initial estimation: 3.5

#include <bits/stdc++.h>
using namespace std;

// Horner's method
double horner(double h, vector<double> coeffs) {
    double result = coeffs[0];
    for (int i = 1; i < coeffs.size(); i++) {
        result = result * h + coeffs[i];
    }
    return result;
}

// Derivative f'(h) = 6h^2 - 14h + 4
double f_derivative(double h) {
    return 6*h*h - 14*h + 4;
}

int main() {
    double h0, h1;
    double Ea = 1e-6;
    double rel_error;
    int iteration = 0;

    // Polynomial: 2h^3 - 7h^2 + 4h - 1
    vector<double> coeffs = {2, -7, 4, -1};

    cout << "Enter initial estimation: ";
    cin >> h0;

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "Iter || h0 || h1 || f(h0) || f'(h0) || f(h1) || Rel.Error\n";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    do {
        double f0 = horner(h0, coeffs);
        double f0_der = f_derivative(h0);

        h1 = h0 - (f0 / f0_der);
        double f1 = horner(h1, coeffs);

        rel_error = fabs((h1 - h0) / h1);

        iteration++;
        cout << iteration << " || "
             << fixed << setprecision(6)
             << h0 << " || "
             << h1 << " || "
             << f0 << " || "
             << f0_der << " || "
             << f1 << " || "
             << rel_error << endl;

        h0 = h1;

    } while (rel_error > Ea);

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "Approximate root h = " << fixed << setprecision(6) << h1 << endl;

    return 0;
}


