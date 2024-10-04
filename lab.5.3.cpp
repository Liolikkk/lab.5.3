#include <iostream>
#include <cmath>
using namespace std;

double t(const double x); 
int main() {
    double gp, gk, z;
    int n;

    cout << "gp = "; cin >> gp;
    cout << "gk = "; cin >> gk;
    cout << "n = "; cin >> n;

    double dg = (gk - gp) / n;
    double g = gp; 

    while (g <= gk) {
        z = t(pow(g, 2)) + 2 * t(2 * g + 1) + sqrt(t(1));
        cout << "g: " << g << "   z: " << z << endl;
        g += dg;
    }

    return 0;
}

// функція t(x)
double t(const double x) {
    // коли |x| >= 1
    if (abs(x) >= 1) {
        return (cos(x) + 1) / (exp(x) + pow(sin(x), 2));
    }
    // коли |x| < 1
    else {
        double S = 0;
        for (int j = 0; j <= 5; j++) {
            double term = pow(-1, j) * pow(x, 2 * j + 1) / tgamma(2 * j + 2); // Taylor series term
            S += term;
        }
        return S;
    }
}
