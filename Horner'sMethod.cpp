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

