#include <stdio.h>
#include <math.h>
#pragma warning (disable: 4996)

// Funkcja f(x) = sin(x) - 0.5x
double funkcja_f(double x) {
    return sin(x) - 0.5 * x;
}

// Pochodna funkcji f(x) = sin(x) - 0.5x
double pochodna_f(double x) {
    return cos(x) - 0.5;
}

// Funkcja g(x) = tan(x) - 2x
double funkcja_g(double x) {
    return tan(x) - 2 * x;
}

// Pochodna funkcji g(x) = tan(x) - 2x
double pochodna_g(double x) {
    return 1 / (cos(x) * cos(x)) - 2;
}

// Funkcja Newtona
int newton(double* x, int n, double eps, double (*f1)(double), double (*f2)(double)) {
    double x1;
    int i = 0;

    do {
        x1 = -(*f1)(*x) / (*f2)(*x);
        *x += x1;

        if (fabs(x1) < eps)
            return 0;
    } while (i++ < n);

    return 1;
}

int main() {
    double x0, eps;
    int n;

    // Testowanie dla f(x) = sin(x) - 0.5x
    printf("Podaj x0, n, eps dla funkcji f(x) = sin(x) - 0.5x: ");
    scanf("%lf %d %lf", &x0, &n, &eps);
    int wynik_f = newton(&x0, n, eps, funkcja_f, pochodna_f);
    printf("Dla f(x) = sin(x) - 0.5x: x = %.4lf\n", x0);

    // Testowanie dla g(x) = tan(x) - 2x
    printf("Podaj x0, n, eps dla funkcji g(x) = tan(x) - 2x: ");
    scanf("%lf %d %lf", &x0, &n, &eps);
    int wynik_g = newton(&x0, n, eps, funkcja_g, pochodna_g);
    printf("Dla g(x) = tan(x) - 2x: x = %.4lf\n", x0);

    return 0;
}
