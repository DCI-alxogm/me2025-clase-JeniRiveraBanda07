#include <stdio.h>
#include <math.h>
double factorial(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; i++) fact *= i;
    return fact;
}
double taylor_exp(double xi, double x_next, int n_terms) {
    double result = 0.0;
    double h = x_next - xi;
    for (int k = 0; k <= n_terms; k++) {
        result += exp(xi) * pow(h, k) / factorial(k);
    }
    return result;
}
double taylor_sin(double xi, double x_next, int n_terms) {
    double result = 0.0;
    double h = x_next - xi;
    for (int k = 0; k <= n_terms; k++) {
        double deriv;
        switch(k % 4) {
            case 0: deriv = sin(xi); break;
            case 1: deriv = cos(xi); break;
            case 2: deriv = -sin(xi); break;
            case 3: deriv = -cos(xi); break;
        }
        result += deriv * pow(h, k) / factorial(k);
    }
    return result;
}
double taylor_cos(double xi, double x_next, int n_terms) {
    double result = 0.0;
    double h = x_next - xi;
    for (int k = 0; k <= n_terms; k++) {
        double deriv;
        switch(k % 4) {
            case 0: deriv = cos(xi); break;
            case 1: deriv = -sin(xi); break;
            case 2: deriv = -cos(xi); break;
            case 3: deriv = sin(xi); break;
        }
        result += deriv * pow(h, k) / factorial(k);
    }
    return result;
}
double taylor_ln1p(double x, int n_terms) {
    double result = 0.0;
    for (int k = 1; k <= n_terms; k++) {
        result += pow(-1, k+1) * pow(x, k) / k;
    }
    return result;
}
double taylor_arctan(double x, int n_terms) {
    double result = 0.0;
    for (int k = 0; k < n_terms; k++) {
        result += pow(-1, k) * pow(x, 2*k+1) / (2*k+1);
    }
    return result;
}

double residuo_exp(double xi, double x_next, int n) {
    double h = x_next - xi;
    double max_val = exp(fmax(xi, x_next));
    return max_val * pow(h, n+1) / factorial(n+1);
}

double residuo_sin(double xi, double x_next, int n) {
    double h = x_next - xi;
    return pow(fabs(h), n+1) / factorial(n+1);
}

double residuo_cos(double xi, double x_next, int n) {
    double h = x_next - xi;
    return pow(fabs(h), n+1) / factorial(n+1);
}

double residuo_ln1p(double x, int n) {
    return pow(fabs(x), n+1) / ((n+1) * (1+fabs(x)));
}

double residuo_arctan(double x, int n) {
    return pow(fabs(x), 2*n+1) / (2*n+1);
}

int main() {
    int opcion, n = 0;
    double xi, x_next, approx, real_val, error, Rn, error_lim;

    printf("Serie de Taylor\n");
    printf("Elige la funcion:\n");
    printf("1) e^x\n2) sin(x)\n3) cos(x)\n4) ln(1+x)\n5) arctan(x)\n");
    scanf("%d", &opcion);

    printf("Ingresa error limite: ");
    scanf("%lf", &error_lim);

    if (opcion <= 3) {
        printf("Ingresa xi: ");
        scanf("%lf", &xi);

        printf("Ingresa x_{i+1}: ");
        scanf("%lf", &x_next);

        if (opcion == 1) real_val = exp(x_next);
        if (opcion == 2) real_val = sin(x_next);
        if (opcion == 3) real_val = cos(x_next);

        printf("\n n | Aproximacion       | Error       | Residuo\n");
        printf("-------------------------------------------------------------\n");

        while (1) {
            if (opcion == 1) {
                approx = taylor_exp(xi, x_next, n);
                Rn = residuo_exp(xi, x_next, n);
            }
            if (opcion == 2) {
                approx = taylor_sin(xi, x_next, n);
                Rn = residuo_sin(xi, x_next, n);
            }
            if (opcion == 3) {
                approx = taylor_cos(xi, x_next, n);
                Rn = residuo_cos(xi, x_next, n);
            }
            error = real_val - approx;

            printf("%2d | % .12f | % .12f | %.12f\n", n, approx, error, Rn);

            if (fabs(error) < error_lim) {
                printf("\n*** Se alcanzo el error limite en n = %d ***\n", n);
                break;
            }
            n++;
        }

    } else if (opcion == 4) {
        printf("Ingresa x (|x|<1): ");
        scanf("%lf", &x_next);

        real_val = log(1+x_next);

        printf("\n n | Aproximacion       | Error       | Residuo\n");
        printf("-------------------------------------------------------------\n");

        while (1) {
            approx = taylor_ln1p(x_next, n);
            error = real_val - approx;
            Rn = residuo_ln1p(x_next, n);

            printf("%2d | % .12f | % .12f | %.12f\n", n, approx, error, Rn);

            if (fabs(error) < error_lim) {
                printf("\n*** Se alcanzo el error limite en n = %d ***\n", n);
                break;
            }
            n++;
        }

    } else if (opcion == 5) {
        printf("Ingresa x (|x|<=1): ");
        scanf("%lf", &x_next);

        real_val = atan(x_next);

        printf("\n n | Aproximacion       | Error       | Residuo\n");
        printf("-------------------------------------------------------------\n");

        while (1) {
            approx = taylor_arctan(x_next, n);
            error = real_val - approx;
            Rn = residuo_arctan(x_next, n);

            printf("%2d | % .12f | % .12f | %.12f\n", n, approx, error, Rn);

            if (fabs(error) < error_lim) {
                printf("\n*** Se alcanzo el error limite en n = %d ***\n", n);
                break;
            }
            n++;
        }
    }

    return 0;
}
